#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
};

class Visitor {
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
    virtual void v10(void** p);
};

extern "C" {
void fn_27_2BB86C(void* arg0, Visitor* visitor) {
    char* base = (char*)arg0;
    char* elem;
    void* sp8;
    s32 idx = (s32)(((s32)(*(s32*)(base + 0x14) << 5)) & 0xFC000000) >> 27;
    while (idx >= 0) {
        if (idx >= 0) {
            ((Inner*)(base + 0x10))->m13();
        }
        elem = base + idx * 0x14;
        sp8 = (void*)(elem + 0x1C);
        visitor->v10(&sp8);
        if (idx >= 0) {
            ((Inner*)(base + 0x10))->m13();
        }
        idx = (s8)(*(s8*)(elem + 0x29));
    }
}
}
