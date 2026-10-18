#pragma force_active on
extern "C" void* fn_10_7600(char* self, void** out) {
    if (out != 0) {
        *out = *(void**)(self + 0xa8);
    }
    return *(void**)(self + 0xa4);
}
