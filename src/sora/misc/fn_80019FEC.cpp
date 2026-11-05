#include <gm/gm_global.h>
#pragma force_active on
extern char* lbl_8059FFC0;
extern int* lbl_805A0098;
extern const float lbl_805A1454;
extern const float lbl_805A1458;
extern "C" void fn_800384CC(int*, int);
extern "C" void fn_80018610(void*);
extern "C" char* fn_80019FEC(char* self) {
    lbl_8059FFC0 = self;
    if ((unsigned int)((((unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1) == 1) {
        float f = lbl_805A1458;
        fn_800384CC(lbl_805A0098, 1);
        *(float*)(self + 0x73c) = *(float*)((char*)lbl_805A0098 + 0x44);
        *(float*)(self + 0x738) = f;
        float v = f * *(float*)((char*)lbl_805A0098 + 0x44);
        *(float*)(self + 0xe4) = v;
        *(float*)(self + 0x218) = v;
        *(float*)(self + 0x34c) = v;
        *(float*)(self + 0x480) = v;
        *(float*)(self + 0x5b4) = v;
        *(float*)(self + 0x6e8) = v;
    } else {
        float f = lbl_805A1454;
        fn_800384CC(lbl_805A0098, 0);
        *(float*)(self + 0x73c) = *(float*)((char*)lbl_805A0098 + 0x44);
        *(float*)(self + 0x738) = f;
        float v = f * *(float*)((char*)lbl_805A0098 + 0x44);
        *(float*)(self + 0xe4) = v;
        *(float*)(self + 0x218) = v;
        *(float*)(self + 0x34c) = v;
        *(float*)(self + 0x480) = v;
        *(float*)(self + 0x5b4) = v;
        *(float*)(self + 0x6e8) = v;
    }
    char* p = self;
    for (int i = 0; i < 6; ++i, p += 0x134) {
        fn_80018610(p);
    }
    *(int*)(self + 0x5d0) = 0;
    return self;
}