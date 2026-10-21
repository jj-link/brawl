#pragma force_active on
struct Result {
    float x, y, z;
};

class Dispatch {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Result target();
};

struct Object {
    unsigned char padding[0xDB4];
    Dispatch dispatch;
};

extern "C" Result fn_27_290060(Object* object) {
    return object->dispatch.target();
}
