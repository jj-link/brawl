#include <types.h>
#include <internal/fdlibm_public.h>

#define PSMTXMultVec fn_801ECD70
#define PSVECMag fn_801ED04C
#include <revolution/MTX/mtxvec.h>
#include <revolution/MTX/vec.h>
#pragma force_active on
#undef PSVECMag
#undef PSMTXMultVec

extern "C" {
f64 fn_80400B44(f64, f64);
void* fn_801B77F8();
s32 fn_801B802C(void*);

extern f32 lbl_805A05B0, lbl_805A05B8, lbl_805A05C0, lbl_805A05C8;
extern f32 lbl_805A05D0, lbl_805A05D8, lbl_805A05E0, lbl_805A05E8;
extern s8 lbl_805A05B4, lbl_805A05BC, lbl_805A05C4, lbl_805A05CC;
extern s8 lbl_805A05D4, lbl_805A05DC, lbl_805A05E4, lbl_805A05EC;
extern f32 lbl_805A35DC, lbl_805A35E4, lbl_805A35E8, lbl_805A35EC;
extern f32 lbl_805A35F0, lbl_805A35F4, lbl_805A35F8, lbl_805A35FC;
extern f32 lbl_805A3600, lbl_805A3604, lbl_805A3608, lbl_805A360C;
}

static inline f32 ratio(f32 a, f32 b, f32 c)
{
    return (a - b) / c;
}

