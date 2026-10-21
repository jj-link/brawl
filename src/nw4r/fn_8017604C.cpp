#pragma force_active on
extern "C" {
void* fn_8017604C(char* self) {
    char* p = *(char**)(self + 0x38);
    while (p != 0 && *(int*)(p + 0xc) != 1) {
        p = *(char**)(p + *(unsigned short*)(self + 0x42) + 4);
    }
    return p;
}
}
