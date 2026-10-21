#pragma force_active on

extern "C" void fn_27_1D9DF4();
extern "C" void* getInstance__16CameraControllerFv();

struct Vec2 {
    float x, y;

    Vec2() {}
    Vec2(const Vec2& other) : x(other.x), y(other.y) {}
};

class PositionModule {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Vec2 getPosition();
    virtual void setPosition(const Vec2&);
};

inline PositionModule* getModule(unsigned char* self) {
    return *(PositionModule**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xd8) + 0xc);
}

extern "C" void fn_123_16E28(unsigned char* self) {
    fn_27_1D9DF4();

    PositionModule* c = getModule(self);
    Vec2 v = c->getPosition();

    unsigned char* cam = (unsigned char*)getInstance__16CameraControllerFv();
    if (cam != 0) {
        float x = v.x;
        if (x < *(float*)(cam + 0x158)) {
            v.x = *(float*)(cam + 0x158);
        } else if (x > *(float*)(cam + 0x15c)) {
            v.x = *(float*)(cam + 0x15c);
        }

        float y = v.y;
        if (y < *(float*)(cam + 0x164)) {
            v.y = *(float*)(cam + 0x164);
        } else if (y > *(float*)(cam + 0x160)) {
            v.y = *(float*)(cam + 0x160);
        }
    }

    PositionModule* d = *(PositionModule**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xd8) + 0xc);
    d->setPosition(v);
}
