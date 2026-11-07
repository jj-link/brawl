#pragma force_active on
extern "C" int fn_80210708(void* a, void* b);
extern "C" int fn_802107A8(void* a, void* b, void* c);
extern "C" int fn_80210EC8(void* a);
extern "C" int fn_80210EDC(void* a);
extern "C" void fn_80210EE4(void* a);
extern "C" int fn_803CCE1C(void* a, int b, int c, int d);
extern "C" void* fn_803CD478(void);

extern "C" int fn_80033A78(char* self, void* arg1) {
    int sp14[5];
    int sp8[3];

    if (*(int*)(self + 0xB4) == 1) {
        if (fn_80210708(arg1, sp14) != 0 && fn_802107A8(sp14, fn_803CD478(), sp8) != 0) {
            int temp_r31 = fn_80210EC8(sp8);
            int temp_r30 = fn_80210EDC(sp8);
            fn_80210EE4(sp8);
            if (fn_803CCE1C(*(void**)(self + 0x4C), temp_r31, temp_r30, 0) == 0) {
                *(int*)(self + 0xB4) = 3;
                return 1;
            }
        }
        *(int*)(self + 0xB4) = 2;
    }
    return 0;
}
