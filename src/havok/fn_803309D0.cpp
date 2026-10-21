#pragma force_active on
extern char lbl_8041552C[];

extern "C" {
void* fn_803309D0(char* arg0) {
    char* r3 = *(char**)(arg0 + 0xC);
    if (*(signed char*)(r3 + 0x28) != -1) {
        return r3 + 0x28;
    }
    int r0 = *(int*)(r3 + 0xC);
    if (r0 == 1) {
        return lbl_8041552C + 0x26;
    }
    if (r0 == 2) {
        return lbl_8041552C + 0x32;
    }
    return 0;
}
}
