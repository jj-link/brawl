#pragma force_active on
extern "C" void fn_120_9CC4(void*, void*, void*);

extern "C" void* fn_120_9DF0(void* arg0, void* arg1) {
    void* result[4];
    fn_120_9CC4(&result[0], arg0, arg1);
    return &result[0];
}
