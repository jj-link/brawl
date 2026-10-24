#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern void fn_804035BC(void* buffer);
extern void fn_804035B4(void* buffer);
extern void fn_8000449C(void* destination, const void* source, u32 size);
extern char lbl_80599F48[];

s32 TRKGetNextEvent(void* arg0) {
    s32 result = 0;
    s32 next;
    s32 remaining;

    fn_804035BC(lbl_80599F48);
    if (*(s32*)(lbl_80599F48 + 4) > 0) {
        fn_8000449C(arg0,
                    lbl_80599F48 + *(s32*)(lbl_80599F48 + 8) * 0xC + 0xC,
                    0xC);
        remaining = *(s32*)(lbl_80599F48 + 4) - 1;
        next = *(s32*)(lbl_80599F48 + 8) + 1;
        *(s32*)(lbl_80599F48 + 8) = next;
        *(s32*)(lbl_80599F48 + 4) = remaining;
        if (next == 2) {
            *(s32*)(lbl_80599F48 + 8) = 0;
        }
        result = 1;
    }
    fn_804035B4(lbl_80599F48);
    return result;
}
