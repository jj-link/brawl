#include <types.h>
#pragma force_active on

typedef struct File {
    u8 pad[0x1860];
    u32 count;
} File;

typedef struct Header {
    u32 words[13];
    File *file;
} Header;

typedef struct State {
    s32 value;
    File *file;
    Header header;
    s32 field40;
    u32 field44;
    u16 field48;
    u16 mask;
    u8 buffer[0x20];
    u8 shift[12];
} State;

extern void *fn_803A976C(void *, int, u32);
extern u8 *fn_803A9884(u8 *, u8 *);
extern s32 fn_803B4F28(State *, s32);
extern s32 fn_803B502C(State *);
extern s32 fn_803B5138(State *, s32);
extern int fn_803BE914(char *, const u8 *, int);
extern int fn_803BF730(char *, u32);
extern int fn_803BE008(const char *, const char *);

s32 fn_803B24E0(Header *header, u32 start, u8 *prefix, u32 *bits)
{
    State st;
    char name[16];
    char expected[16];
    u32 result;
    u32 i, j, remaining;
    File *file;

    file = header->file;
    fn_803A976C(bits, 0, file->count * 4);
    st.header = *header;

    result = fn_803B4F28(&st, 0);
    while (fn_803B502C(&st) == 0) {
        if (result != 0)
            return result;
        if (st.buffer[0] == 0)
            break;

        if (st.buffer[0] != 0xE5 && (st.buffer[11] & 15) != 15 &&
            !(st.buffer[11] & 8)) {
            fn_803BE914(name, st.buffer, 0);

            for (i = 1; name[i] != '~' && name[i] != 0 && i < 7; i++) {
            }

            if (i < 7 && name[i] == '~') {
                for (j = i + 1; name[j] >= '0' && name[j] <= '9'; j++) {
                }

                if (name[j] == '.' || name[j] == 0) {
                    result = 0;
                    remaining = j - i - 1;
                    while (remaining != 0) {
                        result *= 10;
                        result += name[j - remaining] - '0';
                        remaining--;
                    }

                    fn_803A9884((u8 *)expected, prefix);
                    fn_803BF730(expected, result);
                    if (fn_803BE008(name, expected) == 0 && result >= start &&
                        result < start + (file->count << 5)) {
                        result -= start;
                        bits[result >> 5] |= 1 << result;
                    }
                }
            }
        }

        result = fn_803B5138(&st, 0);
    }

    return 0;
}
