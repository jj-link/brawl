#include <types.h>

#pragma force_active on

extern void *fn_803A976C(void *, int, u32);
extern s32 fn_801F6278(void *, void *);
extern s32 fn_801F6524(void *);
extern s32 fn_803C7460(void *);
extern s32 DVDReadPrio(void *, void *, s32, s32, s32);

s32 fn_803C4CB8(void *unused, u8 *path) {
    int i;
    char *s = (char *)path;
    u8 name[0xFF];
    u8 *p = name;
    u32 size;
    s32 result = 0xB001;
    u8 readbuf[0x20] __attribute__((aligned(32)));
    u8 file[0x3C];
    int c;
    int read_result;

    fn_803A976C(name, 0, 0xFF);
    for (i = 0; i < 0xFF && *s != 0; i++) {
        if (*s == '/') {
            *p = '\\';
        } else {
            *p = *s;
        }
        s++;
        p++;
    }

    if (fn_801F6278(name, file) != 0) {
        read_result = DVDReadPrio(file, readbuf, 0x20, 0, 2);
        size = *(u32 *)(file + 0x34);
        if (read_result != 0 &&
            fn_803C7460(readbuf) != 0 &&
            size ==
                ((u32)readbuf[8] << 24 | (u32)readbuf[9] << 16 |
                 (u32)readbuf[10] << 8 | readbuf[11])) {
            result = 0;
        } else {
            result = 0xB006;
        }
        fn_801F6524(file);
    }
    return result;
}
