#ifndef __MINOS_VM_PM_H__
#define __MINOS_VM_PM_H__

#include <minos/types.h>

#define VM_PM_ACTION_BY_SELF (1 << 0)
#define VM_PM_ACTION_BY_MVM (1 << 1)
#define VM_PM_ACTION_BY_HOST (1 << 2)
#define VM_PM_FLAGS_DESTROY (1 << 8)

int vm_power_off(int vmid, void *arg, int byself);

int vm_reset(int vmid, void *args, int byself);
int native_vm_reboot(struct vm *vm);

int vm_suspend(int vmid);

static inline bool pm_action_by_self(int flags)
{
	return !!(flags & VM_PM_ACTION_BY_SELF);
}

static inline bool pm_action_by_mvm(int flags)
{
	return !!(flags & VM_PM_ACTION_BY_MVM);
}

static inline bool pm_action_by_host(int flags)
{
	return !!(flags & VM_PM_ACTION_BY_HOST);
}

static inline char *pm_action_caller(int flags)
{
	if (pm_action_by_self(flags))
		return "itself";
	else if (pm_action_by_mvm(flags))
		return "mvm";
	else
		return "host";
}

#endif
