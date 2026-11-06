#include <types.h>
#include <gf/gf_task_scheduler.h>
#include <nw4r/g3d/g3d_obj.h>
#include <snd/snd_system.h>
#pragma force_active on

struct PeachTask {
    char pad[0x3c];
    void* vtable;
    char pad40[8];
    nw4r::g3d::G3dObj* object;
    char pad4c[4];
    int sound;
    u32 taskId;
};

extern "C" {
extern char lbl_103_data_6830[];
extern char lbl_103_data_654[];
extern char lbl_103_data_23A0[];
void fn_80075F1C(sndSystem*, int, int);
void fn_103_10C78(PeachTask*);
void fn_103_9708(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void __dt__6gfTaskFv(void*, short);
void __dl__FPv(void*);

PeachTask* fn_103_10AB0(PeachTask* self, int flag) {
    if (self) {
        self->vtable = lbl_103_data_6830;
        if (self->sound >= 0) {
            fn_80075F1C(g_sndSystem, self->sound, 0);
            self->sound = -1;
        }
        fn_103_10C78(self);
        if (self->object)
            self->object->Destroy();
        void* task = gfTaskScheduler::getInstance()->getTaskById(gfTask::Category_Fighter, self->taskId);
        void* obj = __dynamic_cast(task, 0x3c, lbl_103_data_654, lbl_103_data_23A0, 0);
        if (obj)
            fn_103_9708(obj);
        __dt__6gfTaskFv(self, 0);
        if ((short)flag > 0)
            __dl__FPv(self);
    }
    return self;
}
}