#include <types.h>
#pragma force_active on

struct Vec3f;

void cmReqQuake(int id, Vec3f* vec);

extern "C" {
extern s32 lbl_27_rodata_DE8[];

void fn_27_B496C(u8* self, long kind, Vec3f* vec) {
    u8 flags = self[0x14];
    if (!((flags >> 5) & 1)) {
        return;
    }
    if (kind == 3) {
        if (((flags >> 6) & 1u) == 1) {
            return;
        }
        self[0x14] = flags | 0x40;
    }
    cmReqQuake(lbl_27_rodata_DE8[kind], vec);
}
}
