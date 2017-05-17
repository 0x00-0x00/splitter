#/bin/bash

echo "[*] Compiling program ..."
gcc main.c split.c -o splitter
if [[ $? == 0 ]]; then
    echo "[+] Compilation successfull.";
else
    echo "[!] Error on compilation.";
fi
