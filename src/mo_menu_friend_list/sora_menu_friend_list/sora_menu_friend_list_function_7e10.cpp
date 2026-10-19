#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" {
int fn_14_7E10(char* self) {
    if (fn_800B61C0(*(void**)(self + 0xb0))) {
        return 0x16;
    }
    return *(int*)(self + 0x24c4);
}
}
