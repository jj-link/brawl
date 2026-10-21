#pragma force_active on

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Owner {
    char pad[60];
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
    virtual int get();
};

struct Model {
    char pad[8];
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
    virtual Vec get(int);
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void set(int, const Vec&);
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float get();
};

struct Modules {
    char pad[4];
    Model* model;
    char pad8[4];
    Posture* posture;
};

struct Obj {
    char pad[8];
    Owner* owner;
    char padC[0xcc];
    Modules* modules;
};

extern "C" const float lbl_27_rodata_8080[];
extern "C" char lbl_27_bss_8C2C[];
extern "C" void fn_27_3C2CD4(void*);
extern "C" void fn_27_89DAC(int, Obj*);

extern "C" void fn_27_3C2ED4(void*, Obj* o) {
    const float* data = lbl_27_rodata_8080;
    fn_27_3C2CD4(lbl_27_bss_8C2C);

    int n;
    if (o->owner->get() == 5)
        n = 0x197;
    else
        n = 4;

    Vec b = o->modules->model->get(n);
    if (data[3] == o->modules->posture->get())
        b.y = data[4];
    else
        b.y = data[1];

    o->modules->model->set(n, b);
    fn_27_89DAC(2, o);
    fn_27_89DAC(0, o);
}
