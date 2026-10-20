#pragma force_active on
struct Obj {
    int pad0;
    int pad1;
    unsigned int mode : 2;
    unsigned int rest : 30;
};

extern "C" {
void fn_27_CD9A8(Obj *obj, unsigned int val) {
    obj->mode = val;
}
}
