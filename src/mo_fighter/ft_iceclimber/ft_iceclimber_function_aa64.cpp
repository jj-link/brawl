#include <types.h>
#pragma force_active on
extern "C" int fn_27_13ACC4(void*, void*, void*, void*);

struct PlainBase {
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    void* p6;
    void* p7;
    void* p8;
    void* p9;
    void* p10;
    void* p11;
    void* p12;
    void* p13;
    void* p14;
};

struct D : PlainBase {
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int v40();
};

extern "C" int fn_105_AA64(void* self, D* arg, void* a3, void* a4) {
    if (*reinterpret_cast<u8*>(reinterpret_cast<u8*>(self) + 0x1FE4C) == 1) {
        if (arg->v40() == 0x14) {
            return 0;
        }
    }
    return fn_27_13ACC4(self, arg, a3, a4);
}
