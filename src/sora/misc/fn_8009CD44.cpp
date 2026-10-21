#include <types.h>
#pragma force_active on

extern "C" {
void* getManager__15gfCameraManagerFv();

char* fn_8009CD44(char* self) {
    s32 v = *(s32*)(self + 0x40);
    switch (v) {
    case 3:
    case 4:
    case 6:
        return (char*)getManager__15gfCameraManagerFv();
    default:
        return (char*)getManager__15gfCameraManagerFv() + 0x134;
    }
}
}
