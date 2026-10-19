#include <types.h>
#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

class IObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 v4();
};

struct Mid {
    u8 pad[0xc];
    IObj* obj;
};

struct Top {
    u8 pad[0x180];
    Mid* mid;
};

extern "C" {
float fn_27_263634(Top* t) {
    return t->mid->obj->v4().x;
}
}
