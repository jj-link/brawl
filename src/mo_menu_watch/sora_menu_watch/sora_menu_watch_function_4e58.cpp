#pragma force_active on
extern "C" int fn_15_4E58(void* self) {
    if (*(int*)((char*)self + 0x4ec) != 6) {
        *(int*)((char*)self + 0x48) = 2;
        return 11;
    }
    return *(int*)((char*)self + 0x504);
}
