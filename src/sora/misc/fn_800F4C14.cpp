#pragma force_active on
extern "C" {
int fn_800F4C14(char* self) {
    char* p = *(char**)(self + 0xAC);
    if (*(int*)(p + 0x350) == 0) {
        return 0;
    }
    return *(int*)(self + 0x60);
}
}
