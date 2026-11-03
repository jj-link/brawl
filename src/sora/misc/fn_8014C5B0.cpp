#pragma force_active on
#include <gf/gf_task.h>

extern "C" {
void fn_800307B4();
extern int lbl_805A0448;
void fn_8014C5B0(gfTask* self);
}

extern "C" void fn_8014C5B0(gfTask* self) {
    char* obj = *(char**)((char*)self + 0x40);
    if (obj != 0 && *(int*)(obj + 0xF0) == 0) {
        fn_800307B4();
        *(char**)((char*)self + 0x40) = 0;
        if (*((unsigned char*)self + 0x44) != 0) {
            self->exit();
        }
        lbl_805A0448 -= 1;
    }
}
