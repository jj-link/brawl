#pragma force_active on
extern float lbl_805A3E14;

extern "C" void fn_80294DAC(void* arg0, int arg1, int arg2, float farg0, float farg1) {
    float v = lbl_805A3E14;
    *(float*)((char*)arg0 + 0x8) = farg1;
    *(int*)((char*)arg0 + 0x0) = 0x80C0018;
    *(float*)((char*)arg0 + 0xC) = farg0;
    *(int*)((char*)arg0 + 0x4) = arg1;
    *(float*)((char*)arg0 + 0x10) = v;
    *(int*)((char*)arg0 + 0x14) = arg2;
}
