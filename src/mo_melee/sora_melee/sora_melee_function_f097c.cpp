#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void target();
};

struct Object {
    unsigned char padding[0x10];
    Interface interface;
};

extern "C" void fn_27_F097C(Object* object) {
    object->interface.target();
}
