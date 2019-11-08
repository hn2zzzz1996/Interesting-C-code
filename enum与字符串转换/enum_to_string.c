#include <stdio.h>
#include "verify.h"

# define ARRAY_CARDINALITY(Array) (sizeof(Array) / sizeof(*(Array)))

# define VIR_ENUM_IMPL(name, lastVal, ...)                               \
    static const char *const name ## TypeList[] = { __VA_ARGS__ };      \
    verify(ARRAY_CARDINALITY(name ## TypeList) == lastVal);             \
    const char *name ## TypeToString(int type) {                        \
        return virEnumToString(name ## TypeList,                        \
                               ARRAY_CARDINALITY(name ## TypeList),     \
                               type);                                   \
    }                                                                   \
    int name ## TypeFromString(const char *type) {                      \
        return virEnumFromString(name ## TypeList,                      \
                                 ARRAY_CARDINALITY(name ## TypeList),   \
                                 type);                                 \
    }

const char *virEnumToString(const char *const*types,
                            unsigned int ntypes,
                            int type)
{
    if (type < 0 || type >= ntypes)
        return NULL;

    return types[type];
}

int virEnumFromString(const char *const*types,
                      unsigned int ntypes,
                      const char *type)
{
	# define STREQ(a, b) (strcmp(a, b) == 0)
    size_t i;
    if (!type)
        return -1;

    for (i = 0; i < ntypes; i++)
        if (STREQ(types[i], type))
            return i;

    return -1;
}

typedef enum {
    VIR_HOOK_QEMU_OP_START,            /* domain is about to start */
    VIR_HOOK_QEMU_OP_STOPPED,          /* domain has stopped */
    VIR_HOOK_QEMU_OP_PREPARE,          /* domain startup initiated */
    VIR_HOOK_QEMU_OP_RELEASE,          /* domain destruction is over */
    VIR_HOOK_QEMU_OP_MIGRATE,          /* domain is being migrated */
    VIR_HOOK_QEMU_OP_STARTED,          /* domain has started */
    VIR_HOOK_QEMU_OP_RECONNECT,        /* domain is being reconnected by libvirt */
    VIR_HOOK_QEMU_OP_ATTACH,           /* domain is being attached to be libvirt */
    VIR_HOOK_QEMU_OP_RESTORE,          /* domain is being restored */
    VIR_HOOK_QEMU_OP_DEFINE,

    VIR_HOOK_QEMU_OP_LAST,
} virHookQemuOpType;

VIR_ENUM_IMPL(virHookQemuOp, VIR_HOOK_QEMU_OP_LAST,
              "start",
              "stopped",
              "prepare",
              "release",
              "migrate",
              "started",
              "reconnect",
              "attach",
              "restore",
			  "define")

int main(){
	const char *opstr = virHookQemuOpTypeToString(VIR_HOOK_QEMU_OP_START);
	printf("%s\n", opstr);
}
