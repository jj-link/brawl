#include <types.h>
#include <gf/gf_application.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
void fn_8004D010(void* game);
void* getInstance__14gfSceneManagerFv();
void* searchScene__14gfSceneManagerFPCc(void* mgr, const char* name);
void* memset(void* p, int c, unsigned long n);
extern char lbl_1_data_6F5C[];
extern void* lbl_1_bss_18B4;
}

extern "C" void fn_1_22C8C(void* self) {
    *(u32*)((char*)self + 8) = 0;
    *(u8*)((char*)self + 0x18) = *(u8*)((char*)g_gfApplication + 0x110) != 0;
    fn_8004D010(g_GameGlobal);
    void* mgr = getInstance__14gfSceneManagerFv();
    void* s = searchScene__14gfSceneManagerFPCc(mgr, lbl_1_data_6F5C);
    lbl_1_bss_18B4 = s;
    *(u32*)((char*)s + 0x3B4) = 0;
    *(u32*)((char*)s + 0x3B0) = 0;
    memset((char*)s + 0x3B8, 0, 0x80);
    *(u8*)((char*)s + 0x440) = 0;
    *(u32*)((char*)s + 0x43C) = 0;
    *(u32*)((char*)s + 0x438) = 0;
    *(u8*)(*(char**)((char*)g_GameGlobal + 0x2C) + 0x509) = 0;
}
