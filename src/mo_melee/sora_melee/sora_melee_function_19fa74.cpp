#pragma force_active on
struct Fn27Obj {
    char pad[8];
    unsigned int pad2 : 10;
    unsigned int field : 6;
};

extern "C" int fn_27_19FA74(Fn27Obj* p) {
    return (int)(p->field << 26) >> 27;
}
