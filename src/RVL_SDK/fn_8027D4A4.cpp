#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32* slot4(s32, s32);
    virtual void slot5(void*, s32, s32);
};
extern Object_vptr_0* lbl_805A0EB8;
struct Map { s32* data; s32 count; s32 mask; };
extern "C" void fn_80281D64(void*, int, int);
extern "C" void fn_8027D0B8(Map*, u32, s32);
extern "C" void fn_8027D4A4(Map* self, s32 size) {
    s32* keys;
    s32* values;
    s32 flag;
    s32 count;
    s32* old;
    old = self->data;
    flag = self->count & 0x80000000;
    count = self->mask + 1;
    self->data = lbl_805A0EB8->slot4(size * 8, 0x15);
    fn_80281D64(self->data, 0, size * 4);
    self->count = 0;
    self->mask = size - 1;
    keys = old;
    values = old + count;
    for (s32 i = 0; i < count; i++) {
        if (*keys != 0) {
            fn_8027D0B8(self, *keys, *values);
        }
        keys++;
        values++;
    }
    if (flag == 0) {
        lbl_805A0EB8->slot5(old, count * 8, 0x15);
    }
}