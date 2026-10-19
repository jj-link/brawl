#pragma force_active on
extern "C" void fn_120_9CC4(void*, void*, void*);

extern "C" void* fn_120_9C70(void* arg0, void* arg1) {
    void* result[3];
    fn_120_9CC4(&result[0], arg0, arg1);
    ((void**)arg0)[1] = result[0];
    ((void**)arg0)[2] = result[1];
    ((void**)arg0)[3] = result[2];
    return &((void**)arg0)[1];
}
