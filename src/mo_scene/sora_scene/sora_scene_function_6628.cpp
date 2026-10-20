#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

struct Task {
    char padding[0x3c];
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void init();
};

extern "C" Task* fn_2_0(Task*);

struct Scene {
    char padding[8];
    int state;
    Task* task;
};

extern "C" void fn_1_6628(Scene* scene) {
    scene->state = 0;
    Task* task = (Task*)__nw__FUlQ25Heaps8HeapType(0x650, 0x2a);
    if (task) {
        task = fn_2_0(task);
    }
    task->init();
    scene->task = task;
}
