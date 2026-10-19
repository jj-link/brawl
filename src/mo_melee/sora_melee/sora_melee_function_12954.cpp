#pragma force_active on
extern "C" int fn_80095BD4(void* obj, int arg);
extern "C" int fn_80095F78(void* obj);

extern "C" int fn_27_12954(void* self) {
    void* a = *(void**)((char*)self + 0x28);
    if (a != 0) {
        return fn_80095BD4(a, 7);
    }
    void* b = *(void**)((char*)self + 0x2c);
    if (b != 0) {
        return fn_80095F78(b);
    }
    return 0;
}
