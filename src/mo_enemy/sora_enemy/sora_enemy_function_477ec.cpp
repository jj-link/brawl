#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Matrix {
    double m[6];
};

struct StackLocals {
    Vec3f v20;
    float sc[2];
    float pad;
    Vec3f v38;
    Vec3f v44;
    Matrix matrix;
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned long);
};

struct ObjBase {
    void* pad0;
    void* pad4;
};

class Obj : public ObjBase {
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
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void f40(int, Matrix*, int);
    virtual void f42();
    virtual Vec3f f44(int, int);
};

struct Container {
    char pad0[4];
    Obj* obj;
    char pad8[4];
    soNullable* p0c;
    char pad10[0x64 - 0x10];
    soNullable* p64;
};

struct Accesser {
    char pad[0xd8];
    Container* container;
};

extern "C" {
extern float lbl_41_rodata_1018[];
extern unsigned char lbl_41_bss_504[];

Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
void fn_41_534C(Vec3f*, const Vec3f*);
void fn_41_47564(Vec3f*, int);
float fn_41_6AD8(void*, void*);
void fn_8003E3BC(Matrix*, Vec3f*, Vec3f*);
void fn_8003DE70(Vec3f*);
void mtSinCosf__FfPfPf(float, float*, float*);

void fn_41_477EC(int arg0, void* arg1, Accesser* arg2, int flag, int arg4) {
    float* rodata = lbl_41_rodata_1018;
    StackLocals locals;
    float var_f31;

    if (flag != 0) {
        arg2->container->obj->f40(arg0, &locals.matrix, 0);
        fn_41_5AC4(&locals.v38, rodata[0], rodata[0], rodata[1]);
        fn_41_47564(&locals.v20, arg4);
        fn_41_534C(&locals.v38, &locals.v20);
        const Vec3f& v14 = arg2->container->obj->f44(arg0, 0);
        fn_41_534C((Vec3f*)(lbl_41_bss_504 + 0x0c), &v14);
        fn_8003E3BC(&locals.matrix, &locals.v38, &locals.v44);
        fn_8003DE70(&locals.v44);
        float t = fn_41_6AD8((char*)arg1 + 0x38, arg2);
        *(float*)(lbl_41_bss_504 + 0x18) = locals.v44.x * t;
        *(float*)(lbl_41_bss_504 + 0x1c) = locals.v44.y * t;
        *(float*)(lbl_41_bss_504 + 0x20) = locals.v44.x * *(float*)((char*)arg1 + 0x58);
        *(float*)(lbl_41_bss_504 + 0x24) = locals.v44.y * *(float*)((char*)arg1 + 0x58);
        return;
    }

    const Vec3f& v8 = arg2->container->obj->f44(arg0, 0);
    fn_41_534C((Vec3f*)(lbl_41_bss_504 + 0x0c), &v8);
    *(float*)(lbl_41_bss_504 + 0x14) -= rodata[4];
    mtSinCosf__FfPfPf(rodata[5] * *(float*)(lbl_41_bss_504 + 0x14),
                       &locals.sc[1], &locals.sc[0]);
    float t = fn_41_6AD8((char*)arg1 + 0x38, arg2);
    *(float*)(lbl_41_bss_504 + 0x18) = locals.sc[0] * t;
    *(float*)(lbl_41_bss_504 + 0x1c) = locals.sc[1] * t;
    *(float*)(lbl_41_bss_504 + 0x20) = locals.sc[0] * *(float*)((char*)arg1 + 0x58);
    *(float*)(lbl_41_bss_504 + 0x24) = locals.sc[1] * *(float*)((char*)arg1 + 0x58);
    var_f31 = rodata[1];
    if (arg2->container->p64->slot17(0x12000003) == 0) {
        var_f31 = arg2->container->p0c->slot9();
    }
    *(float*)(lbl_41_bss_504 + 0x18) *= var_f31;
    *(float*)(lbl_41_bss_504 + 0x20) *= var_f31;
}
}
