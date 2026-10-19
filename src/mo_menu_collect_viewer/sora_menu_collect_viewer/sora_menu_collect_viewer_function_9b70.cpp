#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" int fn_6_9B70(char* self) {
    if (fn_800B61C0(*(void**)(self + 0x40))) {
        int ret = 7;
        if (*(int*)(self + 0x72c) <= 0) {
            ret = 6;
        }
        return ret;
    }
    return *(int*)(self + 0x124);
}
