# Instructions to run

- First run make to create the .ko file which is the kernel module (the source code for the module is monitor_child.c)
- Then run gcc process_creation.c -o target_proc to compile the program that we will be monitoring
- Then run the program with ./target_proc
- Now do sudo insmod monitor_child.ko to insert the module into the kernel
- Now run dmesg to see the output of the module
