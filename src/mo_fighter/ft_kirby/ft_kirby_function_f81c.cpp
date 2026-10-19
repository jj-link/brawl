#pragma force_active on
struct F6F0Arg1;

extern "C" void fn_96_F6F0(void* result, F6F0Arg1* arg1, int arg2);

extern "C" void* fn_96_F81C(F6F0Arg1* arg1, int arg2) {
    unsigned char result[24];
    fn_96_F6F0(result, arg1, arg2);
    return result;
}
