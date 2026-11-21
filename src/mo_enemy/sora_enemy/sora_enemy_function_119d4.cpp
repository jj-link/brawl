#include <types.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_41_FCC0(void* self);
extern char __RTTI__5Enemy[];
extern char lbl_41_data_1B48[];
extern char lbl_41_data_1630[];
extern char lbl_41_data_19EC[];
void OSReport(const char* msg, ...);
}

struct EmPad3C {
    u8 pad[0x3C];
};

struct EmVObj : EmPad3C {
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
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void* f40();
};

extern "C" void fn_41_119D4(u8* self, u8* em)
{
    fn_41_FCC0(self);
    *(f32*)(self + 0xD0) = *(f32*)(em + 0x10);
    *(f32*)(self + 0xD4) = *(f32*)(em + 0x14);
    *(f32*)(self + 0xD8) = *(f32*)(em + 0x18);
    u32 taskId = *(u32*)(em + 0xC);
    if (taskId != 0xFFFFFFFF) {
        gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)em[0x22], taskId);
        if (task != nullptr) {
            s32 kind = (gfTask::Category)task->m_taskCategory;
            switch (kind) {
            case 10: {
                void* p = __dynamic_cast(task, 0x3C, lbl_41_data_1B48, lbl_41_data_1630, 1);
                EmVObj* obj = (EmVObj*)p;
                *(s32*)(self + 0xC8) = 0;
                *(void**)(self + 0xCC) = obj->f40();
                *(u32*)(self + 0xC4) = *(u32*)((u8*)p + 0x10C);
                break;
            }
            case 2: {
                void* p = __dynamic_cast(task, 0x3C, __RTTI__5Enemy, lbl_41_data_1630, 1);
                EmVObj* obj = (EmVObj*)p;
                *(s32*)(self + 0xC8) = 1;
                *(void**)(self + 0xCC) = obj->f40();
                *(u32*)(self + 0xC4) = *(u32*)((u8*)p + 0xB0);
                break;
            }
            case 6:
            case 11:
            case 12:
                break;
            default:
                OSReport(lbl_41_data_19EC, kind);
                break;
            }
        }
    }
}