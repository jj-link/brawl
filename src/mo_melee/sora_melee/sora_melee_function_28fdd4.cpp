#pragma force_active on
class Target {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void call();
};

struct Modules {
    unsigned char padding[0xC8];
    Target* target;
};

struct Object {
    unsigned char padding[0x1A4];
    Modules* modules;
};

extern "C" void fn_27_28FDD4(Object* object) {
    object->modules->target->call();
}
