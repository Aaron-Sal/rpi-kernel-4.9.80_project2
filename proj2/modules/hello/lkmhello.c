#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init lkmhello_init(void){

	printk(KERN_INFO "Hello world! Group04 in kernel space\n");
	return 0;
}

static void __exit lkmhello_exit(void){

	printk(KERN_INFO "lkmhello unloaded\n");
	}
module_init(lkmhello_init);
module_exit(lkmhello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Group04");
MODULE_DESCRIPTION("Hello World kernel module");