extern "C" void fn_801C6238(
    char* a0, f32* a1, s32 a2, s32 a3, char* a4, u32 a5)
{
                f32 factor;
    char* obj = *(char**)(a0 + 0xC);
    Vec v, u, w;
    f32 f30, f29, f27, f31, f28, f0, f5;

    if (obj == 0) {
        a1[0] = lbl_805A35DC;
        return;
    }

    fn_801ECD70((const f32 (*)[4])obj, (const Vec*)(a4 + 0xC), &v);
    f31 = fn_801ED04C(&v);
    f29 = lbl_805A35E4;

    if (a5 & 9) {
        f32 r = *(f32*)(obj + 0x34);
        if (f31 > r) {
            switch (*(u8*)(a4 + 8)) {
            case 1:
                f29 = (f32)fn_80400B44(
                    (f32)*(u8*)(a4 + 9) * lbl_805A35E8,
                    ratio(f31, r, *(f32*)(obj + 0x38)));
                break;
            case 2: {
                f32 delta = f31 - r;
                f32 span = *(f32*)(obj + 0x38);
                f32 scaled = (f32)*(u8*)(a4 + 9) * (delta / span);
                f29 -= scaled * lbl_805A35E8;
                f29 = lbl_805A35DC < f29 ? f29 : lbl_805A35DC;
                break;
            }
            }
        }
    }

    if ((a5 & 1) && !(*(u32*)(a4 + 4) & 1)) a1[0] = f29;

    if (a5 & 6) {
        if (lbl_805A35DC == f31) {
            u.x = u.y = u.z = lbl_805A35DC;
        } else {
            f32 x, z;
            z = v.z;
            x = v.x;
            w.y = lbl_805A35DC;
            w.x = x;
            w.z = z;
            f32 len = fn_801ED04C(&w);
            if (len > *(f32*)(obj + 0x30)) {
                w.x *= *(f32*)(obj + 0x30) / len;
                w.z *= *(f32*)(obj + 0x30) / len;
            }
            len = fn_801ED04C(&w);
            u.x = v.x * len / f31;
            u.y = lbl_805A35DC;
            u.z = v.z * len / f31;
        }

        f31 = (f32)atan2(u.x, -u.z);
        f28 = fn_801ED04C(&u) / *(f32*)(obj + 0x30);

        switch (fn_801B802C(fn_801B77F8())) {
        case 1:
        case 2:
            if (!lbl_805A05B4) {
                f32 value = -*(f32*)(a0 + 0x1c);
                lbl_805A05B4 = 1;
                lbl_805A05B0 = value;
            }
            if (!lbl_805A05BC) {
                f32 value = -*(f32*)(a0 + 0x18);
                lbl_805A05BC = 1;
                lbl_805A05B8 = value;
            }
            if (!lbl_805A05C4) {
                lbl_805A05C0 = *(f32*)(a0 + 0x18);
                lbl_805A05C4 = 1;
            }
            if (!lbl_805A05CC) {
                lbl_805A05C8 = *(f32*)(a0 + 0x1c);
                lbl_805A05CC = 1;
            }

            if (f31 < lbl_805A05B0) {
                if (lbl_805A35EC == lbl_805A05B0) {
                    f30 = lbl_805A35F0;
                } else {
                    f32 denominator = lbl_805A35EC - lbl_805A05B0;
                    f30 = (f31 * lbl_805A35E4) / denominator
                        + (lbl_805A35F4 - lbl_805A05B0 * lbl_805A35DC)
                            / denominator;
                }
                f27 = lbl_805A35E4;
            } else if (f31 < lbl_805A35F8) {
                f30 = lbl_805A35FC;
                if (lbl_805A05B0 == lbl_805A35F8) {
                    f27 = lbl_805A3600;
                } else {
                    f27 = (f31 * lbl_805A35E4)
                            / (lbl_805A05B0 - lbl_805A35F8)
                        + (lbl_805A05B0 * lbl_805A35DC - lbl_805A35F8)
                            / (lbl_805A05B0 - lbl_805A35F8);
                }
            } else if (f31 < lbl_805A05B8) {
                f30 = lbl_805A35FC;
                if (lbl_805A35F8 == lbl_805A05B8) {
                    f27 = lbl_805A35F0;
                } else {
                    f32 denominator = lbl_805A35F8 - lbl_805A05B8;
                    f27 = (f31 * lbl_805A35E4) / denominator
                        + (lbl_805A3604 - lbl_805A05B8 * lbl_805A35DC)
                            / denominator;
                }
            } else if (f31 < lbl_805A05C0) {
                if (lbl_805A05B8 == lbl_805A05C0) {
                    f30 = lbl_805A35DC;
                } else {
                    f32 denominator = lbl_805A05B8 - lbl_805A05C0;
                    f30 = (f31 * lbl_805A3608) / denominator
                        + (lbl_805A05B8 * lbl_805A35E4
                           - lbl_805A05C0 * lbl_805A35FC)
                            / denominator;
                }
                f27 = lbl_805A35FC;
            } else if (f31 < lbl_805A3604) {
                f30 = lbl_805A35E4;
                if (lbl_805A05C0 == lbl_805A3604) {
                    f27 = lbl_805A35F0;
                } else {
                    f27 = (f31 * lbl_805A35FC)
                            / (lbl_805A05C0 - lbl_805A3604)
                        + (lbl_805A05C0 * lbl_805A35DC - lbl_805A35F8)
                            / (lbl_805A05C0 - lbl_805A3604);
                }
            } else if (f31 < lbl_805A05C8) {
                f30 = lbl_805A35E4;
                if (lbl_805A3604 == lbl_805A05C8) {
                    f27 = lbl_805A3600;
                } else {
                    f32 denominator = lbl_805A3604 - lbl_805A05C8;
                    f27 = (f31 * lbl_805A35FC) / denominator
                        + (lbl_805A3604 - lbl_805A05C8 * lbl_805A35DC)
                            / denominator;
                }
            } else {
                if (lbl_805A05C8 == lbl_805A35F4) {
                    f30 = lbl_805A3600;
                } else {
                    f32 denominator = lbl_805A05C8 - lbl_805A35F4;
                    f30 = (f31 * lbl_805A35E4) / denominator
                        + (lbl_805A05C8 * lbl_805A35DC - lbl_805A35F4)
                            / denominator;
                }
                f27 = lbl_805A35E4;
            }

            {
                f31 = (f32)cos(*(f32*)(a0 + 0x1c));
                f32 angle = *(f32*)(a0 + 0x18);
                f32 c2 = (f32)cos(angle);
                f32 sum = c2 + f31;
                f32 mid = sum * lbl_805A3600;
                f32 cosine = (f32)cos(*(f32*)(a0 + 0x1c));
                f32 normalization = mid / (mid + -cosine);
                factor = *(f32*)(a0 + 0x24);
                f30 *= factor;
                f27 *= factor;
                f5 = f30 * f28;
                f0 = *(f32*)(a0 + 0x20) + (lbl_805A35E4 + (f27 * f28
                    + normalization * (lbl_805A35E4 - f28)));
            }
            break;

        case 0: {
            if (!lbl_805A05D4) {
                f32 value = lbl_805A35EC + *(f32*)(a0 + 0x14);
                lbl_805A05D4 = 1;
                lbl_805A05D0 = value;
            }
            if (!lbl_805A05DC) {
                f32 value = -*(f32*)(a0 + 0x14);
                lbl_805A05DC = 1;
                lbl_805A05D8 = value;
            }
            if (!lbl_805A05E4) {
                lbl_805A05E0 = *(f32*)(a0 + 0x14);
                lbl_805A05E4 = 1;
            }
            if (!lbl_805A05EC) {
                f32 value = lbl_805A35F4 - *(f32*)(a0 + 0x14);
                lbl_805A05EC = 1;
                lbl_805A05E8 = value;
            }

            f32 shift, spread;
            if (f31 < lbl_805A05D0) {
                if (lbl_805A35EC == lbl_805A05D0) {
                    shift = lbl_805A35F0;
                } else {
                    f32 denominator = lbl_805A35EC - lbl_805A05D0;
                    shift = (f31 * lbl_805A35E4) / denominator
                        + (lbl_805A35F4 - lbl_805A05D0 * lbl_805A35DC)
                            / denominator;
                }
                spread = lbl_805A35E4;
            } else if (f31 < lbl_805A05D8) {
                shift = lbl_805A35FC;
                if (lbl_805A05D0 == lbl_805A05D8) {
                    spread = lbl_805A35DC;
                } else {
                    f32 denominator = lbl_805A05D0 - lbl_805A05D8;
                    spread = (f31 * lbl_805A360C) / denominator
                        + (lbl_805A05D0 * lbl_805A35FC
                           - lbl_805A05D8 * lbl_805A35E4)
                            / denominator;
                }
            } else if (f31 < lbl_805A05E0) {
                if (lbl_805A05D8 == lbl_805A05E0) {
                    shift = lbl_805A35DC;
                } else {
                    f32 denominator = lbl_805A05D8 - lbl_805A05E0;
                    shift = (f31 * lbl_805A3608) / denominator
                        + (lbl_805A05D8 * lbl_805A35E4
                           - lbl_805A05E0 * lbl_805A35FC)
                            / denominator;
                }
                spread = lbl_805A35FC;
            } else if (f31 < lbl_805A05E8) {
                shift = lbl_805A35E4;
                if (lbl_805A05E0 == lbl_805A05E8) {
                    spread = lbl_805A35DC;
                } else {
                    f32 denominator = lbl_805A05E0 - lbl_805A05E8;
                    spread = (f31 * lbl_805A3608) / denominator
                        + (lbl_805A05E0 * lbl_805A35E4
                           - lbl_805A05E8 * lbl_805A35FC) / denominator;
                }
            } else {
                if (lbl_805A05E8 == lbl_805A35F4) {
                    shift = lbl_805A3600;
                } else {
                    f32 denominator = lbl_805A05E8 - lbl_805A35F4;
                    shift = (f31 * lbl_805A35E4) / denominator
                        + (lbl_805A05E8 * lbl_805A35DC - lbl_805A35F4)
                            / denominator;
                }
                spread = lbl_805A35E4;
            }

            spread *= *(f32*)(a0 + 0x24);
            shift *= *(f32*)(a0 + 0x24);
            f5 = shift * f28;
            f0 = lbl_805A35E4 + spread * f28;
            break;
        }

        case 3:
        default:
            f5 = lbl_805A35DC;
            f0 = f5;
            break;
        }
    }

    if ((a5 & 2) && !(*(u32*)(a4 + 4) & 2)) a1[2] = f5;
    if ((a5 & 4) && !(*(u32*)(a4 + 4) & 4)) a1[3] = f0;
    if ((a5 & 8) && !(*(u32*)(a4 + 4) & 8)) {
        f32 loss = lbl_805A35E4 - f29;
        *(s32*)(a1 + 6) = -(s32)(loss * (f32)*(s32*)(a0 + 0x10));
    }
}
