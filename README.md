# Sucx

This project is named after its defining quality. I aim to turn this into atleast a usable os soon.

## How to use this?

Clone the project using the submodules as they are used for various parts of the kernel

### Dependencies

Any `make` command depends on GNU make (`gmake`) and is expected to be run using it. This usually means using `make` on most GNU/Linux distros, or `gmake` on other non-GNU systems.

All `make all*` targets depend on a GNU-compatible C toolchain capable of generating x86-64 ELF objects. Usually `gcc/binutils` or `clang/llvm/lld` provided by any x86-64 UNIX like (including Linux) distribution will suffice.

Additionally, building an ISO with `make all` requires `xorriso`, and building a HDD/USB image with `make all-hdd` requires `sgdisk` (usually from `gdisk` or `gptfdisk` packages) and `mtools`.

### Makefile targets

Running `make all` will compile the kernel (from the `kernel/` directory) and then generate a bootable ISO image.

Running `make all-hdd` will compile the kernel and then generate a raw image suitable to be flashed onto a USB stick or hard drive/SSD.

Running `make run` will build the kernel and a bootable ISO (equivalent to make all) and then run it using `qemu` (if installed).

Running `make run-hdd` will build the kernel and a raw HDD image (equivalent to make all-hdd) and then run it using `qemu` (if installed).

The `run-uefi` and `run-hdd-uefi` targets are equivalent to their non `-uefi` counterparts except that they boot `qemu` using a UEFI-compatible firmware.

## TODO
- [ ] Memory management
- [ ] PIT Timer
- [ ] Undefined Behaviour Sanitizer
- [ ] HPET Timer
- [ ] LAPIC Timer
- [ ] Scheduler
- [ ] VFS
- [ ] PS2 Controller driver
- [ ] PS2 Keyboard driver
- [ ] PS2 Mouse driver
- [ ] Drivers as "modules" interface
- [ ] Print to /dev/tty instead of framebuffer
- [ ] tmpfs
- [ ] Disk driver
- [ ] Any good file system
- [ ] Integrate DWARF in stacktrace
- [ ] USB driver
- [ ] USB keyboard / mouse
- [ ] Seperate init phase and later phase