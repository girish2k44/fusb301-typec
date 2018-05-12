KERNEL_SRC ?= /lib/modules/$(shell uname -r)/build

KBUILD_OPTIONS := FUSB301_ROOT=$(PWD)
KBUILD_OPTIONS += MODNAME?=fusb301

ARCH		?= $(SUBARCH)
CROSS_COMPILE	?= $(CONFIG_CROSS_COMPILE:"%"=%)

CC		= $(CROSS_COMPILE)gcc

obj-m+=typec-fusb301.o

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) modules $(KBUILD_OPTIONS)

modules_install:
	$(MAKE) INSTALL_MOD_STRIP=1 -C $(KERNEL_SRC) M=$(shell pwd) modules_install

clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(PWD) clean
