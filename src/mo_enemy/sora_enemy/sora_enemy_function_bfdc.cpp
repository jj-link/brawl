#pragma force_active on
extern "C" void fn_41_BEB0(void*, void*, unsigned int);

extern "C" void* fn_41_BFDC(void* a, unsigned int b) {
    float result[3];
    fn_41_BEB0(result, a, b);
    return result;
}
