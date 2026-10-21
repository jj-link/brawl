#pragma force_active on
class Dispatch {
public:
    virtual void first();
    virtual void second();
};

struct Object {
    unsigned char padding[0x10];
    Dispatch dispatch;
};

extern "C" void fn_27_FB1A0(Object* object) {
    object->dispatch.second();
}
