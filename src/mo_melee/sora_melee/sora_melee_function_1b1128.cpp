#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" void* fn_27_1B1128(Obj* obj, int idx) {
    int n = (obj->unk8 >> 29) + idx;
    if (n >= 3) {
        n -= 3;
    }
    return (char*)obj + n * 4 + 0xc;
}
