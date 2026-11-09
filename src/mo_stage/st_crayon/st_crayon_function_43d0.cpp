#pragma force_active on
extern "C" {
void fn_56_46BC(char* self);
void fn_56_4780(char* self);
extern const float lbl_56_rodata_80[];
}

extern "C" void fn_56_43D0(char* self, float farg0) {
    const float* ro = lbl_56_rodata_80;
    char* p = self + 0xd0;
    if (p == 0) {
        return;
    }
    switch (*(int*)(self + 0x184)) {
    case 0: {
        fn_56_46BC(self);
        char* m = *(char**)(p + 4);
        *(float*)(self + 0x170) = *(float*)(m + 0x8);
        *(float*)(self + 0x174) = *(float*)(m + 0xc);
        if (*(float*)(m + 0x8) > ro[0]) {
            *(float*)(self + 0x178) = ro[0x18 / 4];
        } else {
            *(float*)(self + 0x178) = ro[0x1c / 4];
        }
        char* t = self + 0xd0;
        float f1 = *(float*)(self + 0x178);
        if (t != 0) {
            if (f1 > ro[0x64 / 4]) {
                if (ro[0] != *(float*)(*(char**)(t + 4) + 0x18) && *(int*)(self + 0x188) == 0) {
                    *(int*)(self + 0x188) = 1;
                }
            } else if (f1 < ro[0x68 / 4]) {
                if (ro[0x38 / 4] != *(float*)(*(char**)(t + 4) + 0x18) && *(int*)(self + 0x188) == 0) {
                    *(int*)(self + 0x188) = 1;
                }
            }
        }
        *(int*)(self + 0x184) = 1;
        break;
    }
    case 1: {
        float s = *(float*)(self + 0x178);
        char* m = *(char**)(p + 4);
        float a = s * farg0;
        *(float*)(m + 0x8) = *(float*)(m + 0x8) + a;
        m = *(char**)(p + 4);
        *(float*)(m + 0xc) = *(float*)(m + 0xc) + ro[0x84 / 4] * farg0;
        m = *(char**)(p + 4);
        if (*(float*)(m + 0xc) > ro[0x88 / 4]) {
            fn_56_4780(self);
        }
        break;
    }
    }
}