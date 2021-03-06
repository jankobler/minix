#define _SYSTEM 1
#define _MINIX_SYSTEM 1
#include <sys/cdefs.h>
#include "namespace.h"
#include <lib.h>
#include <minix/u64.h>
#include <minix/vm.h>

/* INCLUDES HERE */

#include <sys/mman.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

#ifdef __weak_alias
__weak_alias(mmap, _mmap)
__weak_alias(munmap, _munmap)
#endif

void *minix_mmap_for(endpoint_t forwhom,
	void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
	message m;
	int r;

	memset(&m, 0, sizeof(m));
	m.VMM_ADDR = addr;
	m.VMM_LEN = len;
	m.VMM_PROT = prot;
	m.VMM_FLAGS = flags;
	m.VMM_FD = fd;
	m.VMM_OFFSET = offset;
	m.VMM_FORWHOM = forwhom;

	if(forwhom != SELF) {
		m.VMM_FLAGS |= MAP_THIRDPARTY;
	}

	r = _syscall(VM_PROC_NR, VM_MMAP, &m);

	if(r != OK) {
		return MAP_FAILED;
	}

	return m.VMM_RETADDR;
}

int minix_vfs_mmap(endpoint_t who, off_t offset, size_t len,
	dev_t dev, ino_t ino, int fd, u32_t vaddr, u16_t clearend,
	u16_t flags)
{
	message m;

	memset(&m, 0, sizeof(message));

	m.m_vm_vfs_mmap.who = who;
	m.m_vm_vfs_mmap.offset = offset;
	m.m_vm_vfs_mmap.dev = dev;
	m.m_vm_vfs_mmap.ino = ino;
	m.m_vm_vfs_mmap.vaddr = vaddr;
	m.m_vm_vfs_mmap.len = len;
	m.m_vm_vfs_mmap.fd = fd;
	m.m_vm_vfs_mmap.clearend = clearend;
	m.m_vm_vfs_mmap.flags = flags;

	return _syscall(VM_PROC_NR, VM_VFS_MMAP, &m);
}

void *mmap(void *addr, size_t len, int prot, int flags,
	int fd, off_t offset)
{
	return minix_mmap_for(SELF, addr, len, prot, flags, fd, offset);
}

int munmap(void *addr, size_t len)
{
	message m;

	memset(&m, 0, sizeof(m));
	m.VMUM_ADDR = addr;
	m.VMUM_LEN = len;

	return _syscall(VM_PROC_NR, VM_MUNMAP, &m);
}


void *vm_remap(endpoint_t d,
			endpoint_t s,
			void *da,
			void *sa,
			size_t size)
{
	message m;
	int r;

	memset(&m, 0, sizeof(m));
	m.VMRE_D = d;
	m.VMRE_S = s;
	m.VMRE_DA = (char *) da;
	m.VMRE_SA = (char *) sa;
	m.VMRE_SIZE = size;

	r = _syscall(VM_PROC_NR, VM_REMAP, &m);
	if (r != OK)
		return MAP_FAILED;
	return (void *) m.VMRE_RETA;
}

void *vm_remap_ro(endpoint_t d,
			endpoint_t s,
			void *da,
			void *sa,
			size_t size)
{
	message m;
	int r;

	memset(&m, 0, sizeof(m));
	m.VMRE_D = d;
	m.VMRE_S = s;
	m.VMRE_DA = (char *) da;
	m.VMRE_SA = (char *) sa;
	m.VMRE_SIZE = size;

	r = _syscall(VM_PROC_NR, VM_REMAP_RO, &m);
	if (r != OK)
		return MAP_FAILED;
	return (void *) m.VMRE_RETA;
}

int vm_unmap(endpoint_t endpt, void *addr)
{
	message m;

	memset(&m, 0, sizeof(m));
	m.VMUN_ENDPT = endpt;
	m.VMUN_ADDR = addr;

	return _syscall(VM_PROC_NR, VM_SHM_UNMAP, &m);
}

unsigned long vm_getphys(endpoint_t endpt, void *addr)
{
	message m;
	int r;

	memset(&m, 0, sizeof(m));
	m.VMPHYS_ENDPT = endpt;
	m.VMPHYS_ADDR = (long) addr;

	r = _syscall(VM_PROC_NR, VM_GETPHYS, &m);
	if (r != OK)
		return 0;
	return m.VMPHYS_RETA;
}

u8_t vm_getrefcount(endpoint_t endpt, void *addr)
{
	message m;
	int r;

	memset(&m, 0, sizeof(m));
	m.VMREFCNT_ENDPT = endpt;
	m.VMREFCNT_ADDR = (long) addr;

	r = _syscall(VM_PROC_NR, VM_GETREF, &m);
	if (r != OK)
		return (u8_t) -1;
	return (u8_t) m.VMREFCNT_RETC;
}

