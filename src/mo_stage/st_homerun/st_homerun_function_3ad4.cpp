#pragma force_active on
extern "C" const float lbl_88_rodata_0[];
extern "C" void* getInstance__16CameraControllerFv();
extern "C" void fn_8009D158(void* cam, float* p);

extern "C" void fn_88_3AD4() {
    const float* c = lbl_88_rodata_0;
    float* p = (float*)((char*)getInstance__16CameraControllerFv() + 0xc4);
    if (p != 0) {
        p[0] = c[6];
        p[1] = c[51];
        p[3] = c[52];
        p[4] = c[53];
        p[5] = p[4];
        p[6] = p[4];
        p[7] = p[4];

        fn_8009D158(getInstance__16CameraControllerFv(), p);
    }
}
