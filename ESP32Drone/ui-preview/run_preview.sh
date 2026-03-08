#!/usr/bin/env sh
set -eu
cd "$(dirname "$0")"
PORT="${1:-8080}"
echo "Serving drone_ui.html on http://localhost:${PORT}/drone_ui.html"
python3 -m http.server "$PORT"
