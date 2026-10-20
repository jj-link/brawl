#pragma force_active on

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Matrix { float m[12]; };

struct Stage {
    char pad[0x3C];
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
    virtual void dummy40();
    virtual void dummy41();
    virtual void dummy42();
    virtual void call();
};

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

struct Posture {
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
    virtual float value();
};

struct Modules {
    void* pad;
    Model* model;
    void* pad8;
    Posture* posture;
};

struct Accesser {
    char pad[8];
    Stage* stage;
    char padC[0xCC];
    Modules* modules;
};

extern "C" {
    extern float lbl_41_rodata_C90[];
    Vec3* fn_41_5AC4(Vec3*, float, float, float);
    void fn_41_534C(Vec3*, const Vec3*);
    void getRotate__6MatrixFP5Vec3f(Matrix*, Vec3*);
    void fn_8003E3BC(Matrix*, Vec3*, Vec3*);
    Vec2* fn_41_2354(Vec2*, float, float);
    float fn_41_10830(Vec2*);
    float fn_41_15A00(float, Vec2);
}

struct Frame {
    Vec2 vec;
    Vec3 t6, t5, t4, t3, t2, t1;
    Vec3 rotate;
    Vec3 dir;
    Matrix matrix;
};

extern "C" float fn_41_1EC18(void*, Accesser* acc, float value, int bone) {
    float* data = lbl_41_rodata_C90;
    Posture* posture = acc->modules->posture;
    Model* model = acc->modules->model;

    if ((int)value == 0x8BCE)
        return data[15];

    if ((int)value == 0x8BCB || (int)value == 0x8BCA ||
        (int)value == 0x8BC9 || (int)value == 0x8BC8 ||
        (int)value == 0x8BC7 || (int)value == 0x8BC6) {
        Frame f;
        acc->stage->call();
        model->matrix(bone, &f.matrix, 0);
        fn_41_5AC4(&f.dir, data[3], data[3], data[3]);

        if ((int)value == 0x8BCB)
            fn_41_534C(&f.dir, fn_41_5AC4(&f.t1, data[12], data[3], data[3]));
        else if ((int)value == 0x8BCA)
            fn_41_534C(&f.dir, fn_41_5AC4(&f.t2, data[3], data[12], data[3]));
        else if ((int)value == 0x8BC9)
            fn_41_534C(&f.dir, fn_41_5AC4(&f.t3, data[3], data[3], data[12]));
        else if ((int)value == 0x8BC8)
            fn_41_534C(&f.dir, fn_41_5AC4(&f.t4, data[0], data[3], data[3]));
        else if ((int)value == 0x8BC7)
            fn_41_534C(&f.dir, fn_41_5AC4(&f.t5, data[3], data[0], data[3]));
        else if ((int)value == 0x8BC6)
            fn_41_534C(&f.dir, fn_41_5AC4(&f.t6, data[3], data[3], data[0]));

        getRotate__6MatrixFP5Vec3f(&f.matrix, &f.rotate);
        fn_8003E3BC(&f.matrix, &f.dir, &f.dir);
        fn_41_2354(&f.vec, f.dir.x, f.dir.y);

        if (data[3] == fn_41_10830(&f.vec))
            return data[3];

        return fn_41_15A00(posture->value(), f.vec);
    }

    return value;
}
