#pragma force_active on
class Dispatch {
public:
    virtual void unused();
    virtual int target();
};

struct Object {
    char padding[16];
    Dispatch dispatch;
};

extern "C" int fn_27_F9DD8(Object* object) {
    return object->dispatch.target();
}
