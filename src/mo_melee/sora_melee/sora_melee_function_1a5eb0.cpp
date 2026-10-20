#pragma force_active on
struct SoState {
    void *table;
    void *ptr;
    unsigned int flags;
};

extern "C" {
extern char lbl_27_data_345F0[];

void fn_27_1A5EB0(SoState *self) {
    char *base = lbl_27_data_345F0;
    self->table = base;
    self->ptr = base + 0x48;
    self->flags = self->flags & 1;
}
}
