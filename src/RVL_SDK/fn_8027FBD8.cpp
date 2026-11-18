#include <types.h>
#pragma force_active on

class Class_8028096C {
public:
    Class_8028096C(int, int, int, int);
    ~Class_8028096C();
    char data[12];
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int, int, char*, const char*, int);
    virtual void slot3();
    virtual void slot4();
};

struct Bool8 {
    s8 value;
    Bool8(bool v) : value(v) {}
    operator bool() const { return value != 0; }
};

struct Slot {
    s8 flag;
    s32 size;
    void* ptr;
    s32 arg;
    s8 done;
    Bool8 isFree() { return flag == 1; }
    bool fits(s32 n) { return isFree() && size >= n; }
};

class Class_804863B0 {
public:
    virtual void fn_8027F128();
    virtual void fn_8027F188();
    virtual void fn_8027F1C0();
    virtual void fn_8027F24C();
    virtual void* fn_8027F28C(s32 size, s32 arg);
    char pad[0x28];
    s32 count;
    Slot slots[1];
};

extern "C" {
extern char lbl_8040F428[];
extern Object_vptr_0* lbl_805A0EB0;
extern void* lbl_805A0EC8;
void* fn_8027EA20(void*, s32, s32);
Class_8028096C* fn_80280A74(Class_8028096C*, const char*);
Class_8028096C* fn_80280AA8(Class_8028096C*, s32);

void* fn_8027FBD8(Class_804863B0* self, s32 arg1, s32 arg2) {
    s32 count;
    Slot* e;
    Slot* best;
    s32 i;
    s32 r27;
    s32 t;
    s32 ok;

    if (arg1 < 0x2000) {
        return fn_8027EA20(lbl_805A0EC8, arg1, arg2);
    }
    count = self->count;
    best = 0;
    e = self->slots;
    for (i = 0; i < count; i++) {
        ok = e->fits(arg1);
        if (ok != 0) {
            if (best == 0 || e->size < best->size) {
                best = e;
            }
        }
        e++;
    }
    if (best != 0) {
        best->flag = 0;
        return best->ptr;
    }
    t = arg1 + 0x40;
    r27 = 1;
    for (; t > 0; t >>= 1) {
        r27 += r27;
    }
    if (count < 0x80) {
        void* ret;
        s32 sz;
        s32 n;
        Slot* s;
        {
            union { s32 align; s8 value; } flag;
            flag.value = 1;
            char buf[0x200];
            Class_8028096C obj((int)buf, 0x200, (int)&flag.value, count);
            fn_80280A74(fn_80280AA8(fn_80280A74(&obj, lbl_8040F428 + 0x54), arg1), lbl_8040F428 + 0x66);
            lbl_805A0EB0->slot2(1, 0xAF55ADDE, buf, lbl_8040F428 + 0xA5, 0x30B);
        }
        n = self->count;
        self->count = n + 1;
        s = &self->slots[n];
        s->flag = 0;
        sz = r27 - 0x40;
        s->size = sz;
        ret = self->fn_8027F28C(sz, arg2);
        s->ptr = ret;
        s->arg = arg2;
        s->done = 0;
        return ret;
    } else {
        union { s32 align; s8 value; } flag;
        flag.value = 1;
        char buf[0x200];
        Class_8028096C obj((int)buf, 0x200, (int)&flag.value, count);
        fn_80280A74(fn_80280AA8(fn_80280A74(&obj, lbl_8040F428 + 0x54), arg1), lbl_8040F428 + 0xB6);
        lbl_805A0EB0->slot2(1, 0xAF55ADDE, buf, lbl_8040F428 + 0xA5, 0x318);
    }
    return self->fn_8027F28C(arg1, arg2);
}
}