#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_104_data_6E28[8];
extern const char lbl_104_data_2EDC[8];
}

struct FtObj {
    virtual ~FtObj();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setA(unsigned long flag);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setB(float f, unsigned long flag);
};

struct Ctx {
    char pad[0x207c];
    char* sub;
};

inline char* getSub(char* self) {
    return ((Ctx*)__dynamic_cast(
        *(void**)(self + 0x8),
        0x3c,
        lbl_104_data_6E28,
        lbl_104_data_2EDC,
        1
    ))->sub;
}

extern "C" void fn_104_1377C(void* unused, char* self) {
    FtObj* obj = *(FtObj**)(*(char**)(self + 0xd8) + 0x64);
    obj->setA(0x20000000);
    obj->setB(*(float*)(getSub(self) + 0x2c), 0x21000000);
}
