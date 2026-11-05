#pragma force_active on
#include <gf/gf_task.h>

extern "C" void fn_10_10ACC(void* self, int flag);
extern "C" void fn_10_19EF0(void* obj, int v);
extern "C" void fn_10_1C57C(void* obj, int v);

extern "C" int fn_10_B1CC(char* self) {
    gfTask* task = *(gfTask**)(self + 0x60C);
    if (task != 0) {
        task->exit();
        *(gfTask**)(self + 0x60C) = 0;
        fn_10_10ACC(self, 1);
        if (*(int*)(self + 0x630) == 0) {
            void** cur = (void**)self;
            for (int i = 0; i < *(int*)(self + 0x648); i++) {
                fn_10_19EF0(*(void**)((char*)cur[0x11] + 0x1A8), 0);
                cur++;
            }
            cur = (void**)self;
            for (int i = 0; i < *(int*)(self + 0x648); i++) {
                fn_10_1C57C(*(void**)((char*)cur[0x11] + 0x1AC), 0);
                cur++;
            }
        }
        return 1;
    }
    return 0;
}
