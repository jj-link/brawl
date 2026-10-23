#pragma force_active on
extern "C" {
extern float lbl_805A4348;
extern float lbl_805A434C;
extern float lbl_805A4350;
}

extern "C" void fn_802E2378(void* arg0, void* arg1) {
    float* src = (float*)arg1;
    float a = src[1];
    float c = src[2];
    float b = src[0];
    b = (b < a) ? b : a;
    b = (b < c) ? b : c;
    if (b < lbl_805A4348) {
        *(float*)((char*)arg0 + 0x20) = lbl_805A434C * b;
        return;
    }
    *(float*)((char*)arg0 + 0x20) = lbl_805A4350;
}
