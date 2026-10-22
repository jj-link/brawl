#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" void fn_8019DA5C(void* self, u32 mask, s32 flag);

struct Sub {
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
    virtual void v11();
    virtual void v12();
};

struct Obj {
    u8 pad0[0x10];
    s32 m_count10;
    u16* m_arr14;
    s32 m_count18;
    Sub** m_list1c;
};

extern "C" void fn_8019A47C(Obj* self) {
    for (s32 i = 0; i < self->m_count18; i++) {
        Sub* s = self->m_list1c[i];
        if (s != 0) {
            s->v11();
        }
    }
    s32 i = 0;
    s32 off = 0;
    while (i < self->m_count10) {
        i++;
        *(u16*)((u8*)self->m_arr14 + off) = 0x8000;
        off += 2;
    }
    fn_8019DA5C(self, 4, 0);
}
