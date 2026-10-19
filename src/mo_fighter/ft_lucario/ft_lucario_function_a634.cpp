#pragma force_active on
extern "C" void fn_118_A688(void*, void*, void*);

extern "C" void* fn_118_A634(void* self, void* b) {
    unsigned int result[3];
    fn_118_A688(result, self, b);
    unsigned int* p = static_cast<unsigned int*>(self);
    p[1] = result[0];
    p[2] = result[1];
    p[3] = result[2];
    return p + 1;
}
