#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int f2 : 10;
    unsigned int f1 : 5;
    unsigned int f0 : 17;
};

extern "C" {
void fn_27_CE3E0(Obj* obj, unsigned int v) {
    obj->f1 = v;
}
}
