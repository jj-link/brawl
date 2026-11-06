#include <types.h>
#pragma force_active on

struct Elem {
    s32 unk0;
    s32 key;
};

// vtable at 0x15db8 and 0x19fd0: 3 slots; the object holds the vtable pointer at offset 0x10
class Object_vptr_10 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Elem* slot2(s32 index);
};

// vtable at 0xcf8 and 0xe24 and 0x2710 and more: 5 slots; the object holds the vtable pointer at offset 0x0
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual s32 slot4();

    u32 unk4;
    u32 unk8;
    u32 unkC;
    Object_vptr_10 m_inner;

    s32 find(s32 key) {
        if (key <= -1)
            return -1;
        s32 n = slot4();
        for (s32 i = 0; i < n; i++)
            if (key == m_inner.slot2(i)->key)
                return i;
        return -1;
    }
};

extern "C" void fn_27_FE140(s16* dest, s16* src);

extern "C" void fn_27_1CE660(s16* out, Object_vptr_0* self, s32 key) {
    s32 idx = self->find(key);
    if (idx < 0) {
        *out = 0;
    } else {
        fn_27_FE140(out, (s16*)self->m_inner.slot2(idx));
    }
}