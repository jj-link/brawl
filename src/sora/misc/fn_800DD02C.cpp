#include <gf/gf_task.h>
#include <types.h>

#pragma force_active on

struct Middle {
    int a;
    int b;
    virtual void m2(int);
};

struct SelfObj {
    char pad0[0x9C];
    gfTask* task_ptr;
    char pad_a0[0x18];
    Middle* middle;
};

extern "C" int fn_800F2894(void*);
extern "C" void exit__6gfTaskFv(void*);

extern "C" int fn_800DD02C(SelfObj* self, int* result) {
    gfTask* task = self->task_ptr;
    if (task == NULL) {
        return 1;
    }

    int ret = fn_800F2894(task);
    *result = ret;
    if (ret != 0) {
        exit__6gfTaskFv(self->task_ptr);
        Middle* mid = self->middle;
        self->task_ptr = NULL;
        if (mid != NULL) {
            mid->m2(1);
        }
        self->middle = NULL;
        return 1;
    }
    return 0;
}
