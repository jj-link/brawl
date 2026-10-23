#pragma force_active on
extern "C" {
extern float lbl_805A3E00;

void fn_802921B0(unsigned char* arg0, float* arg1) {
    int flags = *arg0;
    if (flags != 0) {
        float v = lbl_805A3E00;
        for (int i = 0; i < 3; ++i) {
            if ((flags >> (i << 1)) & 3) {
                arg1[12 + i * 4 + 3] = v;
                arg1[12 + i * 4 + 2] = v;
                arg1[12 + i * 4 + 1] = v;
                arg1[12 + i * 4] = v;
                arg1[36 + i * 4 + 3] = v;
                arg1[36 + i * 4 + 2] = v;
                arg1[36 + i * 4 + 1] = v;
                arg1[36 + i * 4] = v;
            }
            flags = *arg0;
        }
    }
}
}
