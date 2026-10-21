#pragma force_active on
extern "C" int fn_801B8FE4(void* obj);

extern "C" int fn_801D17DC(void* self) {
    void* a = *(void**)((char*)self + 0x0C);
    if (a != 0) {
        return fn_801B8FE4(a);
    }
    return 0;
}
