#include <types.h>
#pragma force_active on

extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void* sched, int cat, u32 id);

struct EmVObj {
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
    virtual void callOp(u32 id);
};

extern "C" void fn_41_A7D4(u8* self, u8* em)
{
    u32 taskId = *(u32*)(em + 0xC);
    if (taskId != 0xFFFFFFFF) {
        void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(
            getInstance__15gfTaskSchedulerFv(), em[0x22], taskId);
        if (task != nullptr) {
            u32 x = *(u32*)((u8*)task + 0x2C);
            u32 r = (x << 17) | (x >> 15);
            s32 v = ((s32)(r & 0xFF800000)) >> 24;
            switch (v) {
            case 0xC: {
                EmVObj* obj = *(EmVObj**)(*(u8**)(self + 0x1B4) + 0x64);
                obj->callOp(0x1200000E);
                break;
            }
            default:
                break;
            }
        }
    }
}
