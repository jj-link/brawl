#include <string.h>
#pragma force_active on

extern s32 lbl_8059FEA8;
extern void *fn_803CD284(s32 size);
extern void fn_803CD298(void *ptr);
extern void fn_803CD410(s32 error);
extern s32 fn_8020BA48(s32 path, void *file, s32 mode);
extern s32 fn_8020AC38(void *file, s32 offset, s32 origin);
extern u32 fn_8020AA78(void *file, void *buffer, u32 size);
extern void fn_8020BC3C(void *file);

void *fn_803CDAC8(void *dest, void *table, u32 index, u32 item)
{
    s32 file[0x24];
    unsigned char *entry;
    void *header;
    void *result;
    u32 aligned;
    u32 aligned2;
    void *buffer;
    u32 offset;
    u32 start;
    s32 *data;
    u32 size;

    result = 0;
    entry = (unsigned char *)table + index * 8;
    header = fn_803CD284(0x400);
    if (fn_8020BA48(lbl_8059FEA8, file, 1) == 0) {
        aligned = (*(unsigned short *)entry * 4 + 0x23) & ~0x1Fu;
        fn_8020AC38(file, *(s32 *)(entry + 4), 0);
        if (aligned == fn_8020AA78(file, header, aligned)) {
            data = (s32 *)header;
            start = data[(unsigned short)item];
            size = *(s32 *)((u32)header + (item + 1) * 4) - start;
        } else {
            fn_803CD410(2);
            fn_803CD298(header);
            return 0;
        }
        offset = *(s32 *)(entry + 4) + *(unsigned short *)entry * 4 + start + 4;
        aligned2 = (size + 0x1F) & ~0x1Fu;
        buffer = fn_803CD284(aligned2);
        fn_8020AC38(file, offset, 0);
        if (aligned2 == fn_8020AA78(file, buffer, aligned2)) {
            memcpy(dest, buffer, size);
            result = dest;
        } else {
            fn_803CD410(2);
            fn_803CD298(header);
            fn_803CD298(buffer);
            return 0;
        }
        fn_803CD298(buffer);
        fn_8020BC3C(file);
    } else {
        fn_803CD410(2);
    }
    fn_803CD298(header);
    return result;
}
