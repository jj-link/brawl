#pragma force_active on

class Item {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void process(int) = 0;
    char pad[0xE4 - 0x04];
    int count;
};

class Mgr {
public:
    virtual void vf00() = 0;
    virtual void vf01() = 0;
    virtual void vf02() = 0;
    virtual void vf03() = 0;
    virtual void vf04() = 0;
    virtual void vf05() = 0;
    virtual void vf06() = 0;
    virtual void vf07() = 0;
    virtual void vf08() = 0;
    virtual void vf09() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12() = 0;
    virtual void finish(Item*) = 0;
};

struct Self {
    char _000[0x8];
    Mgr* f8;
    char _00C[0x15C - 0x0C];
    Item* f15C;
};

extern "C" void fn_800DF430(Self* self) {
    Item* it;
    int n;

    it = self->f15C;
    while (n = it->count) {
        if (n == 0) continue;
        it->process(n - 1);
    }
    self->f8->finish(it);
}
