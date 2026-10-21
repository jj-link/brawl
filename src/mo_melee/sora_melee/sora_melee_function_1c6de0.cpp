#pragma force_active on
class Interface {
public:
    virtual void first();
    virtual void second();
};

struct Object {
    char padding[16];
    Interface target;
};

extern "C" void fn_27_1C6DE0(Object* object) {
    object->target.second();
}
