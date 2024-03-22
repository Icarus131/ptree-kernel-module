#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/string.h>

static int target_pid = 1;

module_param(target_pid, int, S_IRUGO);

static void print_process_tree(struct task_struct *task, int depth) {
  struct task_struct *child_task;
  struct list_head *list;

  printk(KERN_INFO "%*s|- %s (PID: %d)\n", depth * 4, "", task->comm,
         task->pid);

  list_for_each(list, &task->children) {
    child_task = list_entry(list, struct task_struct, sibling);
    print_process_tree(child_task, depth + 1);
  }
}

static int monitor_child_init(void) {
  struct task_struct *task;

  printk(KERN_INFO "Monitoring process tree with root PID: %d\n", target_pid);

  for_each_process(task) {
    if (task->pid == target_pid) {
      print_process_tree(task, 0);
      break;
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
MODULE_DESCRIPTION("Kernel module to monitor child processes of a specific "
                   "process by PID and display process tree");
MODULE_AUTHOR("Anirudh Prasad");
