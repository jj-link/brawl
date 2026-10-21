#pragma force_active on

extern "C" int fn_801D7774(void* a, int b);

extern "C" int fn_8019238C(void** p) {
    char* obj = (char*)*p;
    int off = *(int*)(obj + 0x38);
    void* ptr = off != 0 ? (void*)(obj + off) : (void*)0;
    return fn_801D7774(ptr, 0x180);
}
