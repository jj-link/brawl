#include <types.h>
#pragma force_active on
extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void*, int, u32);
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_248[];
extern char __RTTI__6gfTask[];
u32 fn_27_8CB9C(void*);
u8 fn_27_1141C4(void*, u32);
void* getEntity__14ftEntryManagerFUl(void*, u32);
u32 fn_27_115968(void*, int);

struct Inner {
    virtual void f0();
    virtual void* getItem(s32 i);
    virtual void f8();
    virtual s32 getCount();
};
struct Outer { u8 pad[8]; Inner inner; };
struct Self { u8 pad[0x70]; s32 a; s32 b; u8 pad2[0xDC]; Outer* outer; };

void fn_27_10D738(Self* self, u32 cat, u32 id) {
    if (cat != 10) {
        void* t = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), cat, id);
        if (t) {
            id = fn_27_8CB9C(__dynamic_cast(t, 0x3c, lbl_27_data_248, __RTTI__6gfTask, 1));
        }
    }
    s32 n = self->outer->inner.getCount();
    for (s32 i = 0; i < n; i++) {
        if (fn_27_1141C4(*(void**)self->outer->inner.getItem(i), id) != 0xFF) {
            n = ((s32*)*(void**)self->outer->inner.getItem(i))[1];
            if (n != self->b) {
                if (fn_27_115968(getEntity__14ftEntryManagerFUl(self->outer, n), 0) == 1) {
                    self->b = n;
                    self->a = -1;
                }
            }
            break;
        }
    }
}
}