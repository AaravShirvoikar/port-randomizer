#!/bin/bash

MIN_PORT=1024
MAX_PORT=65535

random_port=$(shuf -i $MIN_PORT-$MAX_PORT -n 1)

echo $random_port > port.txt

echo "Random port generated: $random_port"
