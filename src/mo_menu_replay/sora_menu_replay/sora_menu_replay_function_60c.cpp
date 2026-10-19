#pragma force_active on
struct Target {
    virtual void* vf0();
    virtual void* vf1();
    virtual void* vf2();
    virtual void* vf3();
    virtual void* vf4();
    virtual void* vf5();
    virtual void* vf6();
    virtual void* vf7();
    virtual void* vf8();
    virtual void* vf9();
    virtual void* vf10();
    virtual void* vf11();
    virtual void* vf12();
    virtual void* vf13();
    virtual void* vf14();
    virtual void* vf15();
};

struct Inner {
    char pad0[0x48];
    Target* target;
    char pad1[0x1a4 - 0x4c];
    unsigned char flag;
};

struct Outer {
    char pad0[0x35c];
    Inner** innerPtr;
};

struct Mid {
    char pad0[0x1d0c];
    Outer* outer;
};

struct Root {
    char pad0[0x1ac];
    Mid* mid;
};

extern "C" void* fn_7_60C(Root* root) {
    Mid* mid = root->mid;
    Outer* outer = mid->outer;
    Inner* inner = *outer->innerPtr;
    Target* target = inner->flag ? inner->target : 0;
    return target->vf13();
}
