#!/bin/bash

./target_program >program_stdout.txt &
PID=$!

sleep 1

echo "Output of the target program:"
cat program_stdout.txt

# Load the kernel module
sudo insmod monitor_child.ko

if [ $? -eq 0 ]; then
	echo "Kernel module has been loaded successfully."
else
	echo "Failed to load the kernel module."
fi
