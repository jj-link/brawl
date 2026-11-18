#pragma force_active on
#include <types.h>

extern "C" {
extern const float lbl_27_rodata_2B80[];
extern void* lbl_27_bss_551C;
float randf__Fv();
s32 fn_80041978(float*, float*);
s8 fn_27_1F0278(void*, void*, void*, s8, float, float);
}

inline s32 checkMask(void* obj, s32 index) {
    if ((*(u32*)((char*)obj + 0x40) & 0x800) &&
        (index < 0 || index >= 8 ||
         (*(u8*)((char*)obj + 0x3e) & (1 << index))))
        return 1;
    else
        return 0;
}

inline void setEdge(float* out, float a, float b, float x, float y) {
    out[1] = b;
    out[0] = a;
    out[2] = x;
    out[3] = y;
}

inline void bounds(float* out, float* e) {
    {
        register float p5, p4, t3, p2, p1, t0;
        p4 = e[2];
        p5 = e[0];
        p1 = e[3];
        p2 = e[1];
        asm { ps_sub t3, p5, p4 }
        asm { ps_sub t0, p2, p1 }
        asm { ps_sel t3, t3, p4, p5 }
        asm { ps_sel t0, t0, p1, p2 }
        out[0] = t3;
        out[1] = t0;
    }
    {
        register float p5, p4, t3, p2, p1, t0;
        p4 = e[2];
        p5 = e[0];
        p1 = e[3];
        p2 = e[1];
        asm { ps_sub t3, p5, p4 }
        asm { ps_sub t0, p2, p1 }
        asm { ps_sel t3, t3, p5, p4 }
        asm { ps_sel t0, t0, p2, p1 }
        out[2] = t3;
        out[3] = t0;
    }
}

extern "C" s32 fn_27_1EFE3C(
    void* arg0, void* arg1, void* arg2, s32 arg3,
    float farg0, float farg1, float farg2
) {
    const float* c = lbl_27_rodata_2B80;
    float edge[4];
    s32 r30;
    s8 r3;

    if (farg0 < c[33] * (((float*)arg1)[6] + ((float*)arg1)[8]))
        r30 = 1;
    else
        r30 = -1;

    if (!arg1 || !arg2)
        return 0;

    if (randf__Fv() < c[85])
        r30 = -r30;

    if (*(u8*)((char*)arg0 + 0x149)) {
        s32 valid = 1;
        if (r30 > 0) {
            setEdge(edge,
                    ((float*)arg1)[8] - c[86],
                    ((float*)arg1)[9],
                    c[86] + ((float*)arg2)[6],
                    ((float*)arg2)[7]);
        } else {
            setEdge(edge,
                    c[86] + ((float*)arg1)[6],
                    ((float*)arg1)[7],
                    ((float*)arg2)[8] - c[86],
                    ((float*)arg2)[9]);
        }

        u32 flags = *(u32*)((char*)arg1 + 0x40);
        if ((flags & 0x1000) || checkMask(arg1, arg3)) {
            if (r30 > 0) {
                if (edge[0] > edge[2])
                    valid = 0;
            } else if (edge[0] < edge[2]) {
                valid = 0;
            }
        }

        if (valid) {
            u32 j;
            float* e = (float*)((char*)arg0 + 0x1ec);
            for (u32 i = 8; i < 24; ++i, e += 5) {
                if (arg3 >= 0 && *(s32*)(e + 4) == arg3)
                    continue;

                u8 flag = *(u8*)((s32)arg0 + (s32)i + 0x32c);
                if (flag && !(flag & 4)) {
                    float box[4];
                    bounds(box, e);
                    if (fn_80041978(box, edge))
                        return 0;
                }
            }

            switch (*(s32*)((char*)arg0 + 0x370)) {
            case 21: {
                arg3 = (s32)((char*)arg0 + 0x14c);
                for (j = 0; (s32)j < 8; ++j, arg3 += 0x14) {
                    if (*(u8*)((s32)arg0 + (s32)j + 0x32c)) {
                        float box[4];
                        bounds(box, (float*)arg3);
                        if (fn_80041978(box, edge))
                            return 0;
                    }
                }
                break;
            }
            default:
                break;
            }
        }
    }

    r30 = r30 - r30 * 2;
    r3 = fn_27_1F0278(arg0, arg1, arg2, (s8)r30, farg1, farg2);
    if (r3 == 0) {
        r30 = r30 - r30 * 2;
        r3 = fn_27_1F0278(arg0, arg1, arg2, (s8)r30, farg1, farg2);
        if (r3 == 0)
            r30 = 0;
    }

    switch ((s8)(r3 < 0 ? -r3 : r3)) {
    case 15:
    case 16:
        *(void**)((char*)arg2 + 0x38) = lbl_27_bss_551C;
        if (farg0 < c[33] *
            (((float*)lbl_27_bss_551C)[11] +
             ((float*)lbl_27_bss_551C)[13]))
            r30 = 1;
        else
            r30 = -1;
        break;

    default:
        if (r3 != 0) {
            if (r3 > 0) {
                if (farg0 < ((float*)arg2)[8])
                    r30 = 1;
                else
                    r30 = -1;
            } else {
                if (farg0 < ((float*)arg2)[6])
                    r30 = 1;
                else
                    r30 = -1;
            }
        }
        *(void**)((char*)arg2 + 0x38) = arg1;
        break;
    }

    *(s8*)((char*)arg2 + 0x3c) = r3;
    *(s8*)((char*)arg2 + 0x3d) = r30;
    return r3 != 0;
}
