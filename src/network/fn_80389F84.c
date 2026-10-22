#include <types.h>
#pragma force_active on

extern s32 fn_8035A590(void *);
extern u32 *fn_8035A598(void *, s32);

typedef struct {
    u8 pad[4];
    void *table;
} Obj;

s32 fn_80389F84(Obj *self, u32 value) {
    s32 n = fn_8035A590(self->table);
    s32 i;

    for (i = 0; i < n; i++) {
        if (value == *fn_8035A598(self->table, i)) {
            return i;
        }
    }
    return -1;
}
