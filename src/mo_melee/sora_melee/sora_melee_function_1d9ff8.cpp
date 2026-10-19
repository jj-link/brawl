#pragma force_active on
typedef unsigned char u8;

struct fn_27_Obj {
    u8 pad[0xA4];
    u8 flag0 : 1;
    u8 flag1 : 1;
    u8 flag2 : 1;
    u8 flag3 : 1;
    u8 flag4 : 1;
    u8 flag5 : 1;
    u8 flag6 : 1;
    u8 flag7 : 1;
};

extern "C" void fn_27_4AB8(fn_27_Obj* obj);

extern "C" void fn_27_1D9FF8(fn_27_Obj* obj) {
    fn_27_4AB8(obj);
    obj->flag0 = 0;
}
