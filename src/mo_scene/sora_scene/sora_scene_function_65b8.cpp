#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" char lbl_1_data_15C8[];
extern "C" char lbl_1_data_1564[];

struct Scene {
    const char* name;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void init();
    unsigned int unknown[2];
};

struct SceneLayout {
    const char* name;
    void* vtable;
    unsigned int unknown[2];
};

extern "C" Scene* fn_1_65B8() {
    SceneLayout* scene =
        (SceneLayout*)__nw__FUlQ25Heaps8HeapType(0x10, 0x2E);

    if (scene) {
        scene->name = lbl_1_data_15C8;
        scene->vtable = lbl_1_data_1564;
    }

    ((Scene*)scene)->init();
    return (Scene*)scene;
}
