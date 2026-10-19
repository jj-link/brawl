#include <st/module.h>
#pragma force_active on

extern "C" {
void fn_27_D2FF0(void*, int, int);
void fn_27_61454(void*, void*, void*, void*, void*, void*);
extern char lbl_27_bss_4694[0xC];
extern int lbl_115_bss_314;
}

extern "C" void* fn_115_71E8(void* fighter, void* arg2, int arg3)
{
    fn_27_D2FF0(fighter, 1, 0);
    fn_27_61454((char*)fighter + 0xAC, arg2, fighter, lbl_27_bss_4694, &lbl_115_bss_314, (void*)arg3);
    return fighter;
}
