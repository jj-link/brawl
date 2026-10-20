#pragma force_active on
typedef unsigned int u32;

extern unsigned char lbl_27_data_35620[0x90];

struct WorkT {
    void* m0;
    void* m4;
    u32 m8;
};

extern "C" {
void fn_27_1A4A60(WorkT* w) {
    u32 t = w->m8;
    unsigned char* p = lbl_27_data_35620;
    w->m0 = p;
    w->m4 = p + 0x48;
    w->m8 = t & 0x3FF;
}
}
