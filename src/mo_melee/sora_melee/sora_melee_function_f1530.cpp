#include <types.h>
#pragma force_active on
struct Elem { s32 unk0; s32 key; };
class Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual Elem* get(s32 index);
};
class Outer {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual s32 count();
    u8 pad[0xc];
    Inner inner;
    s32 find(s32 key) {
        if (key <= -1) return -1;
        s32 n = count();
        for (s32 i = 0; i < n; i++) {
            if (key == inner.get(i)->key) return i;
        }
        return -1;
    }
};
extern "C" void fn_27_FE028(s16*, const s16*);
extern "C" void fn_27_F1530(s16* dst, Outer* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) *dst = 0;
    else fn_27_FE028(dst, (const s16*)self->inner.get(idx));
}