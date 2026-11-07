#include <types.h>
#pragma force_active on
extern void *fn_8015C1EC(void *, u16);
typedef struct { char pad[16]; u16 count; char pad2[6]; char data[1]; } Owner;
u32 fn_80279BA4(Owner *arg0, u32 arg1) {
    u32 i;
    u32 *entry;
    for (i = 0; i < arg0->count; i++) {
        entry = (u32 *)fn_8015C1EC(arg0->data, (u16)i);
        if (entry[0] == arg1)
            return entry[1];
    }
    return 0;
}