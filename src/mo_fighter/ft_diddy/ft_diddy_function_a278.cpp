#include <types.h>
#pragma force_active on

// Turn off a work flag, returning whether it was previously set.

class Work {
    char pad[8];

public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void offFlag(u32 flag, u32 index);
    virtual void d23();
    virtual bool isFlag(u32 flag, u32 index) const;
};

extern "C" u32 fn_115_A278(Work* work, u32 flag, u32 index) {
    u32 result = work->isFlag(flag, index);
    if (result == 1) {
        work->offFlag(flag, index);
    }
    return result;
}
