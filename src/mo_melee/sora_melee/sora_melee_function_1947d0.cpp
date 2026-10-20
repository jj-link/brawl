#include <types.h>
#pragma force_active on

class Pad {
    u8 m_pad[0x3c];
};

struct SomeType {
};

struct SomeResult {
    u32 m_0 : 28;
    u32 m_1 : 1;
    u32 m_2 : 3;
};

class Obj {
    Pad m_base;

public:
    virtual int d0();
    virtual int d1();
    virtual int d2();
    virtual int d3();
    virtual int d4();
    virtual int d5();
    virtual int d6();
    virtual int d7();
    virtual int d8();
    virtual int d9();
    virtual int d10();
    virtual int d11();
    virtual int d12();
    virtual int d13();
    virtual int d14();
    virtual int d15();
    virtual int d16();
    virtual int d17();
    virtual int d18();
    virtual int d19();
    virtual int d20();
    virtual int d21();
    virtual int d22();
    virtual int d23();
    virtual int d24();
    virtual int d25();
    virtual int d26();
    virtual int d27();
    virtual int d28();
    virtual int d29();
    virtual int d30();
    virtual int d31();
    virtual int d32();
    virtual int d33();
    virtual int d34();
    virtual int d35();
    virtual int d36();
    virtual int d37();
    virtual int d38();
    virtual int d39();
    virtual SomeType* method();
};

extern "C" {
extern u8 g_ftCommonDataAccesser[];
extern SomeResult* fn_27_14554C(void* this_, SomeType* a, void* b);
}

extern "C" u32 fn_27_1947D0(void* a1, void* a2) {
    Obj* x = *(Obj**)((void**)a1 + 2);
    SomeType* y = x->method();
    SomeResult* z = fn_27_14554C(g_ftCommonDataAccesser, y, a2);
    return z->m_1;
}
