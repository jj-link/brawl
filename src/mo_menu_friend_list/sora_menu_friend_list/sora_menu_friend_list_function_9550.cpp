#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" int fn_14_9550(char* self) {
    if (fn_800B61C0(*(void**)(self + 0xc8))) {
        return 0x1e;
    }
    return *(int*)(self + 0x24c4);
}
