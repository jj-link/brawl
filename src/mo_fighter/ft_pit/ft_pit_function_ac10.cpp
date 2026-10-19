#pragma force_active on
extern "C" void fn_112_AC64(void*, void*, void*);

extern "C" unsigned int* fn_112_AC10(unsigned int* a, void* b) {
    unsigned int result[4];
    fn_112_AC64(result, a, b);
    a[1] = result[0];
    a[2] = result[1];
    a[3] = result[2];
    return &a[1];
}
