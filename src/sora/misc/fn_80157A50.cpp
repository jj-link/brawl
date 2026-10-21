#pragma force_active on
struct FnObj {
    char pad[0x37C];
    unsigned char unk37C;
};

extern "C" {
void fn_80157A50(FnObj* p, int unused, int arg) {
    if (arg == 6) {
        p->unk37C = 1;
        return;
    }
    if (arg == 7) {
        p->unk37C = 1;
    }
}
}
