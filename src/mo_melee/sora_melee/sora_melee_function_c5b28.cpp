#pragma force_active on
extern "C" {
struct Obj {
    int _0;
    int _4;
    unsigned unk : 6;
    unsigned target : 1;
};

int fn_27_C5B28(Obj* obj) {
    return obj->target;
}
}
