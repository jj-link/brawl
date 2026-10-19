#pragma force_active on
class Object {
public:
    virtual ~Object();
};

struct Owner {
    unsigned char padding[0x4C0];
    Object* object;
};

extern "C" void fn_20_8230(Owner* owner, Object* object) {
    if (owner->object) {
        delete owner->object;
    }
    owner->object = object;
}
