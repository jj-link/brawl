#include <gf/gf_application.h>
#include <types.h>
#pragma force_active on

extern "C" {
int isLoadFinishMenuSound__6muMenuFv();
void fn_9_74C(void* self);
void fn_9_AF0(void* self);
void fn_9_1984(void* self, void* arg);
void fn_9_618(void* self);
void fn_9_D7C(void* self);
}

extern "C" int fn_9_243C(void* self) {
    if (!isLoadFinishMenuSound__6muMenuFv()) {
        return 0;
    }
    fn_9_74C(self);
    fn_9_AF0(self);
    fn_9_1984(self, (u8*)self + 0xFB0);
    fn_9_618(self);
    fn_9_D7C(self);
    g_gfApplication->unkD0.endKeepScreen();
    return 1;
}
