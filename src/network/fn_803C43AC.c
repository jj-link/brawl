#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern u32 lbl_805A1210;
extern u32 lbl_805A1220;

s32 fn_803C43AC(s32 arg0) {
    s32 result = -1;
    u32 count;
    char* entries;
    u32 i;
    if (arg0 != 0) {
        count = lbl_805A1210;
        if (count != 0 && lbl_805A1220 != 0)
            entries = (char*)lbl_805A1220;
        else
            entries = 0;
        i = 0;
        while (i < count) {
            if ((u32)arg0 == *(u32*)(entries + 8)) {
                result = (s32)i;
                break;
            }
            entries += 0x140;
            i++;
        }
    }
    return result;
}