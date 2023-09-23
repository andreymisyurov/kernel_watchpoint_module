# скопировал .config
# из /home/misyurov/poky/build/tmp/work-shared/qemux86-64/kernel-build-artifacts
# в /home/misyurov/poky/build/tmp/work-shared/qemux86-64/kernel-source/
# вызвал make и ушел поесть. когда пришел и скомпилировал все получилось

ARCH=x86_64
CROSS_COMPILE=x86_64-poky-linux-

KERNEL_SRC=/home/misyurov/poky/build/tmp/work-shared/qemux86-64/kernel-source/

MODULE_NAME=module_kernel
MODULE_SRC=module_kernel.c

CC = $(CROSS_COMPILE)gcc
EXTRA_CFLAGS += -I/home/misyurov/poky/build/tmp/work-shared/qemux86-64/kernel-build-artifacts/include

obj-m += $(MODULE_NAME).o

all:
	make -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KERNEL_SRC) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) clean

install:
	cp $(MODULE_NAME).ko /path/to/target/rootfs/$(MODULE_NAME).ko

uninstall:
	rm -f /path/to/target/rootfs/$(MODULE_NAME).ko

.PHONY: all clean install uninstall
