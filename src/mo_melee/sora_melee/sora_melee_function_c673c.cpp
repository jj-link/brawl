#pragma force_active on
#include <types.h>
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern "C" char lbl_27_data_18658[];
extern "C" char lbl_27_data_186A0[];
extern "C" char lbl_27_data_18740[];
extern "C" float lbl_27_rodata_EF0;
extern "C" float lbl_27_rodata_EF4;
extern "C" void* lbl_27_bss_2CC8;

struct Cls {
    virtual void fn_27_1E8DC();
    virtual void fn_27_1E374();
    virtual void fn_27_1E384();
    virtual void fn_27_C6F34();
    virtual void fn_27_1F00C();
    virtual void fn_27_C6EF4();
    virtual void fn_27_1E488();
    virtual void fn_27_1E544();
    virtual void fn_27_1E894();
};
struct Obj {
    char pad0[0x3C];
    void* m3C;
    void* m40;
    s32 m44;
    s32 m48;
    s32 m4C;
    Cls m50;
    void* m54;
    s32 m58;
    char pad5C[0x20];
    float m7C;
    float m80;
    float m84;
    float m88;
    s8 m8C;
    s8 m8D;
    s8 m8E;
};
extern "C" void fn_27_C673C() {
    Obj* task = (Obj*)lbl_27_bss_2CC8;
    if (task == 0) {
        task = (Obj*)__nw__FUlQ25Heaps8HeapType(0x90, 2);
        if (task != 0) {
            __ct__6gfTaskFPCcQ26gfTask8Categoryiib(task, lbl_27_data_18658, 0, 0, 0, true);
            Cls* sub = &task->m50;
            void* q = (void*)lbl_27_data_18740;
            task->m40 = (void*)lbl_27_data_186A0;
            task->m3C = (void*)(lbl_27_data_186A0 + 8);
            task->m44 = -1;
            task->m48 = 0;
            task->m4C = 0;
            *(void**)sub = q;
            task->m54 = (void*)(lbl_27_data_18740 + 0x48);
            task->m58 = (u16)task->m58;
            task->m8C = 0;
            task->m8D = 0;
            task->m8E = 0;
            task->m44 = -1;
            task->m48 = 0;
            task->m4C = 0;
            sub->fn_27_1E894();
            task->m8D = 0;
            float ef4;
            float ef0;
            ef0 = lbl_27_rodata_EF0;
            task->m8E = 0;
            ef4 = lbl_27_rodata_EF4;
            task->m80 = ef0;
            task->m7C = ef0;
            task->m88 = ef4;
            task->m84 = ef4;
        }
        lbl_27_bss_2CC8 = (void*)task;
    }
}
