#pragma force_active on
struct Obj_6288 {
    int pad0;
    int pad1;
    int field8;
};

extern "C" int fn_50_6288(struct Obj_6288 *p) {
    return p->field8 >> 30;
}
