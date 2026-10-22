#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_25D0;
extern const float lbl_27_rodata_25D4;
extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned int, unsigned int);

class Inner {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(float*, int, float);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(float);
};

struct Mid {
    char pad[0xC];
    Inner* inner;
};

struct Data {
    char pad[0xD8];
    Mid* mid;
};

extern "C" void fn_27_18D96C(void* a, void* arg) {
    float v[3];
    v[0] = lbl_27_rodata_25D0;
    v[1] = lbl_27_rodata_25D4;
    v[2] = lbl_27_rodata_25D0;
    ((*(Data*)arg).mid->inner)->v15(v, 0, lbl_27_rodata_25D0);
    Inner* in = ((*(Data*)arg).mid->inner);
    float c = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg, 0xBE3, 0);
    in->v23(c);
}
