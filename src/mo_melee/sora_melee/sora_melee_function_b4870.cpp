#pragma force_active on
struct Vec3f {
    float x, y, z;
};

class PositionModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f getPosition();
};

struct ModuleAccessor {
    char pad[0x0C];
    PositionModule* position;
};

struct Owner {
    char pad[0xD8];
    ModuleAccessor* modules;
};

struct Object {
    char pad[0x10];
    Owner* owner;
    unsigned char enabled : 1;
    unsigned char active : 1;
    unsigned char reserved : 6;
};

extern "C" void cmReqQuake__FiP5Vec3f(int, const Vec3f*);

extern "C" void fn_27_B4870(Object* self) {
    if (self->enabled && self->active == 1) {
        const Vec3f& position = self->owner->modules->position->getPosition();
        cmReqQuake__FiP5Vec3f(1, &position);
    }
}
