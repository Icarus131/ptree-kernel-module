#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/string.h>

#define TARGET_PROCESS_NAME "target_proc"

static int monitor_child_init(void) {
  struct task_struct *task;
  struct task_struct *child_task;

  printk(KERN_INFO "Monitoring process with name: %s\n", TARGET_PROCESS_NAME);

  for_each_process(task) {
    if (strcmp(task->comm, TARGET_PROCESS_NAME) == 0) {
      printk(KERN_INFO "Target process name: %s, PID: %d\n", task->comm,
             task->pid);

      list_for_each_entry(child_task, &task->children, sibling) {
        printk(KERN_INFO "Child process PID: %d\n", child_task->pid);
      }
    }
  }

  return 0;
}

static void monitor_child_exit(void) {
  printk(KERN_INFO "Exiting monitor_child module\n");
}

module_init(monitor_child_init);
module_exit(monitor_child_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION(
    "Kernel module to monitor child processes of a specific process by name");
MODULE_AUTHOR("Anirudh Prasad");
