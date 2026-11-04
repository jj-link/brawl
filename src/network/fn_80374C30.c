#include <types.h>
#pragma force_active on

typedef struct {
    s32 value;
    u32 unk4;
    u16 key;
} Entry;

typedef struct {
    u8 pad[0x50];
    s32 state[4];
    void *table;
} Obj;

extern s32 fn_8035A590(void *);
extern Entry *fn_8035A598(void *, s32);
extern void fn_8035A918(void *, s32);
extern void fn_803738B8(s32 *, s32, s32);

s32 fn_80374C30(Obj *self, s32 key)
{
    s32 n = fn_8035A590(self->table);
    s32 i;
    s32 base;
    Entry *entry;

    if (n == 0) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        if ((s16)(fn_8035A598(self->table, i)->key - key) >= 0) {
            break;
        }
    }
    if (i == 0) {
        return 1;
    }
    while (i--) {
        fn_8035A918(self->table, i);
    }
    n = fn_8035A590(self->table);
    if (n == 0) {
        self->state[2] = 0;
        return 1;
    }
    base = fn_8035A598(self->table, 0)->value;
    for (i = 0; i < n; i++) {
        entry = fn_8035A598(self->table, i);
        entry->value -= base;
    }
    fn_803738B8(self->state, 0, base);
    return 1;
}
