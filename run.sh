#!/bin/bash

# Start the target program in the background
./target_program >program_stdout.txt &
PID=$!

# Wait for a moment to ensure the program has started
sleep 1

# Display the stdout of the target program
echo "Output of the target program:"
cat program_stdout.txt

# Load the kernel module
sudo insmod monitor_child.ko

# Check if the module has been loaded successfully
if [ $? -eq 0 ]; then
	echo "Kernel module has been loaded successfully."
else
	echo "Failed to load the kernel module."
fi
