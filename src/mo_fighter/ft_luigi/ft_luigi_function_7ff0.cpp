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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void target(u32 arg);
};

extern "C" {
void fn_27_131CD0(void* self, int flag);
}

extern "C" void fn_99_7FF0(void* self, int flag) {
    fn_27_131CD0(self, flag);
    if (flag != 2) {
        u8* p = reinterpret_cast<u8*>(self);
        void* a = *reinterpret_cast<void**>(p + 0x60);
        void* b = *reinterpret_cast<void**>(reinterpret_cast<u8*>(a) + 0xd8);
        void* c = *reinterpret_cast<void**>(reinterpret_cast<u8*>(b) + 0x64);
        reinterpret_cast<VBase*>(c)->target(0x1200003D);
    }
}
