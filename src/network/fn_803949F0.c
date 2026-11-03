#include <types.h>
#pragma force_active on
extern void *fn_803974FC(void);
extern void *fn_80397564(void);
extern void **fn_80397570(void *);
extern int fn_80397580(void *);
extern int fn_8039375C(void *);
extern int fn_80393A04(void *);
extern int fn_80392088(void *, int, void *, int);
extern int fn_803900F4(void *);

int fn_803949F0(void *arg0) {
    void *root;
    void *network;
    void **slot;
    int handle;
    int *node;
    int result;

    root = fn_803974FC();
    network = fn_80397564();
    slot = fn_80397570(root);
    handle = fn_80397580(root);
    node = *(int **)((char *)*slot + 0xc);
    *(int *)((char *)arg0 + 0x330) = 10;
    *(int *)((char *)arg0 + 0x324) = 0;
    if (node[2] != 0 && node[3] != 0) {
        result = fn_8039375C(arg0);
        if (result != 0) return result;
        if (fn_80393A04(arg0) == 0) return 1;
        result = fn_80392088(network, handle, node, *(int *)((char *)network + 0x7d0));
        if (result != 0) {
            if (result == -1004) {
                if (fn_803900F4(network) != 0)
                    *(int *)((char *)arg0 + 0x330) = 16;
                return 1;
            } else if (result == -1005) {
                if (fn_803900F4(network) != 0)
                    *(int *)((char *)arg0 + 0x330) = 17;
                return 1;
            } else {
                if (fn_803900F4(network) != 0)
                    *(int *)((char *)arg0 + 0x330) = 14;
                return 1;
            }
        }
    }
    return 0;
}