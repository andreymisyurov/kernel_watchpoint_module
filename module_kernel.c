#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrey Misyurov");
MODULE_DESCRIPTION("My test task for the best job on the world - kernel module");
MODULE_VERSION("0.01");

static int __init module_kernel_init(void) {
  printk(KERN_INFO "Debug module loaded!\n");
  return 0;
}

static void __exit module_kernel_exit(void) {
  printk(KERN_INFO "Debug module unloaded!\n");
}

module_init(debug_module_init);
module_exit(debug_module_exit);
