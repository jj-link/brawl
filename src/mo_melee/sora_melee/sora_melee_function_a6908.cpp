#pragma force_active on
typedef unsigned char u8;

struct Flags45 {
    u8 pad[0x45];
    u8 f : 1;
};

extern "C" {
void fn_27_A6908(Flags45* p, bool flag) {
    p->f = flag;
}
}
