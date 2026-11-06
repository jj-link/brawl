#include <types.h>
#pragma force_active on
extern void *fn_803A976C(void *, int, u32);
extern int fn_803C8898(void *, void *, int, int);
extern int fn_803C87E0(void *, u32 *);
extern int fn_803C85A0(void *, void *, int);
extern int fn_803C7460(void *);
extern int fn_803C8370(void *);

int fn_803C4B10(char *path, int mode) {
    char file[0xa0] __attribute__((aligned(32)));
    char name[0x100] __attribute__((aligned(32)));
    u8 header[0x20] __attribute__((aligned(32)));
    u32 size __attribute__((aligned(32)));
    char *p = name;
    char *s = path;
    int result = 0xB001;
    int i;
    int ret;
    fn_803A976C(name, 0, 0xff);
    for (i = 0; i < 0xff && *s; i++) {
        if (*s == '\\') *p = '/';
        else *p = *s;
        s++;
        p++;
    }
    if (fn_803C8898(name, file, 1, mode) == 0) {
        size = 0;
        ret = fn_803C87E0(file, &size);
        if (fn_803C85A0(file, header, 0x20) >= 0 && ret >= 0 &&
            fn_803C7460(header) && size == ((u32)header[8] << 24 | (u32)header[9] << 16 | (u32)header[10] << 8 | header[11])) {
            result = 0;
        } else {
            result = 0xB006;
        }
        fn_803C8370(file);
    }
    return result;
}