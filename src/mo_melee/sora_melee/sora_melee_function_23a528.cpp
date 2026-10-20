#include <types.h>
#pragma force_active on

extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" void updateStatus__15gfTaskSchedulerFv(void*);
extern "C" int fn_27_23A580(void*);

extern "C" void fn_27_23A528(void* a, u32 b) {
    while (fn_27_23A580(a) == 0 && b != 0) {
        void* inst = getInstance__15gfTaskSchedulerFv();
        updateStatus__15gfTaskSchedulerFv(inst);
    }
}
