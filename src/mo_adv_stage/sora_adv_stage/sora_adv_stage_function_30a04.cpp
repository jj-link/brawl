#pragma force_active on
typedef struct Obj {
    int pad[2];
    int field;
} Obj;

extern "C" int fn_40_30A04(Obj* p) {
    return (int)((p->field << 5) & 0xFC000000) >> 27;
}
