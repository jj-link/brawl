#pragma force_active on
class FlagArray {
public:
    virtual void unused();
    virtual unsigned int& at(int index);
};

struct Work {
    char padding[0x28];
    FlagArray flags;
};

extern "C" void fn_27_417E4(Work* work, unsigned int bit) {
    unsigned int& flag = work->flags.at(1);
    flag = 1U << bit;
}
