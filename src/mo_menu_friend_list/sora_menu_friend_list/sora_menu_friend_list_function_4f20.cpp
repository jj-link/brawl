#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" int fn_14_4F20(char* self) {
    if (fn_800B61C0(*(void**)(self + 0x9c))) {
        return 7;
    }
    return *(int*)(self + 0x24c4);
}
