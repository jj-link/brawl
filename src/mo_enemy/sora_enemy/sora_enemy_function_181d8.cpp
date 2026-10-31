#include <mt/mt_matrix.h>

#pragma force_active on

struct Model {
    char pad[8];
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual void dummy32();
    virtual void dummy33();
    virtual void dummy34();
    virtual void dummy35();
    virtual void dummy36();
    virtual void dummy37();
    virtual void dummy38();
    virtual void dummy39();
    virtual void matrix(int, Matrix*, int);
};

struct Modules {
    void* pad;
    Model* model;
    void* pad8;
    void* padC;
};

struct Accesser {
    char pad[8];
    void* stage;
    char padC[0xCC];
    Modules* modules;
};

extern "C" {
    extern float lbl_41_rodata_C38[];
    Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
    void fn_41_534C(Vec3f*, const Vec3f*);
    void fn_8003E3BC(Matrix*, Vec3f*, Vec3f*);
    float fn_8003DF9C(const Vec3f*, const Vec3f*);
}

struct Frame {
    Vec3f t6;
    Vec3f t5;
    Vec3f t4;
    Vec3f t3;
    Vec3f t2;
    Vec3f t1;
    Vec3f axis;
    Vec3f dir;
    Matrix matrix;

    Frame() : matrix(true) {}
};

extern "C" int fn_41_181D8(Accesser* acc, float threshold, int bone, int type) {
    float* data = lbl_41_rodata_C38;
    Frame f;
    float val = threshold;

    acc->modules->model->matrix(bone, &f.matrix, 0);
    fn_41_5AC4(&f.dir, data[1], data[1], data[1]);

    switch (type) {
    case 0x8BCB:
        fn_41_534C(&f.dir, fn_41_5AC4(&f.t1, data[4], data[1], data[1]));
        break;
    case 0x8BCA:
        fn_41_534C(&f.dir, fn_41_5AC4(&f.t2, data[1], data[4], data[1]));
        break;
    case 0x8BC9:
        fn_41_534C(&f.dir, fn_41_5AC4(&f.t3, data[1], data[1], data[4]));
        break;
    case 0x8BC8:
        fn_41_534C(&f.dir, fn_41_5AC4(&f.t4, data[0], data[1], data[1]));
        break;
    case 0x8BC7:
        fn_41_534C(&f.dir, fn_41_5AC4(&f.t5, data[1], data[0], data[1]));
        break;
    case 0x8BC6:
        fn_41_534C(&f.dir, fn_41_5AC4(&f.t6, data[1], data[1], data[0]));
        break;
    }

    fn_8003E3BC(&f.matrix, &f.dir, &f.dir);
    fn_41_5AC4(&f.axis, data[1], data[4], data[1]);

    return fn_8003DF9C(&f.axis, &f.dir) * data[2] <= val;
}
