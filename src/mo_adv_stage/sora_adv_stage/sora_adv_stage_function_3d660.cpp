#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_260604(void* obj, unsigned int flag, int v);

struct Obj {
    u8 pad[0x40];
    int m40;
    u8 pad2[0x6c - 0x44];
    u8 b0 : 1;
    u8 b1 : 1;
};

extern "C" void fn_40_3D660(void* obj, unsigned int flag) {
    Obj* p = (Obj*)obj;
    if (p->m40 != 0) {
        fn_27_260604(obj, flag, 0);
        p->b1 = flag;
    }
}
