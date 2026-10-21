#pragma force_active on
extern float lbl_805A1E80;

extern "C" void fn_8009FCF4(char *arg0, float farg0)
{
    float c = lbl_805A1E80;
    *(float *)(arg0 + 0x17C) = farg0;
    *(float *)(arg0 + 0x180) = c;
}
