#pragma force_active on
#include <types.h>

struct Ent {
    s32 flag;
    char pad[0x54];
    s32 f58;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Ent* slot1(s32);
    virtual void slot2();
    virtual s32 slot3();
};

struct Inner {
    s32 a;
    s32 b;
};

struct Holder {
    char pad[0xD8];
    Inner* inner;
};

struct Self {
    char pad0[0x28];
    Holder* holder;
    Object_vptr_0* obj;
    f32 f30;
    char pad1[0xB8 - 0x34];
    char sub[0xCB - 0xB8];
    s8 cb;
    char pad2[0x104 - 0xCC];
    u8 u104;
};

struct Arg3 {
    char pad[0x14];
    u32 flags;
};

extern "C" {
void fn_27_36074(void*, s32, s32, s32);
s32 fn_27_36028(void*, s32, s32);
void fn_27_362E4(void*, s32);
void fn_27_36650(void*, s32, s32);
void fn_27_4D95C(void*, void*, s32);
void fn_27_4DBA8(void*, s32, s32, f32);

void fn_27_4E348(Self* self, s32 arg1, s32 arg2, Arg3* arg3) {
    s32 i;
        s32 field;
    {
    s32 r28;

    fn_27_36074(self->sub, arg1, (arg3->flags >> 5) & 1, arg2);
    r28 = fn_27_36028(self->sub, arg1, arg2);

    if (self->obj->slot1(arg1)->flag == 0 ||
        arg2 != self->obj->slot1(arg1)->f58) {
        Ent* e = self->obj->slot1(arg1);
        e->flag = 1;
        self->obj->slot1(arg1)->f58 = arg2;
        fn_27_362E4(self->sub, arg2);
        field = self->obj->slot1(arg1)->f58;

        for (i = 0; i < self->obj->slot3(); i++) {
            if (self->obj->slot1(i)->flag != 0 && i != arg1 &&
                self->obj->slot1(i)->f58 == field) {
                goto done;
            }
        }
        fn_27_36650(self->sub, field, 0);
    done:;
    }

    fn_27_4D95C(self->obj->slot1(arg1), arg3, r28);
    self->cb = (s8)((arg3->flags >> 6) & 1);

    if (self->u104 == 1) {
        Inner* inner = self->holder->inner;
        s32 val = inner->b;
        void* ret = self->obj->slot1(arg1);
        fn_27_4DBA8(ret, val, r28, self->f30);
    }
    }
}
}