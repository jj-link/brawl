#pragma force_active on

#include <types.h>
#include <revolution/OS/OSMutex.h>

extern void fn_801CA7E8(void *p);
extern void fn_801CBFB0(void *a, void *b, int c, int d, int e, int f);
extern s32 fn_802781F0(void *a, void *b);
extern void fn_80278C34(void *p);
extern void fn_8027ABA8(void *p);

extern s32 lbl_8040E738[0x25][2];
extern s32 lbl_8040E798[0x4A][2];
extern OSMutex lbl_80532170;
extern const f32 lbl_805A3AF4;
extern const f32 lbl_805A3B60;

static inline s32 findSlot(s32 id, s32 flag)
{
    s32 j;

    for (j = 0; j < 0x4A; j++) {
        if (id == lbl_8040E798[j][0] && lbl_8040E798[j][1] == flag)
            return j;
    }
    return -1;
}

static inline s32 findIdx(s32 n, s32 id, s32 flag)
{
    const s32 *e = &lbl_8040E738[0][0];
    s32 i;

    for (i = 0; i < n; i++) {
        if (id == e[0] && flag == e[1])
            return i;
        e += 2;
    }
    return -1;
}

#define mode currentMode
#define SLOT(i) (*(s32 *)((u8 *)*(void **)(self + 0x2A0 + (i) * 4) + 0x14))
#define ITEM(i) (*(void **)(self + 0x2A0 + (i) * 4))

#define FLUSH()                                                              \
    if (*(s32 *)(self + 0x64) > 2) {                                         \
        s32 res_ = 0;                                                        \
        s32 (*cb_)(s32, s32) =                                               \
            *(s32 (**)(s32, s32))((u8 *)*(void **)(self + 4) + 0x14);        \
        if (cb_ != 0)                                                        \
            res_ = cb_(5, 4);                                                \
        if (res_ == 0 && *(void **)(self + 0x5D0) != 0 &&                    \
            *(void **)(self + 0x5E4) != 0) {                                 \
            void *m_ = &lbl_80532170;                                        \
            OSLockMutex(m_);                                                 \
            fn_801CA7E8(*(void **)(self + 0x5E4));                           \
            fn_801CBFB0((u8 *)*(void **)(self + 0x5D0) + 0xC,                \
                        *(void **)(self + 0x5E4), 4, 0, 0, 0);               \
            OSUnlockMutex(m_);                                               \
        }                                                                    \
        *(s32 *)(self + 0x64) = 0;                                           \
    }

static inline s32 canActivate(u8 *self)
{
    s32 ok = 1;
    s32 a = findSlot(4, 2);
    s32 b = findSlot(5, 3);
    s32 c = findSlot(4, 0x13);
    s32 d = findSlot(5, 0x14);
    if (*(s32 *)(self + 0x10) != 2 || SLOT(a) == 1 || SLOT(b) == 1 ||
        SLOT(c) == 1 || SLOT(d) == 1)
        ok = 0;
    return ok;
}

#define ACT(id, fl)                                                          \
    {                                                                        \
        void *o_;                                                            \
        s32 i0_ = findSlot((id), (fl));                                      \
        s32 ok_ = canActivate(self);                                                         \
        if (ok_ != 0) {                                                      \
            o_ = ITEM(i0_);                                                  \
            fn_80278C34(o_);                                                 \
            *(s32 *)((u8 *)o_ + 0x14) = 1;                                   \
            *(s32 *)(self + 0x74) = i0_;                                     \
            *(s32 *)(self + 0x6C) = 0;                                       \
            FLUSH();                                                         \
            flag = 1;                                                        \
        } else {                                                             \
            *(s32 *)(self + 0x6C) = i0_;                                     \
        }                                                                    \
    }

#define ONE(id, fl)                                                          \
    {                                                                        \
        void *o_;                                                            \
        s32 i0_ = findSlot((id), (fl));                                      \
        o_ = ITEM(i0_);                                                      \
        fn_80278C34(o_);                                                     \
        *(s32 *)((u8 *)o_ + 0x14) = 1;                                       \
        FLUSH();                                                             \
        flag = 1;                                                            \
    }

void fn_80274AD0(void *arg0, void *arg1, s32 *arg2)
{
    u8 *self = (u8 *)arg0;
    s32 r;
    s32 state;
    s32 flag;

    r = fn_802781F0(arg0, arg1);
    state = *(s32 *)(self + 0x10);
    flag = 0;
    if (state == 2 && r != -1 && *(s32 *)(self + 0x1C + r * 4) == 0) {
        s32 currentMode = *(s32 *)(self + 0);
        if (mode != 2 && r < *(s32 *)(self + 8)) {
            s32 k = findIdx(*(s32 *)(self + 0xC), r, 0);
            void *o = *(void **)(self + 0x270 + k * 4);

            fn_80278C34(o);
            *(s32 *)((u8 *)o + 0x14) = 1;
            if (*(s32 *)(self + 0) == 0) {
                FLUSH();
                flag = 1;
            }
        } else {
            switch (r - *(s32 *)(self + 8)) {
            case 0:
                if (mode == 0) {
                    s32 v = 1;
                    if (state != 2 ||
                        *(s32 *)((u8 *)*(void **)(self + 0x3F8) + 0x14) == 1 ||
                        *(s32 *)((u8 *)*(void **)(self + 0x3D4) + 0x14) == 1)
                        v = 0;
                    if (v != 0) {
                        void *o = *(void **)(self + 0x3D4);
                        fn_80278C34(o);
                        *(s32 *)((u8 *)o + 0x14) = 1;
                        *(s32 *)(self + 0x70) = 3;
                        *(s32 *)(self + 0x68) = 0;
                        FLUSH();
                        flag = 1;
                    } else {
                        *(s32 *)(self + 0x68) = 3;
                    }
                }
                break;
            case 1:
            case 9:
                if (mode == 0) {
                    ACT(4, 2)
                } else if (mode == 1) {
                    ACT(4, 0x13)
                }
                break;
            case 2:
                if (mode == 1) {
                    ONE(6, 4)
                }
                break;
            case 3:
                if (mode == 1) {
                    ONE(7, 4)
                }
                break;
            case 4:
                if (mode == 1) {
                    ONE(8, 4)
                }
                break;
            case 5:
                if (mode == 1) {
                    ONE(9, 4)
                }
                break;
            case 6:
                if (mode == 1) {
                    ONE(0xA, 4)
                }
                break;
            case 7:
                if (mode == 2) {
                    ONE(0x11, 0xB)
                }
                break;
            case 8:
                if (mode == 2) {
                    ONE(0x12, 0xB)
                }
                break;
            }
        }
    }

    if (r == *(s32 *)(self + 8) + 1 || r == *(s32 *)(self + 8) + 9) {
        *(s32 *)(self + 0x1C + (*(s32 *)(self + 8) + 1) * 4) += 1;
        *(s32 *)(self + 0x1C + (*(s32 *)(self + 8) + 9) * 4) += 1;
    } else {
        *(s32 *)(self + 0x1C + r * 4) += 1;
    }

    if (flag != 0 && arg2 != 0) {
        u8 *p = self + *arg2 * 4;
        void *h = *(void **)(p + 0x25C);

        if (*(u8 *)((u8 *)h + 0x1C) == 0) {
            if (*(f32 *)(p + 0x1D0) <= lbl_805A3AF4) {
                *(f32 *)(p + 0x1C0) = lbl_805A3B60;
                fn_8027ABA8(*(void **)(self + 0x25C + *arg2 * 4));
            }
        }
    }
}
