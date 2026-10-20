#pragma force_active on
typedef unsigned int u32;

struct SoWork {
    void* m0;
    void* m4;
    u32 m8;
};

extern char lbl_27_data_34BB8[];

extern "C" {
void fn_27_1A5794(SoWork* p) {
    u32 v = p->m8;
    char* base = lbl_27_data_34BB8;
    p->m0 = base;
    p->m4 = base + 0x48;
    p->m8 = v & 0x7FFFF;
}
}
