#pragma force_active on
struct Fn27_1A2950_Arg {
    int field0;
    int field4;
    int field8;
};

extern "C" int fn_27_1A2950(Fn27_1A2950_Arg* p) {
    return p->field8 >> 28;
}
