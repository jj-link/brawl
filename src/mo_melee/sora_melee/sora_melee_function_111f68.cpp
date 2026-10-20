#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct FnInner {
    u8 pad[0x1f];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 flag : 1;
    u8 f5 : 3;
};

extern "C" void fn_27_111F68(FnInner** p, u32 v) {
    FnInner* in = *p;
    in->flag = v;
}
