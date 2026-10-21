#include <types.h>
#pragma force_active on
extern "C" {

extern float lbl_805A3E10;

void fn_80295148(void* p) {
    float x = lbl_805A3E10;
    *(float*)((char*)p + 8) = x;
    *(float*)((char*)p + 16) = x;
    *(float*)((char*)p + 24) = x;
}

}
