#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

extern u16 lbl_8059ED04;
extern u16 lbl_8059ED06;
extern u16 lbl_8059ED08;
extern u16 lbl_8059ED0A;

#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define U32(p, o) (*(u32*)((u8*)(p) + (o)))

static inline int gt(int a, int b, int c) {
    int d = (a - b < 0) ? (b - a) : (a - b);
    return d > c;
}

#define BLOCK_A(F4, F2, F6, CA, CB)                                   \
    {                                                                 \
        int f4 = gt(S16(p, F4), S16(q, F4), 12);                      \
        int f2 = gt(S16(p, F2), S16(q, F2), 12);                      \
        int f6 = gt(S16(p, F6), S16(q, F6), 12);                      \
        if (f2 | f4 | f6) {                                           \
            u16 t = U16(o, CA) + 1;                                   \
            U16(o, CA) = t;                                           \
            if (t > lbl_8059ED04) {                                   \
                U16(o, CA) = 0;                                       \
                r = (u8)(r | 1);                                      \
                U16(o, CB) = 0;                                       \
            }                                                         \
        } else {                                                      \
            u16 t = (U16(o, CB) + 1) % lbl_8059ED08;                  \
            U16(o, CB) = t;                                           \
            if (t == lbl_8059ED08 - 1) {                              \
                u16 c = U16(o, CA);                                   \
                if (c != 0) {                                         \
                    U16(o, CA) = c - 1;                               \
                }                                                     \
            }                                                         \
        }                                                             \
    }

#define BLOCK_LOOP(a, b)                                              \
    for (i = 0; i < 4; i++) {                                         \
        int fa = gt(S16(a, 0xa), S16(b, 0xa), 2);                     \
        int f8 = gt(S16(a, 0x8), S16(b, 0x8), 2);                     \
        if (f8 | fa) {                                                \
            u16 t = U16(o, 0x8f8) + 1;                                \
            U16(o, 0x8f8) = t;                                        \
            if (t > lbl_8059ED06) {                                   \
                r = (u8)(r | 1);                                      \
                U16(o, 0x8f8) = 0;                                    \
            }                                                         \
        } else {                                                      \
            u16 t = (U16(o, 0x8fa) + 1) % lbl_8059ED0A;               \
            U16(o, 0x8fa) = t;                                        \
            if (t == lbl_8059ED0A - 1) {                              \
                u16 c = U16(o, 0x8f8);                                \
                if (c != 0) {                                         \
                    U16(o, 0x8f8) = c - 1;                            \
                }                                                     \
            }                                                         \
        }                                                             \
        b += 8;                                                       \
        a += 8;                                                       \
    }

u8 fn_802172F8(void* self, u8* p, u8* q) {
    u8* o = (u8*)self;
    u32 mode = U32(o, 0x8b8);
    u8 sel = U8(o, 0x8c2);
    int r;
    int i;
    if (mode <= 2) {
        r = U16(p, 0) != U16(q, 0);
        if (S8(p, 0x29) == 0 && S8(q, 0x29) == 0) {
            BLOCK_A(4, 2, 6, 0x8fc, 0x8fe)
            BLOCK_LOOP(p, q)
        }
    } else if (mode - 3 <= 2) {
        u8* a = p;
        u8* b = q;
        r = U16(p, 0) != U16(q, 0);
        if (S8(p, 0x29) == 0 && S8(q, 0x29) == 0) {
            BLOCK_A(4, 2, 6, 0x8fc, 0x8fe)
            BLOCK_LOOP(a, b)
            BLOCK_A(0x2c, 0x2a, 0x2e, 0x900, 0x902)
            r |= gt(S8(p, 0x30), S8(q, 0x30), 1);
            r |= gt(S8(p, 0x31), S8(q, 0x31), 1);
        }
    } else if (mode - 6 <= 2) {
        u8* a = p;
        u8* b = q;
        int d1, d2, d3;
        switch (sel) {
        case 1:
            d1 = 16;
            d2 = 32;
            d3 = 8;
            break;
        case 3:
            d1 = 4;
            d2 = 4;
            d3 = 1;
            break;
        default:
            d1 = 1;
            d2 = 1;
            d3 = 1;
            break;
        }
        r = U16(p, 0) != U16(q, 0);
        if (S8(p, 0x29) == 0 && S8(q, 0x29) == 0) {
            BLOCK_A(4, 2, 6, 0x8fc, 0x8fe)
            BLOCK_LOOP(a, b)
            r |= U16(p, 0x2a) != U16(q, 0x2a);
            r |= gt(S16(p, 0x2c) / d1, S16(q, 0x2c) / d1, 1);
            r |= gt(S16(p, 0x2e) / d1, S16(q, 0x2e) / d1, 1);
            r |= gt(S16(p, 0x30) / d2, S16(q, 0x30) / d2, 1);
            r |= gt(S16(p, 0x32) / d2, S16(q, 0x32) / d2, 1);
            r |= gt(U8(p, 0x34) / d3, U8(q, 0x34) / d3, 1);
            r |= gt(U8(p, 0x35) / d3, U8(q, 0x35) / d3, 1);
        }
    } else {
        r = U16(p, 0) != U16(q, 0);
        if (S8(p, 0x29) == 0 && S8(q, 0x29) == 0) {
            BLOCK_A(4, 2, 6, 0x8fc, 0x8fe)
            BLOCK_LOOP(p, q)
        }
    }
    return r;
}
