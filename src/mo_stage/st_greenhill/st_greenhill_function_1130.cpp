#include <gr/gr_yakumono.h>
#pragma force_active on

struct GreenHillGround : grYakumono {
    unsigned char unk150;
    float unk154;
};

extern "C" void __ct__10grYakumonoFPCc(GreenHillGround*, const char*);
extern "C" unsigned char lbl_72_data_7E8[];
extern "C" const float lbl_72_rodata_38;

extern "C" GreenHillGround* fn_72_1130(GreenHillGround* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(void**)((unsigned char*)self + 0x3c) = lbl_72_data_7E8;
    self->unk150 = 0;
    self->unk154 = lbl_72_rodata_38;
    self->setupMelee();
    return self;
}
