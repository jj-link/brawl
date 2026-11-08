#include <types.h>
#pragma force_active on
#define UNUSED(n) virtual void unused##n();
struct VA { UNUSED(0) UNUSED(1) UNUSED(2) UNUSED(3) UNUSED(4) UNUSED(5) UNUSED(6) UNUSED(7) UNUSED(8) UNUSED(9) UNUSED(10) UNUSED(11) UNUSED(12) UNUSED(13) UNUSED(14) UNUSED(15) virtual s32 getKind(); };
struct GFBase { char pad[0x3c]; };
struct GF : GFBase { UNUSED(0) UNUSED(1) UNUSED(2) UNUSED(3) UNUSED(4) UNUSED(5) UNUSED(6) UNUSED(7) UNUSED(8) UNUSED(9) UNUSED(10) UNUSED(11) UNUSED(12) UNUSED(13) UNUSED(14) UNUSED(15) UNUSED(16) UNUSED(17) UNUSED(18) UNUSED(19) UNUSED(20) UNUSED(21) UNUSED(22) UNUSED(23) UNUSED(24) UNUSED(25) UNUSED(26) UNUSED(27) UNUSED(28) UNUSED(29) UNUSED(30) UNUSED(31) UNUSED(32) UNUSED(33) UNUSED(34) UNUSED(35) UNUSED(36) UNUSED(37) UNUSED(38) UNUSED(39) virtual s32 getStatus(); };
struct Act4 { UNUSED(0) UNUSED(1) UNUSED(2) UNUSED(3) virtual s32 f4(u32 x, void* p); };
struct Act3 { UNUSED(0) UNUSED(1) UNUSED(2) virtual s32 f3(); };
struct Act13 { UNUSED(0) UNUSED(1) UNUSED(2) UNUSED(3) UNUSED(4) UNUSED(5) UNUSED(6) UNUSED(7) UNUSED(8) UNUSED(9) UNUSED(10) UNUSED(11) UNUSED(12) virtual u64 f13(s16* p); };
extern "C" u32* fn_27_14554C(void*, u32, u32);
extern char g_ftCommonDataAccesser[];
extern f32 lbl_27_rodata_1F14;
extern "C" s32 fn_27_155C40(void* p1, u8* arg1, void* p3, u8* arg2) {
    VA* va = *(VA**)(*(u8**)(arg1 + 0xd8) + 0x70);
    s32 kind = va->getKind();
    GF* gf = *(GF**)(arg1 + 0x8);
    s32 status = gf->getStatus();
    u32* p = fn_27_14554C(g_ftCommonDataAccesser, status, kind);
    if ((p[1] >> 28) & 1) return 0;
    if (kind != 0xC3) {
        if ((*(Act4**)(*(u8**)(arg1 + 0xd8) + 0x64))->f4(0x10000012, *(u8**)(arg1 + 0xd8)) <= 0) {
            if ((*(Act3**)(*(u8**)(arg1 + 0xd8) + 0x14))->f3() == 2) {
                s32 flag = 0;
                if (*(s8*)(arg2 + 0xe) < -1) {
                    s16 local = -1;
                    u64 ret = (*(Act13**)(*(u8**)(arg1 + 0xd8) + 0x7c))->f13(&local);
                    if (*(float*)((u8*)&ret + 4) < lbl_27_rodata_1F14) flag = 1;
                }
                if (flag) return 1;
            } else {
                if ((*(Act3**)(*(u8**)(arg1 + 0xd8) + 0x14))->f3() == 0 && *(s8*)(arg2 + 0xe) < -1) return 1;
            }
        }
    }
    return 0;
}