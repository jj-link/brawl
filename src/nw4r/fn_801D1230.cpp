#pragma force_active on
extern "C" int fn_801D1230(void* self) {
    int a = *(int*)((char*)self + 0xC);
    if (a != 0) {
        return *(int*)((char*)a + 0x14);
    }
    return 0xA;
}
