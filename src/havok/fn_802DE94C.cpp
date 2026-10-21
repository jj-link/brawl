#pragma force_active on
typedef unsigned int u32;

extern "C" {
u32 fn_802DE728(void);
void fn_802DE6F4(void* arg0);
void fn_802DE714(void* p);
extern char lbl_804126F0[];
extern u32 lbl_80532F10[4];
}

extern "C" void fn_802DE94C(void) {
    u32 temp_r3 = fn_802DE728();
    lbl_80532F10[0] = (u32)lbl_804126F0;
    lbl_80532F10[1] = (u32)fn_802DE6F4;
    lbl_80532F10[2] = (u32)fn_802DE714;
    lbl_80532F10[3] = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802DE94C_ctor = (void*)fn_802DE94C;
