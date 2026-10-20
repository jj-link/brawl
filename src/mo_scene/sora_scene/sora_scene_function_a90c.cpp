#pragma force_active on
extern "C" void fn_80056B70(void*);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_2_36DB4(void*);

struct Task {
    char pad[0x3C];
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void init();
};

struct Scene {
    char pad[8];
    Task* task;
};

extern "C" void fn_1_A90C(Scene* self) {
    fn_80056B70(self);
    Task* task = (Task*)__nw__FUlQ25Heaps8HeapType(0x284C, 0x2A);
    if (task) {
        task = (Task*)fn_2_36DB4(task);
    }
    task->init();
    self->task = task;
}
