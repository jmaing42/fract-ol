#!/bin/sh

set -e

find src -name "*.c" -o -name "*.h" | grep -v "/test/" | grep -vE "/\\." | while IFS= read -r line
do
  cp "$line" "tmp/$(basename "$line")"
done
