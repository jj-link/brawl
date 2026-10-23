#include <types.h>
#pragma force_active on

typedef struct Object Object;

struct Object {
    u8 pad0[4];
    void *field4;
    u8 pad8[0x480];
    void (*callback)(Object *, s32, s32, s32);
    u8 pad48C[8];
    s32 field494;
    u8 pad498[0x340];
    s32 field7D8;
};

extern s32 *fn_8035A598(void *);
extern void fn_8035A918(void *, s32);
extern void fn_803889B8(s32, s32);

void fn_8038A00C(Object *self, s32 arg1) {
    s32 temp;

    temp = *fn_8035A598(self->field4);
    self->callback(self, 2, temp, self->field494);
    fn_8035A918(self->field4, arg1);
    if (self->field7D8 == 0) {
        fn_803889B8(temp, 0);
    } else {
        fn_803889B8(temp, self->field7D8);
    }
    self->field7D8 = temp;
}
