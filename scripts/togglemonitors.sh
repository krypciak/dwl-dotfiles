#!/bin/sh
wlr-randr | grep -E '"*"|Enabled' | awk '{if ($1 ~ "Enabled") print $2 "@"; else print $1 " "}' | tr -d '\n' | tr '@' '\n' | fuzzel -d --log-level none --width 15 --lines 5 | awk '{print $1}' | xargs -I _ wlr-randr --output _ --toggle
