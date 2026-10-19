#include <gr/gr_yakumono.h>
#pragma force_active on

extern "C" grYakumono* __ct__10grYakumonoFPCc(grYakumono*, const char*);
extern "C" unsigned char lbl_27_data_580E4[];

extern "C" grYakumono* fn_27_272668(grYakumono* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *reinterpret_cast<unsigned char**>(reinterpret_cast<char*>(self) + 0x3C) =
        lbl_27_data_580E4;
    *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(self) + 0x150) = 0;
    *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(self) + 0xE4) = 0xE;
    return self;
}
