#pragma force_active on

struct Module {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void reset(int);
};
struct Accesser { char pad[0x3c]; Module* module; };
struct Fighter { char pad[0xd8]; Accesser* accesser; };
extern "C" void fn_109_C30C(void*, Fighter* fighter, int kind) {
    switch (kind) {
    case 0x3b:
    case 0x11d:
        break;
    default:
        fighter->accesser->module->reset(0);
        break;
    }
}
