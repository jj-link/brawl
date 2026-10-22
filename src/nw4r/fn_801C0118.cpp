#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" {
void fn_801BBC1C(void*, void*, void*);
void fn_801BBC68(void*, s32, s32);
s32 fn_80203640(void*);
s32 fn_8020365C(void*);
extern s32 lbl_805A0574;

s32 fn_801C0118(void* arg0) {
    char* base = (char*)arg0;
    s32 spC;
    s32 sp8;
    s32 temp_r31;
    
    s32 ret = fn_80203640(base + 0x24);
    s32 ptr = *(s32*)(base + 0x10);
    u32 result = ((u32)ret + 0x87) & 0xFFFFFFE0;
    u32 var_r0;
    if (ptr == 0) {
        var_r0 = 0;
    } else {
        var_r0 = (u32)*(s32*)(ptr + 0x1C) - (u32)ptr;
    }
    if (result > var_r0) {
        return 0;
    }
    fn_801BBC1C(base + 0xC, &spC, &sp8);
    lbl_805A0574 = 0;
    temp_r31 = fn_8020365C(base + 0x24);
    fn_801BBC68(base + 0xC, spC, sp8);
    fn_80203640(base + 0x24);
    *(unsigned char*)(base + 0xC) = 1;
    return temp_r31 != 0;
}
}
