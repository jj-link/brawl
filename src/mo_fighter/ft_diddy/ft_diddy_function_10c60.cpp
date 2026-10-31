#pragma force_active on
class Module {
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
    virtual void action(int);
};
struct Accesser { char pad[0x3c]; Module* module; };
struct Owner { char pad[0xd8]; Accesser* accesser; };
extern "C" void fn_115_10C60(void*, Owner* owner, int kind) {
    switch (kind) {
    case 0x11f:
    case 0x121:
        break;
    case 0x120:
    default:
        owner->accesser->module->action(0);
    }
}
