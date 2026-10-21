#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B96E8(void* p, int v, void* w);
void fn_80104938(void* p);
extern char lbl_8045D040[];

void* fn_801048EC(void* arg0) {
    *(unsigned int*)((char*)arg0 + 0x300) = (unsigned int)&lbl_8045D040;
    fn_800B96E8((char*)arg0 + 0x34, 0xFF, &lbl_8045D040);
    fn_80104938(arg0);
    return arg0;
}
}
