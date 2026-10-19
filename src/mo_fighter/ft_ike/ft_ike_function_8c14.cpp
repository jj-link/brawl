#include <types.h>
#pragma force_active on

extern "C" int randi__Fl(long);
extern "C" const void* lbl_119_rodata_0[4];

extern "C" const void* fn_119_8C14() {
    int index = randi__Fl(4);
    if (index < 0 || index >= 4) {
        index = 0;
    }
    return lbl_119_rodata_0[index];
}
