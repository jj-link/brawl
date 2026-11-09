#include <types.h>

#pragma force_active on

typedef struct Obj {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ void *field4;
    /* 0x008 */ u8 pad8[0x7D0];
    /* 0x7D8 */ s32 field7D8;
} Obj;

extern s32 fn_8035A590(void *);
extern s32 *fn_8035A598(void *, s32);
extern void fn_8035ADB0(void *);
extern void fn_803889B8(s32, s32);
extern void *fn_803889C0(void *);
extern void fn_8038862C(void **);

void fn_8038A0D4(Obj *self) {
    s32 n;
    s32 temp;
    s32 node;
    s32 i;
    void *sp8;

    n = fn_8035A590(self->field4);
    for (i = 0; i < n; i++) {
        temp = *fn_8035A598(self->field4, i);
        if (self->field7D8 == 0) {
            fn_803889B8(temp, 0);
        } else {
            fn_803889B8(temp, self->field7D8);
        }
        self->field7D8 = temp;
    }

    fn_8035ADB0(self->field4);

    node = self->field7D8;
    if (node != 0) {
        sp8 = (void *)node;
        while (sp8 != 0) {
            node = (s32)fn_803889C0(sp8);
            fn_8038862C(&sp8);
            sp8 = (void *)node;
        }
        self->field7D8 = 0;
    }
}
