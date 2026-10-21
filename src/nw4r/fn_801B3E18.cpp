#pragma force_active on
extern "C" {

struct Obj {
    int pad0[2];
    int x8;
    int padC[2];
    int x14;
    int pad18[2];
    int x20;
};

extern void fn_801B3FBC(Obj*, int, int, int, int);

void fn_801B3E18(Obj* obj, int arg) {
    int v = obj->x20;
    if (v == 0) {
        return;
    }
    fn_801B3FBC(obj, v, obj->x14, obj->x8, arg);
}

}
