#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_36698[];
}

struct S {
    void* p0;
    void* p4;
    unsigned int p8;
};

extern "C" void fn_27_1A3714(S* s) {
    unsigned int flag = s->p8;
    unsigned char* base = lbl_27_data_36698;
    s->p0 = base;
    s->p4 = base + 0x48;
    s->p8 = flag & 1;
}
