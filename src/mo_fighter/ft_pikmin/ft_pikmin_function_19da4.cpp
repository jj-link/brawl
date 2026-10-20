#pragma force_active on
class WM {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(int id);
    virtual void setFloat(float value, int id);
};

struct Ptr {
    unsigned char prefix[0x64];
    WM* wm;
};

struct Mid {
    unsigned char prefix[0xd8];
    Ptr* ptr;
};

struct Obj {
    unsigned char prefix[0x60];
    Mid* mid;
};

extern "C" void fn_113_19DA4(Obj* self, float damage) {
    if (self->mid->ptr->wm->getFloat(0x11000001) < damage) {
        self->mid->ptr->wm->setFloat(damage, 0x11000001);
    }
}
