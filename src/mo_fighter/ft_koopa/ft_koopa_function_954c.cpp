#pragma force_active on
extern "C" void fn_102_9420(void* out, void* a, void* b);

extern "C" void* fn_102_954C(void* a, void* b) {
    char buf[24];
    fn_102_9420(buf, a, b);
    return buf;
}
