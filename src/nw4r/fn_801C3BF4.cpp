#pragma force_active on
extern "C" {
extern char lbl_804C1FD8[];

void* fn_801C3BF4(char* base, int idx) {
    if (idx < 0x10) {
        return base + idx * 2 + 0xF8;
    }
    if (idx < 0x20) {
        return lbl_804C1FD8 + (idx - 0x10) * 2;
    }
    return (void*)0;
}
}
