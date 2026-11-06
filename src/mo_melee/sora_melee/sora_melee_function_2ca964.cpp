#pragma force_active on
extern const float lbl_27_rodata_6078[];

extern "C" void fn_27_2CA964(void* arg0, float* arg1, float* arg2, int arg3) {
    unsigned char* p = (unsigned char*)arg0;
    const float* data = lbl_27_rodata_6078;
    switch (arg3) {
    case 1:
        if (p[0x44] == 0) {
            *arg1 = data[0x1E0 / 4];
            *arg2 = data[0x1E4 / 4];
            return;
        }
        *arg1 = data[0x1E8 / 4];
        *arg2 = data[0x1E4 / 4];
        return;
    case 0:
        *arg1 = data[0x1EC / 4];
        *arg2 = data[0x1F0 / 4];
        return;
    default:
        *arg1 = data[0x1F4 / 4];
        *arg2 = data[0x1F8 / 4];
        if (*(int*)(p + 0x43A4) == 0) {
            float value = *(float*)(p + 0x4328);
            *arg2 = data[0x1F8 / 4] - (data[0x1FC / 4] * value);
        }
        return;
    }
}
