#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_D46B8();
}

#pragma import__ use_fixfixedpoint fn_27_D46B8
#pragma import__ use_returnfix fn_27_D46B8

extern "C" void fn_96_F038(void* receiver, short id, int argument) {
    ((long (*)(void*, long, void*, char))fn_27_D46B8)(receiver, (long)id, receiver,
                                                      (char)argument);
}
