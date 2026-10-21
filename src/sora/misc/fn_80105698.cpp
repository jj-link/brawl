#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" int fn_80105698(char* self) {
    if (fn_800B61C0(*(void**)(self + 0x4))) {
        return *(int*)(self + 0xDC);
    }
    return 2;
}
