#!/bin/bash

log()
{
    echo -e "\033[092mINFO\033[0m: $1";
}

error()
{
    echo -e "\033[091mERROR\033[0m: $1"
}

while getopts "f:s:" opt; do
    case opt in
        f) log "Basename set to: $OPTARG"; file=$OPTARG;;
        s) log "Split size set to: $OPTARG"; split_size=$OPTARG;;
        ?) error "Invalid argument."; exit 1;;
    esac
done

if [[ $# < 2 ]]; then
    echo 'Uso: $0 -f BASENAME';
    exit 1;
fi

i=0;
while [[ -f $file.$i ]]; do
    cat $file.$i >> $file;
    i=$((i+1));
done

echo "[+] File reconstructed.";
