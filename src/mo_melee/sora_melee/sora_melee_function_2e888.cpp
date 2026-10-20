#pragma force_active on
extern "C" void fn_80133B98(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_2E68[];

struct fn_27_2E888_obj {
    unsigned int unk0;
    void* unk4;
    unsigned char pad8[0x38];
    void* unk40;
};

extern "C" {
fn_27_2E888_obj* fn_27_2E888(fn_27_2E888_obj* p, int flag) {
    if (p) {
        p->unk40 = lbl_27_data_2E68;
        fn_80133B98(p->unk4, 1);
        p->unk4 = 0;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
