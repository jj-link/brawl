#pragma force_active on
struct Obj {
    char pad[8];
    int field8;
};

extern "C" char* fn_49_6BD8(Obj* obj, int index) {
    int n = (obj->field8 >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return (char*)obj + n * 0xa0 + 0xc;
}
