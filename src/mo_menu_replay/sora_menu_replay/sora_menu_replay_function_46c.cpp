#include <mu/mu_msg.h>
#pragma force_active on
extern "C" void fn_6_1ECC(void*, unsigned int);
extern "C" float lbl_7_rodata_4;

extern "C" void fn_7_46C(void* self, unsigned int flags) {
    char* s = (char*)self;
    fn_6_1ECC(self, flags);
    char* p = *(char**)(s + 0x1ac);
    (*(MuMsg**)(p + 0x1c7c))->attachScnMdlSimple(0x11, *(nw4r::g3d::ScnMdlSimple**)(*(char**)(p + 0x168) + 0x10), 0, lbl_7_rodata_4);
    (*(MuMsg**)(*(char**)(s + 0x1ac) + 0x1c7c))->setFontColor(0x11, 0, 0, 0, 0xff);
    for (int i = 0; i < 4; i++) {
        char* p = *(char**)(s + 0x1ac);
        unsigned int index = i + 0x12;
        (*(MuMsg**)(p + 0x1c7c))->attachScnMdlSimple(index, *(nw4r::g3d::ScnMdlSimple**)(*(char**)(p + 0x16c + i * 4) + 0x10), 0, lbl_7_rodata_4);
        (*(MuMsg**)(*(char**)(s + 0x1ac) + 0x1c7c))->setFontColor(index, 0, 0, 0, 0xff);
        (*(MuMsg**)(*(char**)(s + 0x1ac) + 0x1c7c))->setAlignMode(index, MuMsg::Align_Center);
    }
}