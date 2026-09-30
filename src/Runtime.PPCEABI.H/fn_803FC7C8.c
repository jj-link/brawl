// Runtime.PPCEABI.H/fn_803FC7C8.c
// Wide-character length/copy helpers and stream orientation.

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#define __closed_file 0
#define __unoriented 0
#define __char_oriented 1
#define __wide_oriented 2

struct FILE {
    u8 pad0[4];
    union {
        u32 x4;
        struct {
            u32 unused0 : 7;
            u32 file_kind : 3;
            u32 file_orientation : 2;
            u32 unused1 : 20;
        } bits;
    } mode;
};

int fn_803FC7C8(const u16* s) {
    int k = -1;
    const u16* p = s - 1;
    do {
        k++;
    } while (*++p);

    return k;
}

u16* fn_803FC7E4(u16* dst, const u16* src, int n) {
    const u16* p = src - 1;
    u16* q = dst - 1;

    n++;
    while (--n) {
        if (!(*++q = *++p)) {
            while (--n) {
                *++q = 0;
            }
            break;
        }
    }
    return dst;
}

int fwide(struct FILE* stream, int mode) {
    int orientation;

    if (stream == 0 || stream->mode.bits.file_kind == __closed_file) {
        return 0;
    }
    orientation = stream->mode.bits.file_orientation;
    switch (orientation) {
    case __unoriented:
        if (mode > 0) {
            stream->mode.bits.file_orientation = __wide_oriented;
        } else if (mode < 0) {
            stream->mode.bits.file_orientation = __char_oriented;
        }
        break;
    case __wide_oriented:
        mode = 1;
        break;
    case __char_oriented:
        mode = -1;
        break;
    }
    return mode;
}
