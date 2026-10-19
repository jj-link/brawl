#include <types.h>
#pragma force_active on

extern "C" int randi__Fl(long);

extern "C" void fn_27_220150(void* p) {
    randi__Fl(100);
    int r = randi__Fl(31);
    *(s16*)((u8*)p + 0xD4) = r + 10;
}
