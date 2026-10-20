#pragma force_active on
typedef unsigned int u32;

class Sub {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
};

struct Mid {
    char pad[0x14];
    Sub* sub;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

struct Self {
    char pad[0x308];
    u32 flags;
};

extern "C" bool fn_27_2BA2E8(Self* self, Obj* obj) {
    if (obj->mid->sub->f3() == 0 || (self->flags & 1) != 0) {
        return true;
    }
    return false;
}
