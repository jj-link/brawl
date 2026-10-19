#pragma force_active on
extern "C" void* fn_8008F368(void* p);

extern "C" void* fn_27_1241C(char* p) {
    void* r = *(void**)(p + 0x28);
    if (r != 0) {
        return fn_8008F368(r);
    }
    void* q = *(void**)(p + 0x2c);
    if (q != 0) {
        return fn_8008F368(*(void**)q);
    }
    return 0;
}
