#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_60D4();

class Pad {
public:
    int a;
    int b;
};

class Handler : public Pad {
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
    virtual void v11();
    virtual void v12(void* self);
};

extern "C" {
void fn_27_2894A0(void* self) {
    char* p = static_cast<char*>(self);
    fn_27_60D4();
    if (*(u8*)(p + 0x3d25) != 0) {
        int n = *(u8*)(p + 0x3d24) + 1;
        *(u8*)(p + 0x3d24) = (u8)n;
        if ((u8)n > 2) {
            *(u8*)(p + 0x3d24) = 0;
        }
        *(u8*)(p + 0x3d25) = 0;
    }
    Handler* h = *reinterpret_cast<Handler**>(p + 0x8d0);
    h->v12(self);
}
}
