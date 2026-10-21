#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Obj {
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
    virtual void f34(void*, void*);
    virtual void v12();
    virtual void f3c(void*);

    char pad[0xE0];
    void* fieldE4;
};

struct Arg {
    Obj* object;
    void* data;
    void* model;
};

extern "C" void fn_800B6838(void*, const Vec3f*);
extern "C" void fn_800B753C(void*, float);
extern "C" void setUpdateRate__16gfModelAnimationFf(void*, float);

extern float lbl_10_rodata_884;
extern float lbl_10_rodata_870;

extern "C" void fn_10_1C330(Arg* arg) {
    void* model = arg->model;

    arg->object->f3c(*(void**)((char*)model + 0x10));
    arg->object->f34(
        arg->object->fieldE4, *(void**)((char*)model + 0x10));

    char* data = (char*)arg->data;
    Vec3f position;
    position.x = *(float*)(data + 0x3C);
    position.y = *(float*)(data + 0x40);
    position.z = *(float*)(data + 0x44);

    fn_800B6838(model, &position);
    fn_800B753C(model, lbl_10_rodata_884);
    setUpdateRate__16gfModelAnimationFf(
        *(void**)((char*)model + 0x14), lbl_10_rodata_870);
}
