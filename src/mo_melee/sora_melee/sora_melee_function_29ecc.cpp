#include <types.h>

#pragma force_active on

struct Handle {
    u8 pad[4];
    void* id;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Handle* slot1(s32);
};

struct Self {
    u8 pad[0x28];
    Object_vptr_0* owner;
};

struct A {
    u8 pad[0x10];
    u8 flags;
};

struct B {
    u8 pad[0x54];
    u8 flags;
};

struct C {
    u8 pad[0x2C];
    u8 flags;
};

struct QBits {
    u8 hi : 1;
    u8 rest : 7;
};

struct Out {
    A* a;
    B* b;
    C* c;
    u8 byte;
    QBits q;
};

extern "C" u32 fn_80111CB0(void*, void*);
extern "C" u32 fn_80134534(void*, u32);
extern "C" s32 fn_80134344(void*, u32);
extern "C" void fn_27_300EC(Handle*, u32);

extern "C" void fn_27_29ECC(Self* self, u32 flags, s32 index) {
    Handle* h = self->owner->slot1(index);
    u32 result = 0;

    {
        s32 v = flags & 1;
        if (v != 0)
            v = fn_80134344(h->id, 0);
        if (v != 0) {
            u32 tempId = fn_80134534(h->id, 0);
            if (tempId != 0xFFFF) {
                u32 id;
                s32 valid = 0;
                Out out;
                id = tempId;
                out.a = 0;
                out.b = 0;
                out.c = 0;
                out.byte = 0;
                out.q.hi = 0;
                s32 ok = fn_80111CB0(&id, &out) == 1;
                if (ok) {
                    if (out.a != 0 && out.b != 0 && out.c != 0)
                        valid = 1;
                    s32 enabled;
                    if (valid != 0 && ((out.b->flags >> 4) & 1) &&
                        ((out.c->flags >> 7) & 1))
                        enabled = 1;
                    else
                        enabled = 0;
                    ok = enabled == 1;
                }
                if (ok)
                    ok = ((out.a->flags >> 7) & 1) ^ 1;
                if (ok)
                    v = 1;
                else
                    goto fail0;
            } else {
            fail0:
                v = 0;
            }
        }
        if (v != 0) {
            result = 1;
            goto end;
        }
    }

    {
        s32 v = (flags >> 3) & 1;
        if (v != 0)
            v = fn_80134344(h->id, 3);
        if (v != 0) {
            u32 tempId = fn_80134534(h->id, 3);
            if (tempId != 0xFFFF) {
                u32 id;
                s32 valid = 0;
                Out out;
                id = tempId;
                out.a = 0;
                out.b = 0;
                out.c = 0;
                out.byte = 0;
                out.q.hi = 0;
                s32 ok = fn_80111CB0(&id, &out) == 1;
                if (ok) {
                    if (out.a != 0 && out.b != 0 && out.c != 0)
                        valid = 1;
                    s32 enabled;
                    if (valid != 0 && ((out.b->flags >> 4) & 1) &&
                        ((out.c->flags >> 7) & 1))
                        enabled = 1;
                    else
                        enabled = 0;
                    ok = enabled == 1;
                }
                if (ok)
                    ok = ((out.a->flags >> 7) & 1) ^ 1;
                if (ok)
                    v = 1;
                else
                    goto fail3;
            } else {
            fail3:
                v = 0;
            }
        }
        if (v != 0) {
            result = 8;
            goto end;
        }
    }

    {
        s32 v = (flags >> 1) & 1;
        if (v != 0)
            v = fn_80134344(h->id, 1);
        if (v != 0) {
            u32 tempId = fn_80134534(h->id, 1);
            if (tempId != 0xFFFF) {
                u32 id;
                s32 valid = 0;
                Out out;
                id = tempId;
                out.a = 0;
                out.b = 0;
                out.c = 0;
                out.byte = 0;
                out.q.hi = 0;
                s32 ok = fn_80111CB0(&id, &out) == 1;
                if (ok) {
                    if (out.a != 0 && out.b != 0 && out.c != 0)
                        valid = 1;
                    s32 enabled;
                    if (valid != 0 && ((out.b->flags >> 4) & 1) &&
                        ((out.c->flags >> 7) & 1))
                        enabled = 1;
                    else
                        enabled = 0;
                    ok = enabled == 1;
                }
                if (ok)
                    ok = ((out.a->flags >> 7) & 1) ^ 1;
                if (ok)
                    v = 1;
                else
                    goto fail1;
            } else {
            fail1:
                v = 0;
            }
        }
        if (v != 0) {
            result = 2;
            goto end;
        }
    }

    {
        s32 v = (flags >> 2) & 1;
        if (v != 0)
            v = fn_80134344(h->id, 2);
        if (v != 0) {
            u32 tempId = fn_80134534(h->id, 2);
            if (tempId != 0xFFFF) {
                u32 id;
                flags = 0;
                Out out;
                id = tempId;
                out.a = 0;
                out.b = 0;
                out.c = 0;
                out.byte = 0;
                out.q.hi = 0;
                s32 ok = fn_80111CB0(&id, &out) == 1;
                if (ok) {
                    if (out.a != 0 && out.b != 0 && out.c != 0)
                        flags = 1;
                    s32 enabled;
                    if (flags != 0 && ((out.b->flags >> 4) & 1) &&
                        ((out.c->flags >> 7) & 1))
                        enabled = 1;
                    else
                        enabled = 0;
                    ok = enabled == 1;
                }
                if (ok)
                    ok = ((out.a->flags >> 7) & 1) ^ 1;
                if (ok)
                    v = 1;
                else
                    goto fail2;
            } else {
            fail2:
                v = 0;
            }
        }
        if (v != 0)
            result = 4;
    }

end:
    if (result != 0)
        fn_27_300EC(h, result);
}
