#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_802DBCC8(void);
void fn_802DBC80(s32 arg0);
void fn_802DBCB4(void* p);
extern u32 lbl_80412208[6];
extern u32 lbl_80532E60[4];
}

extern "C" void fn_802DD520(void) {
    s32 temp_r3;

    temp_r3 = fn_802DBCC8();
    lbl_80532E60[0] = (u32)&lbl_80412208;
    lbl_80532E60[1] = (u32)&fn_802DBC80;
    lbl_80532E60[2] = (u32)&fn_802DBCB4;
    lbl_80532E60[3] = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802DD520_ctor = (void*)fn_802DD520;
