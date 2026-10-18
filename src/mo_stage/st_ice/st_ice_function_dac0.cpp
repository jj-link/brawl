#include <snd/snd_id.h>
#pragma force_active on

extern "C" const float lbl_62_rodata_168;
extern "C" const float lbl_62_rodata_170;

class snd3DGenerator {
public:
    void playSE(SndID, int, int, int);
};

extern "C" void fn_62_DAC0(void* object) {
    float* value = (float*)((char*)object + 0x180);
    if (lbl_62_rodata_168 == *value) {
        ((snd3DGenerator*)((char*)object + 0x188))->playSE((SndID)0x1c85, 0, 0, -1);
    }
    *value = lbl_62_rodata_170;
}
