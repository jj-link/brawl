#include <types.h>
#pragma force_active on

struct Base8 {
    u32 m_a;
    u32 m_b;
};

// Local view of the work-object vtable; only slot layout matters here.
// The vtable pointer sits at offset 0x8 (after the 8-byte non-polymorphic
// base), and the check/clear pair must land at 0x60 / 0x58.
class Work : public Base8 {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual u32 offFlag(u32 flag, u32 index);
    virtual void clearFlag(u32 index);
    virtual u32 isFlag(u32 flag, u32 index);
};

extern "C" u32 fn_120_9988(Work* work, u32 flag, u32 index) {
    u32 result = work->isFlag(flag, index);
    if (result == 1) {
        work->offFlag(flag, index);
    }
    return result;
}
