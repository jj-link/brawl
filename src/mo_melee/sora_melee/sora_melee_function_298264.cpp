#include <gf/gf_task.h>
#include <so/so_external_value_accesser.h>
#include <so/stageobject.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char __RTTI__6gfTask[];
extern "C" unsigned int lbl_27_data_4A000[];
extern "C" int fn_27_287890(void*, unsigned int, void*, int);

struct Ctx {
    char pad[0x8C8];
    unsigned int id;
};

extern "C" int fn_27_298264(void*, Ctx* r4, unsigned int r5, Vec3f* r6, int r7) {
    if (r7 == 8) {
        gfTask* task = gfTask::getTask(r4->id);
        void* obj;
        if (task != 0) {
            obj = __dynamic_cast(task, 0x3C, lbl_27_data_4A000, __RTTI__6gfTask, 0);
        } else {
            obj = 0;
        }
        if (obj == 0) {
            return 0;
        }
        if (fn_27_287890(obj, r5, r6, 0) != 0) {
            Vec3f pos = soExternalValueAccesser::getPos((StageObject*)obj);
            r6->m_x = r6->m_x - (pos.m_x - r6->m_x);
            r6->m_y = pos.m_y;
            r6->m_z = pos.m_z;
            return 1;
        }
    }
    return 0;
}
