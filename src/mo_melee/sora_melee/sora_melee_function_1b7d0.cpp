#include <types.h>
#pragma force_active on

struct Tag {
    s16 value;
    s16 pad;

    Tag(s16 v) : value(v) {}
};

class IfaceA {
public:
    virtual s32 v0(void*, s32*, s32, Tag*, s32);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(s32);
};

class IfaceC {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(Tag*, void*);
};

struct Mid {
    u8 pad[0x6C];
    IfaceC* m_ifc;
};

struct Arg1 {
    u8 pad[0xD8];
    Mid* m_mid;
};

struct Self {
    u8 pad[0xF0];
    IfaceA* m_obj;
    u8 pad2[0x165 - 0xF4];
    u8 flags;
};

extern "C" s32 fn_27_1B7D0(Self* self, Arg1* arg1) {
    s32 sp10 = -1;
    Tag spC(0);
    bool result = self->m_obj->v0(arg1, &sp10, -1, &spC, 0) == 1;

    if (result) {
        Tag sp8(1);
        arg1->m_mid->m_ifc->v11(&sp8, arg1);
        self->flags |= 2;
        self->m_obj->v11(-1);
        return 1;
    }

    return 0;
}
