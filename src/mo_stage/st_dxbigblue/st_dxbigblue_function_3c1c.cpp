#include <types.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" void fn_81_3C1C(u8* self, u8 flag) {
    u8* p = self;
    s32 idx = 0;
    for (s32 n = 5; n > 0; n--) {
        if (*(s32*)(p + 0xAA8) == -1) {
            s32 id;
            switch (idx) {
            case 0: id = 0x1DC9; break;
            case 1: id = 0x1DCA; break;
            case 2: id = 0x1DCB; break;
            case 3: id = 0x1DCC; break;
            case 4: id = 0x1DC9; break;
            }
            s32 off = idx << 4;
            s32 h = ((snd3DGenerator*)(self + 0xAA0 + off))->playSE((SndID)id, 0, 0x78, -1);
            *(s32*)(self + off + 0xAA8) = h;
            *(u8*)(self + off + 0xAAC) = flag;
            return;
        }
        p += 0x10;
        idx++;
    }
}