#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" int fn_2_390B0(char* self) {
    if (fn_800B61C0(*(void**)(self + 0x44))) {
        return 3;
    }
    return *(int*)(self + 0x138);
}
