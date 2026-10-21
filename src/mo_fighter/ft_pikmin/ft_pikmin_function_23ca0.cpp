#pragma force_active on
struct Vec2f {
    float x;
    float y;
    Vec2f() {}
    Vec2f(const Vec2f& o) : x(o.x), y(o.y) {}
};

struct Getter {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual float getFloat(unsigned int id);
};

struct Vec3f {
    float x, y, z;
    Vec3f() {}
    Vec3f(const Vec3f& o) : x(o.x), y(o.y), z(o.z) {}
};

struct Vec2Src {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual Vec3f getVec();
};

struct Mod {
    unsigned char pad[0xC];
    Vec2Src* vec;
    unsigned char pad2[0x64 - 0x10];
    Getter* getter;
};

struct Self {
    unsigned char pad[0xD8];
    Mod* mod;
};

extern "C" void fn_113_23E44(Vec2f* p, void* q, int flags);
extern "C" void* fn_113_B7F0(Vec2f* dst, const Vec3f* src);

extern "C" void fn_113_23CA0(Self* self, int arg1) {
    float f31 = self->mod->getter->getFloat(0x11000005);
    Vec2f sp10;
    sp10.x = self->mod->getter->getFloat(0x11000004);
    sp10.y = f31;
    Vec3f sp18 = self->mod->vec->getVec();
    Vec2f sp8;
    void* r = fn_113_B7F0(&sp8, &sp18);
    fn_113_23E44(&sp10, r, arg1);
}
