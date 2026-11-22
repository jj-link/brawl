#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

extern "C" {
void* fn_8018ECCC(void* self, const char* name);
void* fn_801A4DB8(void);
void fn_801EC1B8(void* a, void* b, void* c);
}
extern char lbl_8059E8F8;
extern const f32 lbl_805A334C;

extern "C" void fn_801A5414(u8* arg0, u32* arg1, nw4r::g3d::ResMdl* arg2, u8* arg3)
{
    u8* p;
    u8* base2;
    u32 dst, cnt, i, idx, d25;
    union {
        u32 u;
        f32 f;
    } wu;
    register f32 acc0, acc1, acc2, acc3, acc4, acc5, w;
    register f32 m0, m1, m2, m3, m4, m5;
    register u8* mp;
    register u8* output;

    if ((p = arg3) == 0) {
        p = (u8*)fn_8018ECCC(arg2, &lbl_8059E8F8);
        if (p == 0) {
            return;
        }
    }
    base2 = (u8*)fn_801A4DB8();
    while (*p != 1) {
        if (*p == 3) {
            dst = ((u32)p[1] << 8) + p[2];
            cnt = p[3];
            p += 4;
            arg1[dst] = 0xF0000000;
            acc0 = lbl_805A334C;
            asm {
                ps_merge00 acc0, acc0, acc0
                ps_merge00 acc1, acc0, acc0
                ps_merge00 acc2, acc0, acc0
                ps_merge00 acc3, acc0, acc0
                ps_merge00 acc4, acc0, acc0
                ps_merge00 acc5, acc0, acc0
            }
            for (i = 0; i < cnt; i++) {
                idx = ((u32)p[0] << 8) + p[1];
                wu.u = ((u32)p[2] << 24) | ((u32)p[3] << 16) | ((u32)p[4] << 8) | p[5];
                w = wu.f;
                mp = base2 + idx * 0x30;
                asm {
                    psq_l m0, 0(mp), 0, 0
                    psq_l m1, 8(mp), 0, 0
                    psq_l m2, 16(mp), 0, 0
                    psq_l m3, 24(mp), 0, 0
                    psq_l m4, 32(mp), 0, 0
                    psq_l m5, 40(mp), 0, 0
                    ps_madds0 acc0, m0, w, acc0
                    ps_madds0 acc1, m1, w, acc1
                    ps_madds0 acc2, m2, w, acc2
                    ps_madds0 acc3, m3, w, acc3
                    ps_madds0 acc4, m4, w, acc4
                    ps_madds0 acc5, m5, w, acc5
                }
                arg1[dst] &= arg1[idx];
                p += 6;
            }
            output = arg0 + dst * 0x30;
            asm {
                psq_st acc0, 0(output), 0, 0
                psq_st acc1, 8(output), 0, 0
                psq_st acc2, 16(output), 0, 0
                psq_st acc3, 24(output), 0, 0
                psq_st acc4, 32(output), 0, 0
                psq_st acc5, 40(output), 0, 0
            }
        } else {
            d25 = ((u32)p[1] << 8) + p[2];
            fn_801EC1B8(arg0 + d25 * 0x30,
                         (u8*)arg2->GetResNode((u32)(((u32)p[3] << 8) + p[4])).ptr() + 0xA0,
                         base2 + d25 * 0x30);
            p += 5;
        }
    }
}
