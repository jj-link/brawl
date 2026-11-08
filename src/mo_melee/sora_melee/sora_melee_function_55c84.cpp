#pragma force_active on
struct Vec3f { float x,y,z; };
struct Pair { int x,y; };
struct Input { Pair xy; int z; };
struct Matrix { float m[3][4]; };
struct Model {
    int pad[2];
#define S(n) virtual void slot##n();
    S(0) S(1) S(2) S(3) S(4) S(5) S(6) S(7)
    S(8) S(9) S(10) S(11) S(12) S(13) S(14) S(15)
    S(16) S(17) S(18) S(19) S(20) S(21) S(22) S(23)
    S(24) S(25) S(26) S(27) S(28) S(29) S(30) S(31)
    S(32) S(33) S(34) S(35)
    virtual Vec3f get(int, int);
    virtual Vec3f transform(int, const Input&, int, int);
    S(38) S(39)
    virtual void matrix(int, Matrix*, int);
#undef S
};
struct Object_vptr_30_base { char pad[0x30]; };
class Object_vptr_30 : public Object_vptr_30_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(Vec3f*, Vec3f*, Matrix*);
};
extern float lbl_27_rodata_550;
extern "C" void fn_27_55C84(Model* obj, Object_vptr_30* scene, int mode, int id, Input* a, Input* b) {
    Matrix mat;
    Vec3f p, q;
    Input in_a, in_b;
    if (a) { in_a = *a; p = obj->transform(id, in_a, 0, 0); }
    else p = obj->get(id, 0);
    switch (mode) {
    case 1:
        if (b) { in_b = *b; q = obj->transform(id, in_b, 0, 0); }
        else q = obj->get(id, 0);
        obj->matrix(id, &mat, 0);
        scene->slot3(&p, &q, &mat);
        break;
    case 0:
        q.z = lbl_27_rodata_550;
        q.y = lbl_27_rodata_550;
        q.x = lbl_27_rodata_550;
        scene->slot3(&p, &q, 0);
        break;
    }
}