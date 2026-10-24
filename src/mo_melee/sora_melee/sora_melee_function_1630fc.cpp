#pragma force_active on

struct Vec2f {
    float x, y;
    void set(float a, float b) {
        x = a;
        y = b;
    }
};

struct Vec3f {
    float x, y, z;
};

struct R {
    char pad[0xC];
    float f0;
    float f1;
    char pad2[0x45 - 0x14];
    unsigned char flags;
};

struct Base {
    char pad[8];
};

struct Q : Base {
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
    virtual R* get();
};

struct P {
    char pad[0x38];
    Q* q;
};

struct Acc {
    char pad[0xD8];
    P* p;
};

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, void*, int, void*, void*, float, float);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
}

extern "C" void fn_27_1630FC(
    void* a1, unsigned char* obj, unsigned long a3, Acc* acc) {
    Vec2f v2b;
    Vec2f v2a;
    Vec3f v3a;
    Vec3f v3b;

    v3a.x = lbl_27_rodata_1FC0;
    v3a.y = lbl_27_rodata_1FC0;
    v3a.z = lbl_27_rodata_1FC0;
    v2a.x = lbl_27_rodata_1FC0;
    v2a.y = lbl_27_rodata_1FC0;

    ((void (*)(int, void*, int, void*, void*))fn_27_89D08)(
        1, acc, 0, &v2a, &v3a);

    R* r = acc->p->q->get();
    v2b.set(r->f0, r->f1);

    float f30 =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            acc, 3289, 0);
    float f31 =
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            acc, 3023, 0);
    float f2 = f31 -
        getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            acc, 3288, 0);

    v3b.x = lbl_27_rodata_1FC0;
    v3b.y = lbl_27_rodata_1FC0;
    v3b.z = lbl_27_rodata_1FC0;

    float prod = f30 * f2;
    float old = v2b.y;
    v2b.y = old + prod;
    fn_27_89D08(4, acc, 2, &v2b, &v3b, old, prod);

    if ((r->flags >> 1) & 1) {
        obj[0x178] = 1;
    }
}
