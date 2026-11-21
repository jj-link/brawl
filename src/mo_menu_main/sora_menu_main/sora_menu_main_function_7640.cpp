#include <types.h>
#include <mt/mt_prng.h>
#pragma force_active on
extern "C" s32 fn_80052768(s32);
typedef struct { u32 unk0; u32 unk4; u8 pad[0x1454]; u8 unk145C; } Obj;
typedef struct { u32 v; u8 pad[0x5C]; } Item;
extern "C" s32 fn_2_7640(s32 a0, Obj* a1, u16* a2, s32 total)
{
    s32 a3 = total;
    total = 0;
    u16* src = a2;
    if (a3 <= 0) {
        u16* out = src;
        for (s32 i = 0; i < (a1->unk145C ? a1->unk4 : 0); i++) {
            u32 d = ((Item*)a1->unk0)[i].v;
            if (fn_80052768(d & 0xFFFF) & 0xFFFF) {
                *out++ = (u16)i;
                total++;
            }
        }
    } else {
        u16* out = a2;
        for (u32 n = 0; n < (u32)a3; n++) {
            *out++ = (u16)(n % (a1->unk145C ? a1->unk4 : 0));
            total++;
        }
    }
    for (a3 = 0; a3 < total; a3++) {
        s32 r = randi(total);
        u16 tmp = src[a3];
        src[a3] = src[r];
        src[r] = tmp;
    }
    return total;
}
