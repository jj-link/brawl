#pragma force_active on
struct Fn27Obj {
    unsigned char pad[8];
    unsigned int mode : 2;
};

extern "C" {
void fn_27_C9DB8(Fn27Obj* obj, unsigned int v) {
    obj->mode = v;
}
}
