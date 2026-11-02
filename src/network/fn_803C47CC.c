#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern u32 lbl_805A1210;
extern s32 lbl_805A1218;
extern u32 lbl_805A1220;
extern char lbl_80563280[];
extern char *lbl_80563218[];
extern char lbl_8059FE90;

extern void fn_803A9644(void *, void *, s32);
extern s32 fn_803AE438(void *, void *);
extern void fn_803A976C(void *, s32, u32);
extern void fn_803C7D64(s32, s32);
extern s32 fn_803C2AB0(void);
extern s32 fn_803C4168(void *, s32, s32);
extern s32 fn_80204688(s32, u32, s32);

static inline u32 findFree(void)
{
    char *end;
    char *ptr;
    u32 count;

    if (lbl_805A1210 != 0 && lbl_805A1220 != 0) {
        ptr = (char *)lbl_805A1220;
    } else {
        ptr = 0;
    }

    end = ptr + lbl_805A1210 * 0x140;
    count = 0;
    while (ptr != end) {
        if (*(s32 *)ptr == 0) {
            return count;
        }
        ptr += 0x140;
        count++;
    }
    return -1;
}

s32 fn_803C47CC(s32 *arg0, s32 arg1, u32 arg2)
{
    char *entry;
    s32 value;
    s32 size;
    s32 result;
    u32 count = findFree();

    if (count < lbl_805A1210 && lbl_805A1220 != 0) {
        entry = (char *)(lbl_805A1220 + count * 0x140);
    } else {
        entry = 0;
    }

    *arg0 = -1;
    if (entry == 0) {
        return 0xB002;
    }

    {
        char *obj = lbl_80563280 + count * 8;

        fn_803A9644(obj, &lbl_8059FE90, 8);
        *(s32 *)(obj + 4) = count;

        if (fn_803AE438(obj, entry + 8) == 0) {
            char *obj2 = lbl_80563218[count];

            fn_803A976C(obj2, 0, 0x10);
            *(s32 *)(obj2 + 0) = 0;
            *(s32 *)(obj2 + 0xC) = 0;
            *(s32 *)(obj2 + 8) = 0;
            *(s32 *)entry = (s32)obj2;
            *arg0 = count;

            if (entry != 0) {
                if (*(s32 *)(entry + 8) != 0) {
                    fn_803C7D64(*(s32 *)(entry + 8), 0);
                }
            }

            if (entry != 0) {
                value = lbl_805A1218;
                size = 8;
                if (arg1 != 0 && arg2 > 0x2800) {
                    result = fn_80204688(arg1, arg2, 0);
                    if (result != 0) {
                        value = result;
                        size = arg2 / 1280;
                    }
                }
                fn_803C4168(entry, size, value);
            }
            return 0;
        }
    }

    fn_803A976C(entry, 0, 0x140);
    if (entry + 0x1C != 0) {
        *(s32 *)(entry + 0x1C) = 0;
        *(s32 *)(entry + 0x20) = 0;
        *(s32 *)(entry + 0x24) = 0;
        *(s32 *)(entry + 0x28) = 0;
    }
    return fn_803C2AB0();
}
