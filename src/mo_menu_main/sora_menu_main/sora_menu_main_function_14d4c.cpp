#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct VBase {
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
    virtual void v13(void* arg);
};

extern "C" void fn_2_14D4C(u8* self) {
    u32 off = 0;
    for (u32 i = 0; i < 7; i++) {
        VBase* obj = *(VBase**)(self + 0x654);
        u8* base = *(u8**)(self + 0x64c);
        u32 q = *(u32*)(base + off + 0x74);
        u32 arg = *(u32*)(q + 0x10);
        obj->v13((void*)arg);
        off += 4;
    }
}
