#pragma force_active on
struct Obj {
    char pad[8];
    int unk8;
};

extern "C" char* fn_8029E6D4(Obj* arg0, char* arg1) {
    int n = arg0->unk8;
    int t = (n * 4) - n;
    return arg1 + t * 0x30 + (t << 5) + n * 0x3C0 + ((n + 1) << 5) + (n << 5);
}
