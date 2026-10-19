#pragma force_active on
typedef unsigned short u16;

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void fn_80014ED4(void*, const char*, int, int);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
extern void* lbl_1_bss_48;
extern char lbl_1_data_1D7C[];
}

struct Param {
    int a, b, c, d, e, f, g;
};

struct TaskBase {
    char pad[0x3C];
};

struct Task : TaskBase {
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
    virtual void init();
};

struct Scene {
    char pad[8];
    Task* task;
};

extern "C" Task* fn_5_0(void*, void*, Param*, int);

extern "C" void fn_1_8388(Scene* self) {
    void* archive = __nw__FUlQ25Heaps8HeapType(0x80, 0x2B);
    if (archive)
        archive = __ct__9gfArchiveFv(archive);

    lbl_1_bss_48 = archive;
    fn_80014ED4(archive, lbl_1_data_1D7C, 0x2B, 0);
    getData__9gfArchiveF11ARCNodeTypeiUs(lbl_1_bss_48, 2, 10, 0xFFFE);

    Param param;
    param.a = 2;
    param.b = 2;
    param.c = 0;
    param.d = 0;
    param.e = 0;
    param.f = 0;
    param.g = 0x4917;

    void* arc = lbl_1_bss_48;
    Task* task = (Task*)__nw__FUlQ25Heaps8HeapType(0xC478C, 0x2A);
    if (task)
        task = fn_5_0(task, arc, &param, 0);

    task->init();
    self->task = task;
}
