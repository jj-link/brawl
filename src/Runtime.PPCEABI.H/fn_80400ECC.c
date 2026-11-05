#pragma force_active on
typedef unsigned int u32;
typedef int s32;
extern void fn_804035BC(void*);
extern void fn_804035B4(void*);
extern void fn_8000449C(void*, const void*, u32);
extern char lbl_80599F48[];
s32 fn_80400ECC(void* arg0) {
    s32 result = 0;
    s32 offset;
    u32 total;
    u32 sign;
    fn_804035BC(lbl_80599F48);
    if (*(s32*)(lbl_80599F48 + 4) == 2) result = 0x100;
    else {
        total = *(u32*)(lbl_80599F48 + 8) + *(u32*)(lbl_80599F48 + 4);
        sign = total >> 31;
        offset = (s32)(((total & 1) ^ sign) - sign) * 0xC;
        fn_8000449C((void*)((u32)lbl_80599F48 + (u32)offset + 0xC), arg0, 0xC);
        *(s32*)(lbl_80599F48 + offset + 0x10) = *(s32*)(lbl_80599F48 + 0x24);
        total = *(u32*)(lbl_80599F48 + 0x24) + 1;
        *(u32*)(lbl_80599F48 + 0x24) = total;
        if (total < 0x100) *(u32*)(lbl_80599F48 + 0x24) = 0x100;
        *(s32*)(lbl_80599F48 + 4) = *(s32*)(lbl_80599F48 + 4) + 1;
    }
    fn_804035B4(lbl_80599F48);
    return result;
}