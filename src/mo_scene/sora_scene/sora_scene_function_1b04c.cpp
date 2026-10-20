#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct Task {
    char pad[0x3C];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void init();
};

extern "C" Task* fn_800ED474(void*);

struct Scene {
    char pad[8];
    Task* task;
};

extern "C" void fn_1_1B04C(Scene* scene) {
    Task* task = (Task*)__nw__FUlQ25Heaps8HeapType(0x27C, 0x2A);
    if (task) {
        task = fn_800ED474(task);
    }
    task->init();
    scene->task = task;
}
