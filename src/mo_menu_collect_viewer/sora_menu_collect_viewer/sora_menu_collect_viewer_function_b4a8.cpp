#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" int fn_6_B4A8(void* self) {
    if (fn_800B61C0(*(void**)((char*)self + 0x40))) {
        return 3;
    }
    return *(int*)((char*)self + 0x128);
}
