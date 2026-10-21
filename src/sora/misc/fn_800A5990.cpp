extern float lbl_805A1F90;
extern float lbl_805A1FF8;

#pragma force_active on
extern "C" void fn_800A5990(char* arg0, float* arg1)
{
    char* r5 = *(char**)arg0;
    if (r5 != 0) {
        float a = *arg1;
        float f1 = lbl_805A1FF8 * a;
        *(float*)(arg0 + 0x134) = lbl_805A1F90;
        *(float*)(arg0 + 0x130) = f1;
        *(float*)(r5 + 0xC0) = f1;
        *(float*)(r5 + 0xC4) = *(float*)(arg0 + 0x134);
    }
}
