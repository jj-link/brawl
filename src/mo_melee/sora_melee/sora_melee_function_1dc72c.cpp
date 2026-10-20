#pragma force_active on
extern "C" {
struct Obj2 {
    int y0;
    int y4;
    int y8;
    int yC;
    int y10;
    int y14;
    int y18;
    int y1C;
    int y20;
    int y24;
};

struct Obj {
    int x0;
    int x4;
    Obj2 *x8;
};

int fn_27_1DC72C(Obj *obj) {
    return obj->x8->y24;
}
}
