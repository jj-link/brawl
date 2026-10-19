#pragma force_active on
struct F6F0Arg1;

extern "C" void fn_96_F6F0(void* result, F6F0Arg1* arg1, int arg2);

extern "C" void* fn_96_F69C(F6F0Arg1* arg1, int arg2) {
    unsigned char result[12];
    fn_96_F6F0(result, arg1, arg2);
    unsigned int* out = reinterpret_cast<unsigned int*>(arg1);
    out[1] = reinterpret_cast<unsigned int*>(result)[0];
    out[2] = reinterpret_cast<unsigned int*>(result)[1];
    out[3] = reinterpret_cast<unsigned int*>(result)[2];
    return &out[1];
}
