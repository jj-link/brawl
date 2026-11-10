#include <types.h>
#pragma force_active on
extern "C" {
void fn_8027DDFC(void*, s32, s32);
void fn_80281D64(void*, s32, s32);
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void* slot4(s32, s32);
virtual void slot5(void*, s32, s32);
};
extern Object_vptr_0* lbl_805A0EB8;
struct Owner { s32* buf; s32 used; s32 cap; };
void fn_8027E0A0(Owner* self, s32 count) {
s32* p31;
s32* p30;
s32* p29;
s32 n;
s32* old = self->buf;
n = self->cap + 1;
self->buf = (s32*)lbl_805A0EB8->slot4(count * 12, 21);
fn_80281D64(self->buf, 255, count * 4);
self->used = 0;
self->cap = count - 1;
p31 = old;
p30 = old + n * 2;
p29 = old + n;
for (s32 i = 0; i < n; ++i) {
if ((u32)*p31 != 0xFFFFFFFF) fn_8027DDFC(self, *p29, *p30);
++p31;
++p30;
++p29;
}
lbl_805A0EB8->slot5(old, n * 12, 21);
}
}