#pragma force_active on
typedef unsigned int u32;

struct Flag {
    u32 unused;
    u32 flag;
};

class FlagArray {
public:
    virtual void unused();
    virtual Flag& at(u32 index);
};

struct Work {
    unsigned char padding[0x28];
    FlagArray flags;
};

extern "C" void fn_27_41770(Work* work, u32 flag, u32 enabled) {
    if (enabled == 1) {
        work->flags.at(0).flag |= flag;
    } else {
        work->flags.at(0).flag &= ~flag;
    }
}
