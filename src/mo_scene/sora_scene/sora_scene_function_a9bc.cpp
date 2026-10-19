#include <types.h>
#pragma force_active on

extern "C" void exit__6gfTaskFv(void*);

struct SceneUnk {
    u32 unk0;
    u32 unk4;
    void* task8;
};

extern "C" int fn_1_A9BC(SceneUnk* self) {
    exit__6gfTaskFv(self->task8);
    self->task8 = 0;
    return 0;
}
