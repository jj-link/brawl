#pragma force_active on
extern "C" struct Vec3 {
    float x, y, z;
};

class PositionAccessor {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void getPosition();
    virtual Vec3 position();
};

struct PositionHolder {
    char pad[0xC];
    PositionAccessor* position;
};

struct ModuleAccessor {
    char pad[0xD8];
    PositionHolder* holder;
};

struct ObjectAccessor {
    char pad[0x60];
    ModuleAccessor* modules;
};

extern "C" Vec3 fn_27_8CA78(void* object) {
    return static_cast<ObjectAccessor*>(object)->modules->holder->position->position();
}
