#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_100_data_6294[], lbl_100_data_16D4[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_15FBC8(int);
}

class CaptainVObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* v6(int);
};

struct CaptainFlagByte {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

extern "C" void fn_100_CC94(void*, int, const void*, soModuleAccesser* accesser) {
    fn_27_15FBC8(0x13);
    CaptainVObj* obj = *(CaptainVObj**)(*(unsigned char**)((unsigned char*)accesser + 0xD8) + 0x7C);
    unsigned char* p = (unsigned char*)obj->v6(0);
    ((CaptainFlagByte*)(p + 5))->b0 = 0;
    obj = *(CaptainVObj**)(*(unsigned char**)((unsigned char*)accesser + 0xD8) + 0x7C);
    void* cur = obj->v6(1);
    unsigned char* m = (unsigned char*)__dynamic_cast(cur, 0, lbl_100_data_6294, lbl_100_data_16D4, 1);
    float f = soValueAccesser::getConstantFloat(accesser, 0xfb2, 0);
    *(float*)(m + 0x10) = -f;
}
