#pragma force_active on

struct Obj {
    unsigned char pad[0x71];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
};

extern "C" void* lbl_805A0360;
extern "C" void fn_80112E50(void*, Obj*);

extern "C" void fn_80135910(Obj* obj) {
    fn_80112E50(lbl_805A0360, obj);
    obj->flag5 = 0;
}
