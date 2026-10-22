#include <types.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern "C" s8 lbl_8059DF40;
extern "C" char lbl_80455D8C[];

struct TBase {
    char pad0[0x2C];
    u8 unk2C;
    char pad2D[0xF];
};

struct TTask : public TBase {
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
};

extern "C" TTask* fn_800B08A8(int arg0) {
    TTask* task = (TTask*)__nw__FUlQ25Heaps8HeapType(0x48, arg0);
    if (task) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(task, (const char*)&lbl_8059DF40, 8, 0xF, 8, true);
        *(char**)((char*)task + 0x3C) = lbl_80455D8C;
        task->unk2C &= ~2;
    }
    task->v21();
    return task;
}
