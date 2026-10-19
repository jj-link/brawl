#pragma force_active on
extern "C" void fn_110_9B10(void*, void*, void*);

extern "C" void* fn_110_9C3C(void* a, void* b) {
    unsigned char result[24];
    fn_110_9B10(result, a, b);
    return result;
}
