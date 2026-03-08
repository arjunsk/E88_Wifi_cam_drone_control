/* ========================================================= */
/* Function: Reset @ code:0000 */
/* ========================================================= */

void Reset(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: INT1 @ code:0002 */
/* ========================================================= */

void INT1(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: TIMER2_OVF @ code:0004 */
/* ========================================================= */

void TIMER2_OVF(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: TIMER1_COMPA @ code:0006 */
/* ========================================================= */

void TIMER1_COMPA(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: TIMER1_OVF @ code:0008 */
/* ========================================================= */

void TIMER1_OVF(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: SPI_STC @ code:000a */
/* ========================================================= */

void SPI_STC(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: USART_UDRE @ code:000c */
/* ========================================================= */

void USART_UDRE(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: ADC @ code:000e */
/* ========================================================= */

void ADC(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: ANA_COMP @ code:0010 */
/* ========================================================= */

void ANA_COMP(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: SPM_RDY @ code:0012 */
/* ========================================================= */

void SPM_RDY(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: FUN_code_0062 @ code:0062 */
/* ========================================================= */

void FUN_code_0062(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: Reset @ code:008a */
/* ========================================================= */

void Reset(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  R1 = 0;
  SREG = 0;
  R17 = '\x01';
  X = &DAT_mem_0100;
  Z = s_test_pass_codebyte_0aa8;
  while (pcVar1 = X, (byte)X != 0x26 || X._1_1_ != (char)(R17 + ((byte)X < 0x26))) {
    R0 = *Z;
    Z = Z + 1;
    X = X + 1;
    *pcVar1 = R0;
  }
  R17 = '\x01';
  X = &DAT_mem_0126;
  while (puVar2 = X, (byte)X != 0xdb || X._1_1_ != (char)(R17 + ((byte)X < 0xdb))) {
    X = X + 1;
    *puVar2 = R1;
  }
  R17 = 0;
  Y = &DAT_mem_00c4;
  while ((byte)Y != 0xc2 || (bool)Y._1_1_ != (byte)Y < 0xc2) {
    Y = Y + -2;
    Z = Y;
    DAT_mem_04fe = 0x83;
    FUN_code_054e();
  }
  DAT_mem_04fe = 0x88;
  FUN_code_0479();
  FUN_code_0552();
  return;
}




/* ========================================================= */
/* Function: FUN_code_008c @ code:008c */
/* ========================================================= */

char FUN_code_008c(void)

{
  R1 = 0;
  while (FUN_code_0375(1,0xb9), R24 != '\0' || R25 != '\0') {
    FUN_code_03a9(1,0xb9);
    FUN_code_0139(0,0,0,5);
    FUN_code_04f0();
  }
  R24 = 0;
  R25 = R25;
  return R25;
}




/* ========================================================= */
/* Function: FUN_code_00b0 @ code:00b0 */
/* ========================================================= */

/* WARNING: Restarted to delay deadcode elimination for space: mem */

void FUN_code_00b0(void)

{
  R1 = 0;
  FUN_code_02ee(1,0xb9,0,0,0x25,0x80);
  R25R24 = 2;
  while( true ) {
    DAT_mem_0127 = R25R24._1_1_;
    DAT_mem_0126 = (byte)R25R24;
    if (((byte)R25R24 < 0x14) <= R25R24._1_1_) break;
    FUN_code_01cd();
    R25R24 = CONCAT11(DAT_mem_0127,DAT_mem_0126);
    R25R24 = R25R24 + 1;
  }
  R25R24 = 2;
  while( true ) {
    DAT_mem_0127 = R25R24._1_1_;
    DAT_mem_0126 = (byte)R25R24;
    if (((byte)R25R24 < 0x14) <= R25R24._1_1_) break;
    FUN_code_020c();
    FUN_code_0139(0,0,0,10);
    R25R24 = CONCAT11(DAT_mem_0127,DAT_mem_0126);
    R25R24 = R25R24 + 1;
  }
  FUN_code_04f0(1,0xb9,1,0x10);
  R25R24 = 0x1b9;
  return;
}




/* ========================================================= */
/* Function: FUN_code_00f1 @ code:00f1 */
/* ========================================================= */

void FUN_code_00f1(void)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  uVar9 = Xhi;
  uVar8 = Xlo;
  uVar5 = R25R24;
  uVar4 = R18;
  uVar3 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  R25R24 = CONCAT11(DAT_mem_012d,DAT_mem_012c);
  uVar6 = R25R24;
  R25R24 = R25R24 + 1;
  uVar7 = R25R24;
  bVar1 = DAT_mem_012e + (0xfffe < uVar6);
  Xhi = DAT_mem_012f + CARRY1(DAT_mem_012e,0xfffe < uVar6);
  R18 = DAT_mem_0130 + 3;
  Xlo = bVar1;
  if (0x7c < R18) {
    R18 = DAT_mem_0130 + 0x86;
    R25R24 = uVar6 + 2;
    Xlo = bVar1 + (0xfffe < uVar7);
    Xhi = Xhi + CARRY1(bVar1,0xfffe < uVar7);
  }
  DAT_mem_0130 = R18;
  DAT_mem_012c = (undefined1)R25R24;
  DAT_mem_012d = R25R24._1_1_;
  DAT_mem_012e = Xlo;
  DAT_mem_012f = Xhi;
  R25R24 = CONCAT11(DAT_mem_0129,DAT_mem_0128);
  uVar6 = R25R24;
  R25R24 = R25R24 + 1;
  bVar2 = CARRY1(DAT_mem_012a,0xfffe < uVar6);
  DAT_mem_0128 = (undefined1)R25R24;
  DAT_mem_0129 = R25R24._1_1_;
  DAT_mem_012a = DAT_mem_012a + (0xfffe < uVar6);
  DAT_mem_012b = DAT_mem_012b + bVar2;
  Xhi = uVar9;
  Xlo = uVar8;
  R25R24 = uVar5;
  R18 = uVar4;
  SREG = R0;
  R0 = uVar3;
  R1 = 0;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0139 @ code:0139 */
/* ========================================================= */

void FUN_code_0139(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  char in_Cflg;
  bool bVar7;
  bool bVar8;
  char in_Zflg;
  char in_Nflg;
  bool bVar9;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  bool bVar10;
  char in_Tflg;
  bool bVar11;
  char in_Iflg;
  bool bVar12;
  
  R1 = 0;
  R19R18 = R23R22;
  R21R20 = R25R24;
  bVar10 = in_Hflg == '\x01';
  bVar11 = in_Tflg == '\x01';
  bVar12 = in_Iflg == '\x01';
  R23R22._1_1_ = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
                 (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | bVar10 << 5 | bVar11 << 6 |
                 bVar12 << 7;
  R25R24 = CONCAT11(DAT_mem_0129,DAT_mem_0128);
  uVar6 = R25R24;
  Xlo = DAT_mem_012a;
  bVar2 = ICR1L;
  bVar1 = PORTC;
  if (((bVar1 & 1) != 0) && (bVar2 != 0xff)) {
    R25R24 = R25R24 + 1;
    Xlo = DAT_mem_012a + (0xfffe < uVar6);
  }
  SREG = R23R22._1_1_;
  bVar1 = (byte)R25R24;
  Xhi = Xlo;
  R23R22._0_1_ = '\x02';
  Xlo = R25R24._1_1_;
  R25R24._0_1_ = bVar2;
  R25R24._1_1_ = bVar1;
  do {
    bVar2 = (byte)R25R24 * '\x02';
    R23R22._1_1_ = R25R24._1_1_ * '\x02' + CARRY1((byte)R25R24,(byte)R25R24);
    bVar7 = CARRY1(R25R24._1_1_,R25R24._1_1_) ||
            CARRY1(R25R24._1_1_ * '\x02',CARRY1((byte)R25R24,(byte)R25R24));
    bVar1 = Xlo * '\x02' + bVar7;
    Xhi = Xhi * '\x02' + (CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar7));
    R23R22._0_1_ = (byte)R23R22 + -1;
    Xlo = bVar1;
    R25R24._0_1_ = bVar2;
    R25R24._1_1_ = R23R22._1_1_;
  } while ((byte)R23R22 != '\0');
  while( true ) {
    R23R22._0_1_ = bVar2;
    bVar7 = false;
    bVar1 = 0;
    bVar9 = R21R20 < 0;
    bVar3 = (((char)R19R18 == '\0' && R19R18._1_1_ == 0) && (byte)R21R20 == 0) &&
            R21R20._1_1_ == '\0';
    bVar4 = bVar9;
    if ((((char)R19R18 == '\0' && R19R18._1_1_ == 0) && (byte)R21R20 == 0) && R21R20._1_1_ == '\0')
    break;
    do {
      bVar10 = bVar10 == true;
      bVar11 = bVar11 == true;
      bVar12 = bVar12 == true;
      Zhi = bVar1 | bVar3 << 1 | bVar9 << 2 | bVar7 << 3 | bVar4 << 4 | bVar10 << 5 | bVar11 << 6 |
            bVar12 << 7;
      R25R24 = CONCAT11(DAT_mem_0129,DAT_mem_0128);
      uVar6 = R25R24;
      Xlo = DAT_mem_012a;
      bVar2 = ICR1L;
      bVar1 = PORTC;
      if (((bVar1 & 1) != 0) && (bVar2 != 0xff)) {
        R25R24 = R25R24 + 1;
        Xlo = DAT_mem_012a + (0xfffe < uVar6);
      }
      SREG = Zhi;
      bVar1 = (byte)R25R24;
      Xhi = Xlo;
      Zlo = '\x02';
      Xlo = R25R24._1_1_;
      R25R24._0_1_ = bVar2;
      R25R24._1_1_ = bVar1;
      do {
        bVar5 = (byte)R25R24 * '\x02';
        bVar2 = R25R24._1_1_ * '\x02' + CARRY1((byte)R25R24,(byte)R25R24);
        bVar7 = CARRY1(R25R24._1_1_,R25R24._1_1_) ||
                CARRY1(R25R24._1_1_ * '\x02',CARRY1((byte)R25R24,(byte)R25R24));
        bVar1 = Xlo * '\x02' + bVar7;
        Xhi = Xhi * '\x02' + (CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar7));
        Zlo = Zlo + -1;
        Xlo = bVar1;
        R25R24._0_1_ = bVar5;
        R25R24._1_1_ = bVar2;
      } while (Zlo != '\0');
      bVar2 = bVar2 - (R23R22._1_1_ + (bVar5 < (byte)R23R22));
      R25R24._0_1_ = (bVar5 - (byte)R23R22) + 0x18;
      bVar8 = (byte)(bVar5 - (byte)R23R22) < 0xe8;
      R25R24._1_1_ = bVar2 - (bVar8 + '\x03');
      bVar7 = SBORROW1(bVar2,'\x03') != SBORROW1(bVar2 - 3,bVar8);
      bVar9 = (char)R25R24._1_1_ < '\0';
      bVar4 = bVar9 != bVar7;
      bVar3 = (byte)R25R24 == 0 && R25R24._1_1_ == 0;
      bVar1 = 1;
    } while (bVar2 < 3 || (byte)(bVar2 - 3) < bVar8);
    bVar7 = R19R18._1_1_ < ((char)R19R18 == '\0');
    R19R18 = CONCAT11(R19R18._1_1_ - ((char)R19R18 == '\0'),(char)R19R18 + -1);
    R21R20 = CONCAT11(R21R20._1_1_ - ((byte)R21R20 < bVar7),(byte)R21R20 - bVar7);
    R23R22._1_1_ = R23R22._1_1_ - (((byte)R23R22 < 0x18) + -4);
    bVar2 = (byte)R23R22 - 0x18;
  }
  return;
}




/* ========================================================= */
/* Function: FUN_code_0192 @ code:0192 */
/* ========================================================= */

void FUN_code_0192(void)

{
  R1 = 0;
  R24 = TCNT2;
  R24 = R24 | 2;
  TCNT2 = R24;
  R24 = TCNT2;
  R24 = R24 | 1;
  TCNT2 = R24;
  R24 = TCCR2;
  R24 = R24 | 2;
  TCCR2 = R24;
  R24 = TCCR2;
  R24 = R24 | 1;
  TCCR2 = R24;
  R24 = DAT_mem_006e;
  R24 = R24 | 1;
  DAT_mem_006e = R24;
  ICR3H = 0;
  R24 = ICR3H;
  R24 = R24 | 2;
  ICR3H = R24;
  R24 = ICR3H;
  R24 = R24 | 1;
  ICR3H = R24;
  R24 = ICR3L;
  R24 = R24 | 1;
  ICR3L = R24;
  R24 = DAT_mem_00b1;
  R24 = R24 | 4;
  DAT_mem_00b1 = R24;
  R24 = DAT_mem_00b0;
  R24 = R24 | 1;
  DAT_mem_00b0 = R24;
  Z = 0x7a;
  R24 = TCCR1C;
  R24 = R24 | 4;
  TCCR1C = R24;
  R24 = TCCR1C;
  R24 = R24 | 2;
  TCCR1C = R24;
  R24 = TCCR1C;
  R24 = R24 | 1;
  TCCR1C = R24;
  R24 = TCCR1C;
  R24 = R24 | 0x80;
  TCCR1C = R24;
  DAT_mem_00c1 = 0;
  return;
}




/* ========================================================= */
/* Function: FUN_code_01cd @ code:01cd */
/* ========================================================= */

void FUN_code_01cd(undefined2 param_1,undefined2 R25R24,undefined1 param_3,byte R22)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  bool bVar4;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  uVar2 = Y;
  bVar1 = (byte)R25R24;
  R1 = 0;
  R25R24._1_1_ = -(((byte)R25R24 < 0x66) + -1);
  R25R24 = (byte *)CONCAT11(R25R24._1_1_,(byte)R25R24 + 0x9a);
  R19 = *R25R24;
  R21R20 = (byte *)CONCAT11(-((bVar1 < 0x7a) + -1),bVar1 + 0x86);
  Z = R21R20;
  R25R24._0_1_ = *R21R20;
  if ((byte)R25R24 != 0) {
    bVar1 = (byte)R25R24 * '\x02';
    bVar4 = CARRY1((byte)R25R24,(byte)R25R24);
    Z = (byte *)CONCAT11(bVar4 - ((bVar1 < 0x98) + -1),bVar1 + 0x68);
    X = *(byte **)Z;
    Z = (byte *)CONCAT11(bVar4 - ((bVar1 < 0x8e) + -1),bVar1 + 0x72);
    puVar3 = (undefined2 *)Z;
    Z = (byte *)((int)Z + 1);
    if (R22 == 0) {
      R18 = (bVar4 != true || (byte)(bVar4 + 1U) < (bVar1 < 0x8e)) | 2U | (in_Hflg == '\x01') << 5 |
            (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
      R25R24._0_1_ = *X;
      R25R24._1_1_ = ~R19;
      R25R24._0_1_ = (byte)R25R24 & R25R24._1_1_;
      Y = (byte *)*puVar3;
      *X = (byte)R25R24;
      R25R24._0_1_ = *Y;
      R25R24._0_1_ = (byte)R25R24 & R25R24._1_1_;
    }
    else {
      if (R22 != 2) {
        R25R24._1_1_ = R22 < 2 | (R22 == 2) << 1 | ((char)(R22 - 2) < '\0') << 2 |
                       SBORROW1(R22,'\x02') << 3 | ((char)R22 < '\x02') << 4 |
                       (in_Hflg == '\x01') << 5 | (in_Tflg == '\x01') << 6 |
                       (in_Iflg == '\x01') << 7;
        R25R24._0_1_ = *X;
        R25R24._0_1_ = (byte)R25R24 | R19;
        *X = (byte)R25R24;
        SREG = R25R24._1_1_;
        return;
      }
      R18 = (in_Hflg == '\x01') << 5 | 2U | (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
      R25R24._0_1_ = *X;
      R25R24._1_1_ = ~R19;
      R25R24._0_1_ = (byte)R25R24 & R25R24._1_1_;
      Y = (byte *)*puVar3;
      *X = (byte)R25R24;
      R25R24._0_1_ = *Y;
      R25R24._0_1_ = (byte)R25R24 | R19;
    }
    *Y = (byte)R25R24;
    SREG = R18;
  }
  Y = (byte *)uVar2;
  return;
}




/* ========================================================= */
/* Function: FUN_code_020c @ code:020c */
/* ========================================================= */

void FUN_code_020c(undefined2 param_1,undefined2 R25R24,undefined1 param_3,char R22)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  undefined2 *puVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  bVar3 = (byte)R25R24;
  R1 = 0;
  R25R24 = (byte *)CONCAT11(-(((byte)R25R24 < 0x52) + -1),(byte)R25R24 + 0xae);
  R18 = *R25R24;
  R25R24 = (byte *)CONCAT11(-((bVar3 < 0x66) + -1),bVar3 + 0x9a);
  R25R24._1_1_ = *R25R24;
  R21R20 = (byte *)CONCAT11(-((bVar3 < 0x7a) + -1),bVar3 + 0x86);
  R19 = *R21R20;
  if (R19 == 0) {
    R1 = 0;
    R25R24._0_1_ = bVar3 + 0x9a;
    Z = R21R20;
    return;
  }
  if (R18 == 0) goto LAB_code_024b;
  if (R18 == 3) {
    R25R24._0_1_ = ICR3L;
    R25R24._0_1_ = (byte)R25R24 & 0x7f;
LAB_code_0238:
    ICR3L = (byte)R25R24;
  }
  else {
    if (R18 < 4) {
      if (R18 == 1) {
        R25R24._0_1_ = TCNT2;
        R25R24._0_1_ = (byte)R25R24 & 0x7f;
      }
      else {
        if (R18 != 2) goto LAB_code_024b;
        R25R24._0_1_ = TCNT2;
        R25R24._0_1_ = (byte)R25R24 & 0xdf;
      }
      TCNT2 = (byte)R25R24;
      goto LAB_code_024b;
    }
    if (R18 == 6) {
      R25R24._0_1_ = DAT_mem_00b0;
      R25R24._0_1_ = (byte)R25R24 & 0x7f;
    }
    else {
      if (R18 != 7) {
        if (R18 != 4) goto LAB_code_024b;
        R25R24._0_1_ = ICR3L;
        R25R24._0_1_ = (byte)R25R24 & 0xdf;
        goto LAB_code_0238;
      }
      R25R24._0_1_ = DAT_mem_00b0;
      R25R24._0_1_ = (byte)R25R24 & 0xdf;
    }
    DAT_mem_00b0 = (byte)R25R24;
  }
LAB_code_024b:
  bVar5 = CARRY1(R19,R19);
  cVar1 = R19 * '\x02' + 0x72;
  bVar6 = (byte)(R19 * '\x02') < 0x8e;
  cVar2 = bVar5 - (bVar6 + -1);
  bVar7 = SBORROW1(bVar5,-1) != SBORROW1(bVar5 + 1U,bVar6);
  Z = (byte *)CONCAT11(cVar2,cVar1);
  puVar4 = (undefined2 *)Z;
  Z = (byte *)((int)Z + 1);
  X = (byte *)*puVar4;
  R18 = (bVar5 != true || (byte)(bVar5 + 1U) < bVar6) | (cVar1 == '\0' && cVar2 == '\0') << 1 |
        (cVar2 < '\0') << 2 | bVar7 << 3 | (cVar2 < '\0' != bVar7) << 4 | (in_Hflg == '\x01') << 5 |
        (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  if (R22 == '\0') {
    R25R24._0_1_ = *X;
    R25R24._1_1_ = ~R25R24._1_1_;
    R25R24._0_1_ = (byte)R25R24 & R25R24._1_1_;
  }
  else {
    R25R24._0_1_ = *X;
    R25R24._0_1_ = (byte)R25R24 | R25R24._1_1_;
  }
  *X = (byte)R25R24;
  SREG = R18;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0260 @ code:0260 */
/* ========================================================= */

void FUN_code_0260(void)

{
  R1 = 0;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0261 @ code:0261 */
/* ========================================================= */

undefined1 FUN_code_0261(undefined1 R25,undefined1 R24)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  uVar6 = Z;
  uVar5 = R19;
  uVar4 = R18;
  uVar3 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  bVar1 = DAT_mem_00c0;
  if ((bVar1 & 4) == 0) {
    uVar2 = DAT_mem_00c6;
    R18 = DAT_mem_0171 + 1 & 0x3f;
    R19 = '\0';
    if (R18 != DAT_mem_0173 || (char)(DAT_mem_0174 + (R18 < DAT_mem_0173)) != '\0') {
      Z = (undefined1 *)CONCAT11(DAT_mem_0172 - ((DAT_mem_0171 < 0xcf) + -2),DAT_mem_0171 + 0x31);
      *Z = uVar2;
      DAT_mem_0172 = R19;
      DAT_mem_0171 = R18;
    }
  }
  else {
    uVar2 = DAT_mem_00c6;
  }
  Z = (undefined1 *)uVar6;
  R19 = uVar5;
  R18 = uVar4;
  SREG = R0;
  R0 = uVar3;
  R1 = 0;
  return R25;
}




/* ========================================================= */
/* Function: FUN_code_029c @ code:029c */
/* ========================================================= */

byte FUN_code_029c(void)

{
  byte *pbVar1;
  byte *pbVar2;
  
  R1 = 0;
  Z = (byte *)CONCAT11(DAT_mem_01c6 - ((DAT_mem_01c5 < 0xc0) + -1),DAT_mem_01c5 + 0x40);
  pbVar1 = Z;
  Z = Z + 1;
  pbVar2 = Z;
  R24 = *pbVar1;
  Z = pbVar1 + 2;
  R25 = *pbVar2;
  R18 = *Z;
  R19 = pbVar1[3];
  FUN_code_0503((R25 - ((R24 < 0xc0) + -1)) - (R19 + ((byte)(R24 + 0x40) < R18)),(R24 + 0x40) - R18,
                0,0x40);
  R24 = R24 | R25;
  if (R24 != 0) {
    FUN_code_0260();
  }
  return R25;
}




/* ========================================================= */
/* Function: FUN_code_02b3 @ code:02b3 */
/* ========================================================= */

void FUN_code_02b3(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  char in_Cflg;
  char in_Zflg;
  char in_Nflg;
  char in_Vflg;
  char in_Sflg;
  char in_Hflg;
  char in_Tflg;
  char in_Iflg;
  
  uVar4 = Z;
  uVar3 = R25R24;
  uVar2 = R18;
  uVar1 = R0;
  R0 = in_Cflg == '\x01' | (in_Zflg == '\x01') << 1 | (in_Nflg == '\x01') << 2 |
       (in_Vflg == '\x01') << 3 | (in_Sflg == '\x01') << 4 | (in_Hflg == '\x01') << 5 |
       (in_Tflg == '\x01') << 6 | (in_Iflg == '\x01') << 7;
  if (DAT_mem_01b5 == DAT_mem_01b7 &&
      DAT_mem_01b6 == (char)(DAT_mem_01b8 + (DAT_mem_01b5 < DAT_mem_01b7))) {
    R25R24._0_1_ = DAT_mem_00c1;
    R25R24._0_1_ = (byte)R25R24 & 0xdf;
    DAT_mem_00c1 = (byte)R25R24;
  }
  else {
    Z = (undefined1 *)CONCAT11(DAT_mem_01b8 - ((DAT_mem_01b7 < 0x8b) + -2),DAT_mem_01b7 + 0x75);
    R18 = *Z;
    R25R24._0_1_ = DAT_mem_01b7 + 1 & 0x3f;
    DAT_mem_01b8 = '\0';
    DAT_mem_01b7 = (byte)R25R24;
    DAT_mem_00c6 = R18;
  }
  Z = (undefined1 *)uVar4;
  R25R24 = uVar3;
  R18 = uVar2;
  SREG = R0;
  R0 = uVar1;
  R1 = 0;
  return;
}




/* ========================================================= */
/* Function: FUN_code_02ee @ code:02ee */
/* ========================================================= */

void FUN_code_02ee(void)

{
  byte bVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar7 = Y;
  uVar6 = R17R16;
  uVar5 = R15R14;
  uVar4 = R13;
  uVar3 = R11R10;
  R1 = '\0';
  Y = R25R24;
  R15R14 = R21R20;
  R17R16 = R23R22;
  R13 = (((byte)R21R20 != '\0' || R21R20._1_1_ != 0xe1) || (bool)(byte)R23R22 != R21R20._1_1_ < 0xe1
        ) || (bool)R23R22._1_1_ != (byte)R23R22 < (R21R20._1_1_ < 0xe1);
  R11R10 = 1;
  while( true ) {
    Z = *(byte **)(Y + 0x14);
    if ((bool)R13 == false) {
      *Z = R1;
    }
    else {
      R25R24 = R11R10;
      R0 = *(char *)(Y + 0x20);
      while( true ) {
        R0 = R0 + -1;
        if (R0 < '\0') break;
        R25R24 = (uint)(byte)((byte)R25R24 * '\x02');
      }
      *Z = (byte)R25R24;
    }
    FUN_code_0516();
    bVar1 = R19R18._1_1_ - ((byte)R19R18 == '\0');
    bVar2 = R19R18._1_1_ < ((byte)R19R18 == '\0');
    R21R20._1_1_ = (byte)(R21R20._1_1_ - ((byte)R21R20 < bVar2)) >> 1;
    R19R18._1_1_ = ((byte)R21R20 - bVar2) * -0x80 | bVar1 >> 1;
    R19R18._0_1_ = bVar1 * -0x80 | (byte)((byte)R19R18 - 1) >> 1;
    if ((R19R18._1_1_ < 0x10) || (R13 == '\0')) break;
    R13 = false;
  }
  **(byte **)(Y + 0x10) = R19R18._1_1_;
  **(byte **)(Y + 0x12) = (byte)R19R18;
  *(char *)(Y + 0x21) = R1;
  R21R20._0_1_ = **(byte **)(Y + 0x16);
  R19R18._0_1_ = 1;
  R19R18._1_1_ = '\0';
  R25R24._0_1_ = 1;
  R0 = *(char *)(Y + 0x1c);
  while (R0 = R0 + -1, -1 < R0) {
    R25R24._0_1_ = (byte)R25R24 * '\x02';
  }
  R21R20._0_1_ = (byte)R21R20 | (byte)R25R24;
  **(byte **)(Y + 0x16) = (byte)R21R20;
  R21R20._0_1_ = **(byte **)(Y + 0x16);
  R25R24._0_1_ = (byte)R19R18;
  R0 = *(char *)(Y + 0x1d);
  while (R0 = R0 + -1, -1 < R0) {
    R25R24._0_1_ = (byte)R25R24 * '\x02';
  }
  R21R20._0_1_ = (byte)R21R20 | (byte)R25R24;
  **(byte **)(Y + 0x16) = (byte)R21R20;
  R21R20._0_1_ = **(byte **)(Y + 0x16);
  R25R24._0_1_ = (byte)R19R18;
  R25R24._1_1_ = R19R18._1_1_;
  R0 = *(char *)(Y + 0x1e);
  while (R0 = R0 + -1, -1 < R0) {
    R25R24._1_1_ = R25R24._1_1_ * '\x02' + CARRY1((byte)R25R24,(byte)R25R24);
    R25R24._0_1_ = (byte)R25R24 * '\x02';
  }
  R21R20._0_1_ = (byte)R21R20 | (byte)R25R24;
  **(byte **)(Y + 0x16) = (byte)R21R20;
  Z = *(byte **)(Y + 0x16);
  R25R24._0_1_ = *Z;
  R0 = *(char *)(Y + 0x1f);
  while (R0 = R0 + -1, -1 < R0) {
    R19R18._1_1_ = R19R18._1_1_ * '\x02' + CARRY1((byte)R19R18,(byte)R19R18);
    R19R18._0_1_ = (byte)R19R18 * '\x02';
  }
  R19R18._0_1_ = ~(byte)R19R18;
  R19R18._0_1_ = (byte)R19R18 & (byte)R25R24;
  *Z = (byte)R19R18;
  Y = uVar7;
  R17R16 = uVar6;
  R15R14 = uVar5;
  R13 = uVar4;
  R11R10 = uVar3;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0375 @ code:0375 */
/* ========================================================= */

/* WARNING: Restarted to delay deadcode elimination for space: mem */

void FUN_code_0375(void)

{
  char cVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  R1 = 0;
  X = (byte *)(R25R24 + 0xc);
  pbVar3 = X;
  X = (byte *)(R25R24 + 0xd);
  Z._0_1_ = *pbVar3;
  Z._1_1_ = *X;
  X = (byte *)R25R24;
  Z = (byte *)CONCAT11(Z._1_1_ - (((byte)Z < 0xc0) + -1),(byte)Z + 0x40);
  pbVar3 = Z;
  Z = Z + 1;
  pbVar4 = Z;
  R25R24._0_1_ = *pbVar3;
  Z = pbVar3 + 2;
  R25R24._1_1_ = *pbVar4;
  R18 = *Z;
  R19 = pbVar3[3];
  cVar1 = ((byte)R25R24 + 0x40) - R18;
  cVar2 = (R25R24._1_1_ - (((byte)R25R24 < 0xc0) + -1)) -
          (R19 + ((byte)((byte)R25R24 + 0x40) < R18));
  FUN_code_0503(cVar2,cVar1,0,0x40);
  R25R24 = CONCAT11(cVar2,cVar1);
  return;
}




/* ========================================================= */
/* Function: FUN_code_03a9 @ code:03a9 */
/* ========================================================= */

void FUN_code_03a9(void)

{
  byte bVar1;
  byte *pbVar2;
  byte bVar3;
  
  R1 = 0;
  X = (byte *)(R25R24 + 0xc);
  pbVar2 = X;
  X = (byte *)(R25R24 + 0xd);
  Z._0_1_ = *pbVar2;
  bVar3 = (byte)Z;
  Z._1_1_ = *X;
  bVar1 = (byte)Z + 0x40;
  Z._1_1_ = Z._1_1_ - (((byte)Z < 0xc0) + -1);
  Z = (byte *)CONCAT11(Z._1_1_,bVar1);
  R19R18._0_1_ = *Z;
  R19R18._1_1_ = Z[1];
  Z._1_1_ = Z._1_1_ - (bVar1 < 0x40);
  Z = (byte *)CONCAT11(Z._1_1_,bVar3);
  X = (byte *)CONCAT11(Z._1_1_ - ((bVar3 < 0xbe) + -1),bVar3 + 0x42);
  pbVar2 = X;
  X = X + 1;
  R25R24._0_1_ = *pbVar2;
  R25R24._1_1_ = *X;
  if ((byte)R19R18 == (byte)R25R24 &&
      R19R18._1_1_ == (byte)(R25R24._1_1_ + ((byte)R19R18 < (byte)R25R24))) {
    R19R18 = 0xffff;
    X = pbVar2;
  }
  else {
    X = pbVar2 + 1;
    R25R24._0_1_ = *pbVar2;
    R25R24._1_1_ = *X;
    Z = (byte *)CONCAT11(Z._1_1_ + R25R24._1_1_ + CARRY1(bVar3,(byte)R25R24),bVar3 + (byte)R25R24);
    R19R18._0_1_ = *Z;
    R25R24._0_1_ = *pbVar2;
    R25R24._0_1_ = (byte)R25R24 + 1 & 0x3f;
    X = pbVar2 + 1;
    *X = 0;
    X = X + -1;
    *X = (byte)R25R24;
    R19R18 = (uint)(byte)R19R18;
  }
  R25R24 = R19R18;
  return;
}




/* ========================================================= */
/* Function: FUN_code_03e2 @ code:03e2 */
/* ========================================================= */

void FUN_code_03e2(void)

{
  byte bVar1;
  byte *pbVar2;
  undefined2 uVar3;
  byte bVar4;
  
  uVar3 = Y;
  R1 = 0;
  Y = R25R24;
  Z._0_1_ = *(byte *)(R25R24 + 0xe);
  bVar4 = (byte)Z;
  Z._1_1_ = *(char *)(R25R24 + 0xf);
  bVar1 = (byte)Z + 0x40;
  Z._1_1_ = Z._1_1_ - (((byte)Z < 0xc0) + -1);
  Z = (byte *)CONCAT11(Z._1_1_,bVar1);
  R18 = *Z;
  Z._1_1_ = Z._1_1_ - (bVar1 < 0x40);
  R18 = R18 + 1 & 0x3f;
  R19 = 0;
  X = (byte *)CONCAT11(Z._1_1_ - ((bVar4 < 0xbe) + -1),bVar4 + 0x42);
  pbVar2 = X;
  do {
    X = pbVar2 + 1;
    R25R24._0_1_ = *pbVar2;
    R25R24._1_1_ = *X;
  } while (R18 == (byte)R25R24 && (byte)(R25R24._1_1_ + (R18 < (byte)R25R24)) == '\0');
  Z._1_1_ = Z._1_1_ - ((bVar4 < 0xc0) + -1);
  Z = (byte *)CONCAT11(Z._1_1_,bVar4 + 0x40);
  R25R24._0_1_ = *Z;
  R25R24._1_1_ = Z[1];
  Z = (byte *)CONCAT11((Z._1_1_ - ((byte)(bVar4 + 0x40) < 0x40)) + R25R24._1_1_ +
                       CARRY1(bVar4,(byte)R25R24),bVar4 + (byte)R25R24);
  X = pbVar2;
  *Z = R22;
  Z._0_1_ = *(byte *)(Y + 0xe);
  Z._1_1_ = *(char *)(Y + 0xf);
  Z = (byte *)CONCAT11(Z._1_1_ - (((byte)Z < 0xc0) + -1),(byte)Z + 0x40);
  Z[1] = R19;
  *Z = R18;
  R18 = **(byte **)(Y + 0x16);
  R25R24._0_1_ = 1;
  R0 = *(char *)(Y + 0x1f);
  while (R0 = R0 + -1, -1 < R0) {
    R25R24._0_1_ = (byte)R25R24 * '\x02';
  }
  R18 = R18 | (byte)R25R24;
  **(byte **)(Y + 0x16) = R18;
  *(undefined1 *)(Y + 0x21) = 1;
  Z = *(byte **)(Y + 0x14);
  R25R24._0_1_ = *Z;
  R25R24._0_1_ = (byte)R25R24 | 0x40;
  *Z = (byte)R25R24;
  R25R24 = 1;
  Y = uVar3;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0478 @ code:0478 */
/* ========================================================= */

void FUN_code_0478(void)

{
  R1 = 0;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0479 @ code:0479 */
/* ========================================================= */

void FUN_code_0479(void)

{
  FUN_code_0192();
  FUN_code_0478();
  FUN_code_00b0();
  do {
    FUN_code_008c();
    FUN_code_029c();
  } while( true );
}




/* ========================================================= */
/* Function: FUN_code_04b4 @ code:04b4 */
/* ========================================================= */

void FUN_code_04b4(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar2 = R17R16;
  uVar1 = R15R14;
  R1 = 0;
  R17R16 = R25R24;
  X = (int)R25R24 + 1;
  Z = *(code **)*R25R24;
  (*Z)();
  R15R14 = R25R24;
  X = (int)R17R16 + 1;
  Z = *(code **)*R17R16;
  (*Z)();
  R19R18 = CONCAT11(R25R24._1_1_ + R15R14._1_1_ + CARRY1((byte)R25R24,(byte)R15R14),
                    (byte)R25R24 + (byte)R15R14);
  R25R24 = (undefined2 *)R19R18;
  R17R16 = (undefined2 *)uVar2;
  R15R14 = uVar1;
  return;
}




/* ========================================================= */
/* Function: FUN_code_04d4 @ code:04d4 */
/* ========================================================= */

void FUN_code_04d4(void)

{
  char *pcVar1;
  
  R1 = 0;
  if ((byte)R23R22 == 0 && R23R22._1_1_ == '\0') {
    R19R18 = 0;
  }
  else {
    X = R23R22;
    do {
      pcVar1 = X;
      X = X + 1;
      R0 = *pcVar1;
    } while (R0 != '\0');
    X._0_1_ = (byte)pcVar1;
    X._1_1_ = SUB21(pcVar1,1);
    X = (char *)CONCAT11(X._1_1_ - (R23R22._1_1_ + ((byte)X < (byte)R23R22)),(byte)X - (byte)R23R22)
    ;
    Z = *(code **)(*R25R24 + 2);
    (*Z)();
    R19R18 = R25R24;
  }
  R25R24 = (int *)R19R18;
  return;
}




/* ========================================================= */
/* Function: FUN_code_04f0 @ code:04f0 */
/* ========================================================= */

void FUN_code_04f0(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar2 = R17R16;
  uVar1 = R15R14;
  R1 = 0;
  R15R14 = R25R24;
  FUN_code_04d4();
  R17R16 = R25R24;
  FUN_code_04b4();
  R17R16 = CONCAT11(R17R16._1_1_ + R25R24._1_1_ + CARRY1((byte)R17R16,(byte)R25R24),
                    (byte)R17R16 + (byte)R25R24);
  R25R24 = R17R16;
  R17R16 = uVar2;
  R15R14 = uVar1;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0503 @ code:0503 */
/* ========================================================= */

undefined1 FUN_code_0503(void)

{
  R1 = 0;
  FUN_code_0511();
  if ((R23 & 0x80) != 0) {
    FUN_code_050d();
  }
  FUN_code_0538();
  FUN_code_0511();
  if (R0 < '\0') {
    R23 = ~R23;
    R22 = -R22;
    R23 = R23 - ((R22 != '\0') + -1);
  }
  return R25;
}




/* ========================================================= */
/* Function: FUN_code_050d @ code:050d */
/* ========================================================= */

void FUN_code_050d(undefined1 param_1,undefined1 param_2,byte R23,char R22)

{
  R1 = 0;
  R23 = ~R23;
  R22 = -R22;
  R23 = R23 - ((R22 != '\0') + -1);
  return;
}




/* ========================================================= */
/* Function: FUN_code_0511 @ code:0511 */
/* ========================================================= */

undefined2 FUN_code_0511(byte R25,char R24)

{
  bool in_Tflg;
  
  R1 = 0;
  if (in_Tflg) {
    R25 = ~R25;
    R24 = -R24;
    R25 = R25 - ((R24 != '\0') + -1);
    return CONCAT11(R24,R25);
  }
  return CONCAT11(R24,R25);
}




/* ========================================================= */
/* Function: FUN_code_0516 @ code:0516 */
/* ========================================================= */

void FUN_code_0516(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  
  R1 = '!';
  bVar6 = false;
  Zhi = 0;
  Xlo = 0;
  Xhi = 0;
  Zlo = 0;
  while( true ) {
    bVar2 = (byte)R23R22 * '\x02' + bVar6;
    bVar6 = CARRY1((byte)R23R22,(byte)R23R22) || CARRY1((byte)R23R22 * '\x02',bVar6);
    bVar3 = R23R22._1_1_ * '\x02' + bVar6;
    bVar6 = CARRY1(R23R22._1_1_,R23R22._1_1_) || CARRY1(R23R22._1_1_ * '\x02',bVar6);
    R23R22 = CONCAT11(bVar3,bVar2);
    bVar4 = (byte)R25R24 * '\x02' + bVar6;
    bVar6 = CARRY1((byte)R25R24,(byte)R25R24) || CARRY1((byte)R25R24 * '\x02',bVar6);
    bVar5 = R25R24._1_1_ * '\x02' + bVar6;
    bVar6 = CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar6);
    R25R24 = CONCAT11(bVar5,bVar4);
    R1 = R1 + -1;
    if (R1 == '\0') break;
    bVar2 = Xlo * '\x02' + bVar6;
    bVar6 = CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar6);
    bVar3 = Xhi * '\x02' + bVar6;
    bVar6 = CARRY1(Xhi,Xhi) || CARRY1(Xhi * '\x02',bVar6);
    bVar4 = Zlo * '\x02' + bVar6;
    bVar5 = Zhi * '\x02' + (CARRY1(Zlo,Zlo) || CARRY1(Zlo * '\x02',bVar6));
    bVar1 = (byte)(bVar5 - R21R20._1_1_) <
            (bVar4 < (byte)R21R20 ||
            (byte)(bVar4 - (byte)R21R20) <
            (bVar3 < R19R18._1_1_ || (byte)(bVar3 - R19R18._1_1_) < (bVar2 < (byte)R19R18)));
    bVar6 = bVar5 < R21R20._1_1_ || bVar1;
    Xlo = bVar2;
    Xhi = bVar3;
    Zlo = bVar4;
    Zhi = bVar5;
    if (bVar5 >= R21R20._1_1_ && !bVar1) {
      Xlo = bVar2 - (byte)R19R18;
      Xhi = bVar3 - (R19R18._1_1_ + (bVar2 < (byte)R19R18));
      bVar6 = bVar3 < R19R18._1_1_ || (byte)(bVar3 - R19R18._1_1_) < (bVar2 < (byte)R19R18);
      Zlo = bVar4 - ((byte)R21R20 + bVar6);
      bVar6 = bVar4 < (byte)R21R20 || (byte)(bVar4 - (byte)R21R20) < bVar6;
      Zhi = bVar5 - (R21R20._1_1_ + bVar6);
      bVar6 = bVar5 < R21R20._1_1_ || (byte)(bVar5 - R21R20._1_1_) < bVar6;
    }
  }
  R23R22._0_1_ = ~bVar2;
  R23R22._1_1_ = ~bVar3;
  R25R24._0_1_ = ~bVar4;
  R25R24._1_1_ = ~bVar5;
  R19R18 = R23R22;
  R21R20 = R25R24;
  R23R22._0_1_ = Xlo;
  R23R22._1_1_ = Xhi;
  R25R24._0_1_ = Zlo;
  R25R24._1_1_ = Zhi;
  return;
}




/* ========================================================= */
/* Function: FUN_code_0538 @ code:0538 */
/* ========================================================= */

void FUN_code_0538(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  
  R1 = 0;
  bVar4 = false;
  Xlo = 0;
  R21 = '\x11';
  Xhi = 0;
  while( true ) {
    bVar2 = (byte)R25R24 * '\x02' + bVar4;
    bVar4 = CARRY1((byte)R25R24,(byte)R25R24) || CARRY1((byte)R25R24 * '\x02',bVar4);
    bVar3 = R25R24._1_1_ * '\x02' + bVar4;
    bVar4 = CARRY1(R25R24._1_1_,R25R24._1_1_) || CARRY1(R25R24._1_1_ * '\x02',bVar4);
    R25R24 = CONCAT11(bVar3,bVar2);
    R21 = R21 + -1;
    if (R21 == '\0') break;
    bVar2 = Xlo * '\x02' + bVar4;
    bVar3 = Xhi * '\x02' + (CARRY1(Xlo,Xlo) || CARRY1(Xlo * '\x02',bVar4));
    bVar1 = (byte)(bVar3 - R23R22._1_1_) < (bVar2 < (byte)R23R22);
    bVar4 = bVar3 < R23R22._1_1_ || bVar1;
    Xlo = bVar2;
    Xhi = bVar3;
    if (bVar3 >= R23R22._1_1_ && !bVar1) {
      Xlo = bVar2 - (byte)R23R22;
      Xhi = bVar3 - (R23R22._1_1_ + (bVar2 < (byte)R23R22));
      bVar4 = bVar3 < R23R22._1_1_ || (byte)(bVar3 - R23R22._1_1_) < (bVar2 < (byte)R23R22);
    }
  }
  R25R24._0_1_ = ~bVar2;
  R25R24._1_1_ = ~bVar3;
  R23R22 = R25R24;
  R21 = 0;
  R25R24._0_1_ = Xlo;
  R25R24._1_1_ = Xhi;
  return;
}




/* ========================================================= */
/* Function: FUN_code_054e @ code:054e */
/* ========================================================= */

void FUN_code_054e(void)

{
  R1 = 0;
  Z = (undefined2 *)*Z;
                    /* WARNING: Could not recover jumptable at 0x0551. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)Z)();
  return;
}




/* ========================================================= */
/* Function: FUN_code_0552 @ code:0552 */
/* ========================================================= */

void FUN_code_0552(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}




/* ========================================================= */
/* Function: FUN_code_1c76 @ code:1c76 */
/* ========================================================= */

void FUN_code_1c76(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  
  uVar7 = R17R16;
  uVar6 = R15R14;
  R1 = 0;
  R15R14 = 0;
  R17R16 = 0;
  while (bVar1 = DAT_mem_00c0, (bVar1 & 0x80) == 0) {
    while( true ) {
      bVar1 = (byte)R15R14 + 1;
      bVar2 = R15R14._1_1_ + (0xfe < (byte)R15R14);
      bVar5 = CARRY1(R15R14._1_1_,0xfe < (byte)R15R14);
      R15R14 = CONCAT11(bVar2,bVar1);
      bVar3 = (byte)R17R16 + bVar5;
      bVar4 = R17R16._1_1_ + CARRY1((byte)R17R16,bVar5);
      R17R16 = CONCAT11(bVar4,bVar3);
      if (bVar4 < (bVar3 < 0xf ||
                  (byte)(bVar3 - 0xf) < (bVar2 < 0x42 || (byte)(bVar2 + 0xbe) < (bVar1 < 0x41))))
      break;
      Z = (code *)CONCAT11(DAT_mem_0105,DAT_mem_0104);
      (*Z)();
      bVar1 = DAT_mem_00c0;
      if ((bVar1 & 0x80) != 0) goto LAB_code_1c98;
    }
  }
LAB_code_1c98:
  R24 = DAT_mem_00c6;
  R17R16 = uVar7;
  R15R14 = uVar6;
  return;
}




/* ========================================================= */
/* Function: FUN_code_1cca @ code:1cca */
/* ========================================================= */

void FUN_code_1cca(undefined1 param_1,char R24)

{
  byte bVar1;
  undefined1 uVar2;
  
  uVar2 = R24;
  R1 = 0;
  FUN_code_1c76();
  if (R24 == ' ') {
    do {
      bVar1 = DAT_mem_00c0;
    } while ((bVar1 & 0x20) == 0);
    DAT_mem_00c6 = 0x14;
    do {
      bVar1 = DAT_mem_00c0;
    } while ((bVar1 & 0x20) == 0);
    DAT_mem_00c6 = uVar2;
    do {
      bVar1 = DAT_mem_00c0;
    } while ((bVar1 & 0x20) == 0);
    R24 = 0x10;
    DAT_mem_00c6 = 0x10;
    return;
  }
  DAT_mem_0103 = DAT_mem_0103 + '\x01';
  R24 = DAT_mem_0103;
  if (DAT_mem_0103 == '\x05') {
    Z = (code *)CONCAT11(DAT_mem_0105,DAT_mem_0104);
    (*Z)();
    return;
  }
  return;
}




/* ========================================================= */
/* Function: FUN_code_1cf6 @ code:1cf6 */
/* ========================================================= */

void FUN_code_1cf6(void)

{
  byte bVar1;
  
  R1 = 0;
  FUN_code_1c76();
  if (R24 == ' ') {
    do {
      bVar1 = DAT_mem_00c0;
    } while ((bVar1 & 0x20) == 0);
    DAT_mem_00c6 = 0x14;
    do {
      bVar1 = DAT_mem_00c0;
    } while ((bVar1 & 0x20) == 0);
    R24 = 0x10;
    DAT_mem_00c6 = 0x10;
    return;
  }
  DAT_mem_0103 = DAT_mem_0103 + '\x01';
  R24 = DAT_mem_0103;
  if (DAT_mem_0103 == '\x05') {
    Z = (code *)CONCAT11(DAT_mem_0105,DAT_mem_0104);
    (*Z)();
    return;
  }
  return;
}




/* ========================================================= */
/* Function: FUN_code_1d17 @ code:1d17 */
/* ========================================================= */

byte FUN_code_1d17(byte R25,byte R24)

{
  char cVar1;
  byte bVar2;
  
  R1 = 0;
  DAT_mem_020a = 0;
  if (R24 != 0) {
    R25 = 0;
    R21R20 = 400;
    do {
      bVar2 = DAT_mem_0025;
      DAT_mem_0025 = bVar2 | 0x20;
      R18 = -0x18;
      R19 = '\x03';
      do {
        Z = 400;
        do {
          Z = Z + -1;
        } while (Z != 0);
        cVar1 = R18 + -1;
        R19 = R19 - (R18 == '\0');
        R18 = cVar1;
      } while (cVar1 != '\0' || R19 != '\0');
      bVar2 = DAT_mem_0025;
      DAT_mem_0025 = bVar2 & 0xdf;
      R18 = -0x18;
      R19 = '\x03';
      do {
        Z = 400;
        do {
          Z = Z + -1;
        } while (Z != 0);
        cVar1 = R18 + -1;
        R19 = R19 - (R18 == '\0');
        R18 = cVar1;
      } while (cVar1 != '\0' || R19 != '\0');
      R25 = R25 + 1;
    } while (R25 < R24);
    DAT_mem_020a = R24;
  }
  return R25;
}




/* ========================================================= */
/* Function: FUN_code_1d36 @ code:1d36 */
/* ========================================================= */

void FUN_code_1d36(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  
  R1R0 = (uint)(byte)R1R0;
  DAT_mem_00c4 = 0x33;
  DAT_mem_00c5 = 0;
  DAT_mem_00c1 = 0x18;
  DAT_mem_00c2 = 6;
  bVar1 = UCSR0B;
  UCSR0B = bVar1 & 0xfe;
  bVar1 = UCSR0A;
  UCSR0A = bVar1 | 1;
  bVar1 = ADCW;
  ADCW = bVar1 | 0x20;
  FUN_code_1d17();
  iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
  R15 = 0x14;
  R14 = 0x1e;
  R13 = 0x94;
  R12 = 6;
  R11 = 0x10;
  R10 = 1;
  R9 = 0x41;
  R17R16._0_1_ = 0x41;
  R17R16._1_1_ = 0x56;
  R8 = 0x56;
  R7 = 0x52;
  X = 0x5220;
  R6 = 0x20;
  R5 = 0x49;
  Z = (undefined1 *)0x4953;
  R4 = 0x53;
  R3 = 0x50;
LAB_code_1d73:
  do {
    DAT_mem_0209 = (byte)((uint)iVar4 >> 8);
    DAT_mem_0208 = (byte)iVar4;
    FUN_code_1c76();
joined_c0x1d76:
    if ((byte)R25R24 == '0') goto LAB_code_1dad;
    if ((byte)R25R24 == '1') {
      FUN_code_1c76();
      if ((byte)R25R24 == ' ') break;
      goto LAB_code_1d9d;
    }
    if ((byte)R25R24 == '@') {
      FUN_code_1c76();
      if (0x85 < (byte)R25R24) {
        FUN_code_1c76();
        FUN_code_1cf6();
        iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        goto LAB_code_1d73;
      }
      goto LAB_code_1dad;
    }
    if ((byte)R25R24 == 'A') {
      FUN_code_1c76();
      if ((byte)R25R24 == -0x80) {
        FUN_code_1cca();
        iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        goto LAB_code_1d73;
      }
      if ((byte)R25R24 == -0x7f) {
        FUN_code_1cca();
        iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        goto LAB_code_1d73;
      }
      if ((byte)R25R24 == -0x7e) {
        FUN_code_1cca();
        iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
      }
      else {
        if ((byte)R25R24 != -0x68) goto LAB_code_1e17;
        FUN_code_1cca();
        iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
      }
      goto LAB_code_1d73;
    }
    if ((byte)R25R24 == 'B') {
      R25R24._1_1_ = '\x13';
      while( true ) {
        do {
          bVar1 = DAT_mem_00c0;
        } while ((bVar1 & 0x80) == 0);
        uVar3 = DAT_mem_00c6;
        if (R25R24._1_1_ == '\0') break;
        R25R24._1_1_ = R25R24._1_1_ + -1;
      }
LAB_code_1dad:
      FUN_code_1cf6();
      iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
      goto LAB_code_1d73;
    }
    if ((byte)R25R24 == 'E') {
      R25R24._1_1_ = '\x04';
      while( true ) {
        do {
          bVar1 = DAT_mem_00c0;
        } while ((bVar1 & 0x80) == 0);
        uVar3 = DAT_mem_00c6;
        if (R25R24._1_1_ == '\0') break;
        R25R24._1_1_ = R25R24._1_1_ + -1;
      }
      goto LAB_code_1dad;
    }
    if ((((byte)R25R24 == 'P') || ((byte)R25R24 == 'R')) || ((byte)R25R24 == 'Q'))
    goto LAB_code_1dad;
    if ((byte)R25R24 == 'U') {
      FUN_code_1c76();
      DAT_mem_0106 = (byte)R25R24;
      FUN_code_1c76();
      DAT_mem_0107 = (byte)R25R24;
      FUN_code_1cf6();
      iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
      goto LAB_code_1d73;
    }
    if ((byte)R25R24 == 'V') {
      FUN_code_1c76();
      if ((byte)R25R24 == '0') {
        FUN_code_1c76();
        FUN_code_1c76();
        R17R16._1_1_ = (byte)R25R24;
        FUN_code_1c76();
        if (R17R16._1_1_ == 0) {
          FUN_code_1cca();
          iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        }
        else if (R17R16._1_1_ == 1) {
          FUN_code_1cca();
          iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        }
        else {
          FUN_code_1cca();
          iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        }
        goto LAB_code_1d73;
      }
      R25R24._1_1_ = '\x02';
      while( true ) {
        do {
          bVar1 = DAT_mem_00c0;
        } while ((bVar1 & 0x80) == 0);
        uVar3 = DAT_mem_00c6;
        if (R25R24._1_1_ == '\0') break;
        R25R24._1_1_ = R25R24._1_1_ + -1;
      }
LAB_code_1e17:
      FUN_code_1cca();
      iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
    }
    else {
      if ((byte)R25R24 != 'd') {
        if ((byte)R25R24 != 't') {
          if ((byte)R25R24 != 'u') {
            if ((byte)R25R24 != 'v') goto LAB_code_1d9d;
            goto LAB_code_1e17;
          }
          FUN_code_1c76();
          iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
          if ((byte)R25R24 == ' ') goto LAB_code_1f24;
          goto LAB_code_1d9d;
        }
        FUN_code_1c76();
        DAT_mem_0209 = (byte)R25R24;
        FUN_code_1c76();
        DAT_mem_0208 = (byte)R25R24;
        DAT_mem_0107 = DAT_mem_0107 * '\x02' + CARRY1(DAT_mem_0106,DAT_mem_0106);
        DAT_mem_0106 = DAT_mem_0106 * '\x02';
        FUN_code_1c76();
        if ((byte)R25R24 == 'E') {
          R25R24._0_1_ = DAT_mem_020c | 1;
          DAT_mem_020c = (byte)R25R24;
        }
        else {
          R25R24._0_1_ = DAT_mem_020c & 0xfe;
          DAT_mem_020c = (byte)R25R24;
        }
        FUN_code_1c76();
        iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        if ((byte)R25R24 != ' ') goto LAB_code_1d73;
        do {
          bVar1 = DAT_mem_00c0;
        } while ((bVar1 & 0x20) == 0);
        DAT_mem_00c6 = R15;
        X = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        if (X != 0) {
          R17R16 = CONCAT11(DAT_mem_020c,DAT_mem_020c) & 0x102;
          Z = (undefined1 *)CONCAT11(DAT_mem_0107,DAT_mem_0106);
          R19R18 = (undefined1 *)
                   CONCAT11(DAT_mem_0107 - ((DAT_mem_0106 != 0xff) + -1),DAT_mem_0106 + 1);
          R23R22 = R19R18;
          R21R20 = 0;
          if (R17R16._1_1_ != 0) goto LAB_code_1f07;
          do {
            if ((byte)R17R16 != 0) goto LAB_code_1efa;
            R25R24._1_1_ = *Z;
            do {
              bVar1 = DAT_mem_00c0;
            } while ((bVar1 & 0x20) == 0);
            while( true ) {
              DAT_mem_00c6 = R25R24._1_1_;
LAB_code_1efa:
              bVar1 = (char)R21R20 + 1;
              bVar2 = R21R20._1_1_ - (((char)R21R20 != -1) + -1);
              R21R20 = CONCAT11(bVar2,bVar1);
              R25R24 = R23R22 + 1;
              Z = R19R18;
              if (DAT_mem_0209 <= bVar2 && (bVar1 < DAT_mem_0208) <= (byte)(bVar2 - DAT_mem_0209)) {
                DAT_mem_0107 = R23R22._1_1_;
                DAT_mem_0106 = (byte)R23R22;
                goto LAB_code_1f16;
              }
              R23R22 = R25R24;
              R19R18 = (undefined1 *)
                       CONCAT11(R19R18._1_1_ - (((byte)R19R18 != -1) + -1),(byte)R19R18 + '\x01');
              if (R17R16._1_1_ == 0) break;
LAB_code_1f07:
              do {
                bVar1 = EEARH;
              } while ((bVar1 & 2) != 0);
              OCDR = Z._1_1_;
              WDTCR = (byte)Z;
              bVar1 = EEARH;
              EEARH = bVar1 | 1;
              R25R24._1_1_ = SFIOR;
              do {
                bVar1 = DAT_mem_00c0;
              } while ((bVar1 & 0x20) == 0);
            }
          } while( true );
        }
LAB_code_1f16:
        do {
          bVar1 = DAT_mem_00c0;
          if ((bVar1 & 0x20) != 0) break;
          bVar1 = DAT_mem_00c0;
        } while ((bVar1 & 0x20) == 0);
        goto LAB_code_1df3;
      }
      FUN_code_1c76();
      DAT_mem_0209 = (byte)R25R24;
      FUN_code_1c76();
      DAT_mem_0208 = (byte)R25R24;
      R25R24._0_1_ = DAT_mem_020c & 0xfe;
      DAT_mem_020c = (byte)R25R24;
      FUN_code_1c76();
      if ((byte)R25R24 == 'E') {
        R25R24._0_1_ = DAT_mem_020c | 1;
        DAT_mem_020c = (byte)R25R24;
      }
      if (DAT_mem_0208 != 0 || DAT_mem_0209 != 0) {
        R17R16._0_1_ = 0;
        R17R16._1_1_ = 0;
        do {
          FUN_code_1c76();
          Z = (undefined1 *)CONCAT11(R17R16._1_1_ - (((byte)R17R16 < 0xf8) + -2),(byte)R17R16 + 8);
          *Z = (byte)R25R24;
          bVar1 = (byte)R17R16 + 1;
          R17R16._1_1_ = R17R16._1_1_ - (((byte)R17R16 != 0xff) + -1);
          R17R16._0_1_ = bVar1;
        } while (R17R16._1_1_ < DAT_mem_0209 ||
                 (byte)(R17R16._1_1_ - DAT_mem_0209) < (bVar1 < DAT_mem_0208));
      }
      FUN_code_1c76();
      iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
      if ((byte)R25R24 != ' ') {
LAB_code_1d9d:
        iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
        DAT_mem_0103 = DAT_mem_0103 + '\x01';
        if (DAT_mem_0103 != '\x05') goto LAB_code_1d73;
        Z = (undefined1 *)CONCAT11(DAT_mem_0105,DAT_mem_0104);
        (*(code *)Z)();
        FUN_code_1c76();
        goto joined_c0x1d76;
      }
      if ((DAT_mem_020c & 1) == 0) {
        R25R24._0_1_ = -CARRY1(DAT_mem_0107,DAT_mem_0107) & R10;
        DAT_mem_020b = (byte)R25R24;
        DAT_mem_0107 = DAT_mem_0107 * '\x02' + CARRY1(DAT_mem_0106,DAT_mem_0106);
        if ((DAT_mem_0208 & 1) != 0) {
          R25R24 = (undefined1 *)CONCAT11(DAT_mem_0209,DAT_mem_0208);
          R25R24 = (undefined1 *)((int)R25R24 + 1);
          iVar4 = (int)R25R24;
        }
        do {
          bVar1 = EEARH;
        } while ((bVar1 & 2) != 0);
        R17R16._1_1_ = 0;
        Z = (undefined1 *)CONCAT11(DAT_mem_0107,DAT_mem_0106 * '\x02');
        Y = &DAT_mem_0108;
        R25R24 = (undefined1 *)iVar4;
        do {
          pbVar6 = Y;
          iVar5 = (int)R25R24;
          if (R17R16._1_1_ == 0) {
            do {
              R17R16._0_1_ = TIMSK;
              R17R16._0_1_ = (byte)R17R16 & 1;
            } while ((byte)R17R16 == 1);
            TIMSK = 3;
            *(uint *)((int)Z << 1) = R1R0;
            store_program_mem();
            do {
              R17R16._0_1_ = TIMSK;
              R17R16._0_1_ = (byte)R17R16 & 1;
            } while ((byte)R17R16 == 1);
            TIMSK = 0x11;
            *(uint *)((int)Z << 1) = R1R0;
            store_program_mem();
          }
          Y = Y + 1;
          pbVar7 = Y;
          R1R0._0_1_ = *pbVar6;
          Y = pbVar6 + 2;
          R1R0._1_1_ = *pbVar7;
          do {
            R17R16._0_1_ = TIMSK;
            R17R16._0_1_ = (byte)R17R16 & 1;
          } while ((byte)R17R16 == 1);
          TIMSK = 1;
          *(uint *)((int)Z << 1) = R1R0;
          store_program_mem();
          R17R16._1_1_ = R17R16._1_1_ + 1;
          R17R16._0_1_ = 1;
          if (R17R16._1_1_ < 0x40) goto LAB_code_1fab;
          while( true ) {
            R17R16._1_1_ = 0;
            do {
              R17R16._0_1_ = TIMSK;
              R17R16._0_1_ = (byte)R17R16 & 1;
            } while ((byte)R17R16 == 1);
            TIMSK = 5;
            *(uint *)((int)Z << 1) = R1R0;
            store_program_mem();
            do {
              R17R16._0_1_ = TIMSK;
              R17R16._0_1_ = (byte)R17R16 & 1;
            } while ((byte)R17R16 == 1);
            R17R16._0_1_ = 0x11;
            TIMSK = 0x11;
            *(uint *)((int)Z << 1) = R1R0;
            store_program_mem();
LAB_code_1fab:
            Z = Z + 2;
            R25R24 = (undefined1 *)(iVar5 + -2);
            if (R25R24 != (undefined1 *)0x0) break;
            if (R17R16._1_1_ == 0) {
              R1R0 = (uint)(byte)R1R0;
              bVar1 = DAT_mem_00c0;
              R17R16._1_1_ = 0;
              DAT_mem_0106 = DAT_mem_0106 * '\x02';
              goto joined_c0x1fb7;
            }
          }
        } while( true );
      }
      bVar1 = DAT_mem_0106 * '\x02';
      DAT_mem_0107 = DAT_mem_0107 * '\x02' + CARRY1(DAT_mem_0106,DAT_mem_0106);
      X = CONCAT11(DAT_mem_0209,DAT_mem_0208);
      DAT_mem_0106 = bVar1;
      if (X != 0) {
        Z = &DAT_mem_0108;
        R19R18._0_1_ = bVar1;
        R19R18._1_1_ = DAT_mem_0107;
        do {
          do {
            puVar8 = Z;
            bVar2 = EEARH;
          } while ((bVar2 & 2) != 0);
          OCDR = R19R18._1_1_;
          WDTCR = (byte)R19R18;
          Z = Z + 1;
          R25R24._0_1_ = *puVar8;
          SFIOR = (byte)R25R24;
          bVar2 = EEARH;
          EEARH = bVar2 | 4;
          bVar2 = EEARH;
          EEARH = bVar2 | 2;
          R19R18._1_1_ = R19R18._1_1_ - (((byte)R19R18 != 0xff) + -1);
          R19R18._0_1_ = (byte)R19R18 + 1;
        } while (Z != (undefined1 *)
                      CONCAT11(DAT_mem_0209 + 1 + (0xf7 < DAT_mem_0208) +
                               ((byte)Z < (byte)(DAT_mem_0208 + 8)),DAT_mem_0208 + 8));
        DAT_mem_0106 = bVar1 + DAT_mem_0208;
        DAT_mem_0107 = DAT_mem_0107 + DAT_mem_0209 + CARRY1(bVar1,DAT_mem_0208);
      }
      do {
        bVar1 = DAT_mem_00c0;
joined_c0x1fb7:
      } while ((bVar1 & 0x20) == 0);
      DAT_mem_00c6 = R15;
      do {
        bVar1 = DAT_mem_00c0;
      } while ((bVar1 & 0x20) == 0);
      DAT_mem_00c6 = R11;
    }
  } while( true );
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R15;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R9;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R8;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R7;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R6;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R5;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R4;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R3;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
LAB_code_1df3:
  iVar4 = CONCAT11(DAT_mem_0209,DAT_mem_0208);
  DAT_mem_00c6 = R11;
  goto LAB_code_1d73;
LAB_code_1f24:
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R15;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R14;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R13;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R12;
  do {
    bVar1 = DAT_mem_00c0;
  } while ((bVar1 & 0x20) == 0);
  DAT_mem_00c6 = R11;
  goto LAB_code_1d73;
}




