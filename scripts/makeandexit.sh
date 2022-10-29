#!/bin/sh

LGREEN='\033[1;32m'
GREEN='\033[0;32m'
LBLUE='\033[1;34m'
RED='\033[0;31m'
NC='\033[0m' 

function confirm() {
    echo -en "$LBLUE |||$LGREEN $1 $LBLUE(y/N)? >> $NC"
    read choice
    case "$choice" in 
    y|Y ) return 0;;
    n|N|"" ) exit;;
    * ) confirm "$1" "ignore"; return 0;;
    esac
}

cd ~/.config/dwl/dwl-dotfiles
make
if [ ! $? -eq 0 ]; then
    echo -e "$RED COMPILATION ERROR"
    read
    exit
fi

confirm "Do you want to exit?"
touch /tmp/restart_dwl
echo -e "$RED Exiting...";
killall dwl
