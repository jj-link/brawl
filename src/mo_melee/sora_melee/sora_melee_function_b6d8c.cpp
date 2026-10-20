#pragma force_active on
struct fn_27_B6D8C_Obj {
    unsigned char pad[0x44];
    unsigned char flag : 1;
};

extern "C" {
void fn_27_B6D8C(fn_27_B6D8C_Obj* obj, unsigned char val) {
    obj->flag = val;
}
}
