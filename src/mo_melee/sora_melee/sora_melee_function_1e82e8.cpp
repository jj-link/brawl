#pragma force_active on
extern char lbl_27_data_47BE0[];
extern void* lbl_27_bss_5278[];
extern char lbl_27_bss_54EC[];

struct Object {
    void* vtable;
    unsigned char flag;
    void* other;
};

extern "C" Object* fn_27_1E82E8(Object* self, bool flag) {
    self->flag = flag;
    self->other = lbl_27_data_47BE0;
    self->vtable = lbl_27_data_47BE0 + 8;

    if (lbl_27_bss_5278[0] == 0) {
        for (unsigned int i = 0; i < 154; ++i)
            lbl_27_bss_5278[i] = lbl_27_bss_54EC;
    }

    return self;
}
