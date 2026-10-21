#pragma force_active on

extern "C" {
extern const float lbl_805A3F38;
extern const float lbl_805A3F3C;
}

extern "C" void fn_802B1B08(void* arg0, float farg1, float farg2) {
    float* p = (float*)((char*)arg0 + 0x18);
    if (*p == farg1) {
        *p = farg2;
        return;
    }
    float a = lbl_805A3F38;
    float b = lbl_805A3F3C;
    *(float*)((char*)arg0 + 0x2c) = a;
    *p = b;
    *(float*)((char*)arg0 + 0x28) = a;
    *(float*)((char*)arg0 + 0x24) = a;
    *(float*)((char*)arg0 + 0x20) = a;
}
