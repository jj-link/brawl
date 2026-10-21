#pragma force_active on
extern "C" {

struct Obj {
    int x0;
    int x4;
    int x8;
    int xC;
    int x10;
    int x14;
    int x18;
    int x1C;
};

void fn_801B3FBC(void*, int, int, int, int);

void fn_801B3DF4(struct Obj* p, int a) {
    if (p->x1C == 0) return;
    fn_801B3FBC(p, p->x1C, p->x10, p->x4, a);
}

}
