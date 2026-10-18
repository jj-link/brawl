#pragma force_active on
struct fn_27_C6E60_Obj {
    unsigned char pad[0x8d];
    unsigned char flag8d;
    unsigned char flag8e;
};

extern "C" {
void fn_27_C6E60(fn_27_C6E60_Obj* p) {
    if (p->flag8e != 0) {
        p->flag8d = 1;
    }
}
}
