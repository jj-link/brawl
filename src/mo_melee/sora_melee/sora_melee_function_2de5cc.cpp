#pragma force_active on
extern "C" int fn_27_1922CC(void* accesser, unsigned long value);

class Obj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long id);
    virtual void slot5(int value, unsigned long id);
};

struct Mid {
    char pad[0x64];
    Obj* obj;
};

struct Outer {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_2DE5CC(void* unused, Outer* p) {
    Obj* obj = p->mid->obj;
    int limit = fn_27_1922CC(p, 0x5dc0);
    int n = obj->slot4(0x10000040);
    if (n > limit) {
        n = limit;
    }
    obj->slot5(n * fn_27_1922CC(p, 0x5dc1), 0x20000003);
}
