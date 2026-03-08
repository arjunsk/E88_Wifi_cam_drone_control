Dump the hex

```
brew install avrdude

-- dump flash memory + bootloader
avrdude -c arduino -p m168 -P /dev/cu.usbserial-110 -b 19200 -U flash:r:dump.hex:i

-- check lock bit
avrdude -c arduino -p m168 -P /dev/cu.usbserial-110 -b 19200 -U lock:r:lock.bin:h
```


Covert to bin

```
brew tap osx-cross/avr

brew install avr-gcc

➜  Desktop avr-objdump --version
GNU objdump (GNU Binutils) 2.45.1
Copyright (C) 2025 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) any later version.
This program has absolutely no warranty.
➜  Desktop


avr-objcopy -I ihex dump.hex -O binary dump.bin

avr-objdump -D -b binary -m avr5 dump.bin > firmware.asm

```


Reading it as Pseduo 

```
brew install ghidra

cd /opt/homebrew/Cellar/ghidra/12.0.4/libexec
./ghidraRun

::::Use this a JDK path if asked:::::
/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home


Open the bin file and Use this as the language
> AVR8  default  16  little  gcc


```

Export the whole C Code

> The script manager didn't work. So created a new script.

1. Window → Script Manager
2. The file
3. ExportAllDecompilerC.java
4. Click the green Run button.

```
// ExportAllDecompilerC.java
// Exports pseudo-C for all functions in the current program.

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ExportAllDecompilerC extends GhidraScript {

    @Override
    public void run() throws Exception {
        if (currentProgram == null) {
            println("No program is open.");
            return;
        }

        File outFile = askFile("Choose output .c file", "Save");
        PrintWriter out = new PrintWriter(new FileWriter(outFile));

        DecompInterface ifc = new DecompInterface();
        DecompileOptions options = new DecompileOptions();
        ifc.setOptions(options);
        ifc.toggleCCode(true);
        ifc.toggleSyntaxTree(false);
        ifc.setSimplificationStyle("decompile");

        if (!ifc.openProgram(currentProgram)) {
            println("Failed to open program in decompiler.");
            out.close();
            return;
        }

        FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);

        int count = 0;
        for (Function f : funcs) {
            monitor.setMessage("Decompiling " + f.getName());
            if (monitor.isCancelled()) {
                break;
            }

            DecompileResults res = ifc.decompileFunction(f, 60, monitor);

            out.println("/* ========================================================= */");
            out.println("/* Function: " + f.getName() + " @ " + f.getEntryPoint() + " */");
            out.println("/* ========================================================= */");

            if (res != null && res.decompileCompleted()) {
                out.println(res.getDecompiledFunction().getC());
            } else {
                out.println("/* Decompilation failed for " + f.getName() + " */");
            }

            out.println();
            out.println();
            count++;
        }

        out.close();
        ifc.dispose();

        println("Exported " + count + " functions to: " + outFile.getAbsolutePath());
    }
}
```