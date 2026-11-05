#pragma force_active on

struct Vec4 {
    float x, y, z, w;
};

class Base {
public:
    virtual void m08();
    virtual void m0c();
    virtual void m10();
    virtual void m14();
    virtual void m18();
    virtual void m1c();
    virtual void m20();
    virtual void m24();
    virtual void m28();
    virtual void m2c();
    virtual void m30();
    virtual void m34();
    virtual void m38();
    virtual void m3c();
    virtual void m40();
    virtual void m44();
    virtual void m48();
    virtual void m4c();
    virtual void m50();
    virtual void m54(Vec4* v);
};

extern "C" void fn_802E5198(Base* self, const Vec4* v, float s) {
    __attribute__((aligned(16))) Vec4 out;
    out.x = s * v->x;
    out.y = s * v->y;
    out.z = s * v->z;
    out.w = s * v->w;
    self->m54(&out);
}
