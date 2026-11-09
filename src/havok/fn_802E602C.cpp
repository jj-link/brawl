#pragma force_active on

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

class Base {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(Vec4*);
};

extern "C" void fn_802E602C(Base* self, const Vec4* data, float scale) {
    __attribute__((aligned(16))) Vec4 out;
    out.x = scale * data->x;
    out.y = scale * data->y;
    out.z = scale * data->z;
    out.w = scale * data->w;
    self->v19(&out);
}
