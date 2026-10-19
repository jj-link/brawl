#include <gr/gr_yakumono.h>
#include <types.h>

#include <st_dxbigblue/gr_dxbigblue.h>
#pragma force_active on

extern "C" {
void __ct__10grYakumonoFPCc(void* self, const char* name);
extern const float lbl_76_rodata_8;
extern char lbl_76_data_650[];

grDxBigBlue* fn_76_BE0(grDxBigBlue* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    *(char**)((char*)self + 0x3c) = lbl_76_data_650;
    *(unsigned char*)((char*)self + 0x150) = 0;
    *(float*)((char*)self + 0x154) = lbl_76_rodata_8;
    self->setupMelee();
    return self;
}
}
