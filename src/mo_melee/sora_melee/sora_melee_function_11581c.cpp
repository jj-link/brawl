#pragma force_active on
struct fn_27_Obj {
    char pad[0xc];
    unsigned char unk_c;
};

extern "C" {
int fn_27_11581C(fn_27_Obj* p) {
    return p->unk_c == 6;
}
}
