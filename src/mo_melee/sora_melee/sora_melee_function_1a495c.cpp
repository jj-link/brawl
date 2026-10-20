#pragma force_active on
typedef unsigned int u32;

struct fnObj27 {
    char* m0;
    char* m4;
    u32 m8;
};

extern char lbl_27_data_35718[];

extern "C" void fn_27_1A495C(fnObj27* p) {
    u32 v = p->m8;
    p->m0 = lbl_27_data_35718;
    p->m4 = lbl_27_data_35718 + 0x48;
    p->m8 = v & 0x7FFFF;
}
