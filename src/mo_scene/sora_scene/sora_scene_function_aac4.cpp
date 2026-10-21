#pragma force_active on
typedef unsigned char u8;
typedef int s32;
extern "C" void fn_8004DDEC(s32);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_4_0(void*, int);
extern "C" void* getInstance__14gfSceneManagerFv();
extern "C" s32 g_GameGlobal;

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

extern "C" void fn_1_AAC4(Scene* self) {
    u8* mgr = (u8*)getInstance__14gfSceneManagerFv();
    Task* task;
    if (*(s32*)(mgr + 0x280) == 0) {
        fn_8004DDEC(g_GameGlobal);
        task = (Task*)__nw__FUlQ25Heaps8HeapType(0x3D8, 0x2A);
        if (task) {
            task = (Task*)fn_4_0(task, 1);
        }
        task->init();
        self->task = task;
        return;
    }
    task = (Task*)__nw__FUlQ25Heaps8HeapType(0x3D8, 0x2A);
    if (task) {
        task = (Task*)fn_4_0(task, 0);
    }
    task->init();
    self->task = task;
}
