override MAKEFLAGS += -rR
override KERNEL := kernel

ARCH ?= x86_64

define DEFAULT_VAR =
    ifeq ($(origin $1),default)
        override $(1) := $(2)
    endif
    ifeq ($(origin $1),undefined)
        override $(1) := $(2)
    endif
endef

override DEFAULT_CC := cc
$(eval $(call DEFAULT_VAR,CC,$(DEFAULT_CC)))

override DEFAULT_LD := ld
$(eval $(call DEFAULT_VAR,LD,$(DEFAULT_LD)))

override DEFAULT_CFLAGS := -g -O2 -pipe -ggdb -DPRINTF_DISABLE_SUPPORT_EXPONENTIAL -DPRINTF_DISABLE_SUPPORT_FLOAT
$(eval $(call DEFAULT_VAR,CFLAGS,$(DEFAULT_CFLAGS)))

override DEFAULT_CPPFLAGS :=
$(eval $(call DEFAULT_VAR,CPPFLAGS,$(DEFAULT_CPPFLAGS)))

override DEFAULT_NASMFLAGS := -F dwarf -g
$(eval $(call DEFAULT_VAR,NASMFLAGS,$(DEFAULT_NASMFLAGS)))

override DEFAULT_LDFLAGS :=
$(eval $(call DEFAULT_VAR,LDFLAGS,$(DEFAULT_LDFLAGS)))

override CFLAGS += \
    -Wall \
    -Wextra \
    -std=gnu11 \
    -ffreestanding \
    -fno-stack-protector \
    -fno-stack-check \
    -fno-lto \
    -fPIE \
    -m64 \
    -march=x86-64 \
    -mno-80387 \
    -mno-mmx \
    -mno-sse \
    -mno-sse2 \
    -mno-red-zone

override CPPFLAGS := \
    -I src \
    $(CPPFLAGS) \
    -MMD \
    -MP \
	-I headers

override LDFLAGS += \
    -m elf_x86_64 \
    -nostdlib \
    -static \
    -pie \
    --no-dynamic-linker \
    -z text \
    -z max-page-size=0x1000 \
    -T src/arch/$(ARCH)/linker.ld

override NASMFLAGS += \
    -Wall \
    -f elf64

CFILES := $(shell cd src && find * -name '*.c' ! -path 'arch/*')
ASFILES := $(shell cd src && find * -name '*.S' ! -path 'arch/*')

CFILES += $(shell cd src && find arch/$(ARCH) -name '*.c')
ASFILES += $(shell cd src && find arch/$(ARCH) -name '*.S')

OBJ := $(addprefix obj/,$(CFILES:.c=.c.o) $(ASFILES:.S=.S.o))
HEADER_DEPS := $(addprefix obj/,$(CFILES:.c=.c.d) $(ASFILES:.S=.S.d))

.PHONY: all
all: bin/$(KERNEL)

src/limine.h:
	curl -Lo $@ https://github.com/limine-bootloader/limine/raw/trunk/limine.h

bin/$(KERNEL): GNUmakefile src/arch/$(ARCH)/linker.ld $(OBJ)
	mkdir -p "$(dir $@)"
	$(LD) $(OBJ) $(LDFLAGS) -o $@

-include $(HEADER_DEPS)

obj/%.c.o: src/%.c GNUmakefile src/limine.h
	mkdir -p "$(dir $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -c $< -o $@

obj/%.S.o: src/%.S GNUmakefile
	mkdir -p "$(dir $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -c $< -o $@

.PHONY: clean
clean:
	rm -rf bin obj

.PHONY: distclean
distclean: clean
	rm -f src/limine.h
