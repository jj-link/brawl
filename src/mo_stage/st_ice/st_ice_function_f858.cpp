#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" void fn_62_F858(u8* self) {
    u8* p = self + 0xD0;
    if (p != 0) {
        u8* m = *(u8**)(*(u8**)(self + 0x44));
        if (m != 0) {
            if (*(u32*)(m + 0x11C) == 0) {
                *(u32*)(p + 0xC) = 0;
                *(u8**)(m + 0x11C) = p;
                ((nw4r::g3d::ScnMdlSimple*)m)->EnableScnMdlCallbackTiming(1);
                *(u16*)(m + 0x122) = (u16)**(u32**)(p + 4);
            }
            u8* q = *(u8**)(p + 4);
            *(float*)(q + 8) = *(float*)(self + 0x178);
            *(float*)(q + 12) = *(float*)(self + 0x17C);
            *(float*)(q + 16) = *(float*)(self + 0x180);
            ((snd3DGenerator*)(self + 0x188))->setPos((Vec3f*)(self + 0x178));
        }
    }
}
