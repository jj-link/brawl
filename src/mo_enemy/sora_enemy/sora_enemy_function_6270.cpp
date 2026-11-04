#pragma force_active on
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>

class Source {
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
    virtual Vec3f v14(int);
};

struct Holder {
    char pad[0xc];
    Source* source;
};

struct Enemy {
    char pad[0x1b4];
    Holder* holder;
};

extern "C" {
    void fn_41_6168(Vec3f*);
    void fn_41_534C(Vec3f*, const Vec3f*);
    void fn_41_6354(Vec3f*, float);
    void fn_8003ECA0(Matrix*, float, float, float);
    void fn_8003EA50(Matrix*, const Vec3f*);
    void* __memcpy(void*, const void*, unsigned long);
}

extern float lbl_41_rodata_34;
extern float lbl_41_rodata_38;

extern "C" void fn_41_6270(Vec3f* out, Enemy* enemy) {
    Matrix m(true);
    Vec3f a;
    Source* src = enemy->holder->source;
    fn_41_6168(&a);
    Vec3f b = src->v14(0);
    Vec3f c;
    Vec3f d;
    Vec3f e;
    fn_41_534C(&d, &b);
    fn_41_6354(&d, lbl_41_rodata_34);
    fn_8003ECA0(&m, d.m_x, d.m_y, d.m_z);
    fn_41_534C(&e, &a);
    fn_41_6354(&e, lbl_41_rodata_34);
    fn_8003EA50(&m, &e);
    m.getRotate(&c);
    __memcpy(out, &c, sizeof(Vec3f));
    fn_41_6354(out, lbl_41_rodata_38);
}
