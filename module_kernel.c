#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <asm/debugreg.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrey Misyurov");
MODULE_DESCRIPTION("My test task for the best job on the world - kernel module");
MODULE_VERSION("0.01");

static unsigned long address = 0;

module_param(address, ulong, 0644);
MODULE_PARM_DESC(address, "Memory address for the watch point");



static void set_watchpoint(unsigned long addr) {
  set_debugreg(addr, 0);
  unsigned long dr7 = 0;
  get_debugreg(dr7, 7);
  dr7 |= (1 << 0) | (3 << 16);
  set_debugreg(dr7, 7);
}

static void clear_watchpoint(void) {
  unsigned long dr7 = 0;
  get_debugreg(dr7, 7);
  dr7 &= ~(1 << 0);
  set_debugreg(dr7, 7);
}



static int __init module_kernel_init(void) {
  printk(KERN_INFO "Debug module loaded! address: 0x%lx\n", address);
  set_watchpoint(address);
  return 0;
}

static void __exit module_kernel_exit(void) {
  printk(KERN_INFO "Debug module unloaded! address: 0x%lx\n", address);
  clear_watchpoint();
}

module_init(module_kernel_init);
module_exit(module_kernel_exit);
