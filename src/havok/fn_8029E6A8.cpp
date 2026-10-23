#pragma force_active on

struct Obj {
    int pad;
    int unk4;
};

extern "C" char* fn_8029E6A8(Obj* arg0, char* arg1) {
    int n = arg0->unk4;
    return arg1 + ((n * 4 - n) * 0x30) + n * 0x90 + (n + 1) * 0x10;
}
