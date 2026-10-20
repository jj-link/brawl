#pragma force_active on
struct fn_27_19E40C_Obj {
    unsigned char pad[8];
    unsigned int flags : 3;
};

extern "C" {
void fn_27_19E40C(fn_27_19E40C_Obj* obj, unsigned int value) {
    obj->flags = value;
}
}
