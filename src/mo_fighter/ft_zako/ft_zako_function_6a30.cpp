#pragma force_active on
extern "C" {
extern void* lbl_126_data_1154[];

struct FtZakoObj {
    void* vtbl;
    int pad[3];
    void* f10;
    void* f14;
    void* f18;
};

void fn_126_6A30(FtZakoObj* self, void* a, void* b, void* c) {
    self->vtbl = lbl_126_data_1154;
    self->f10 = a;
    self->f14 = b;
    self->f18 = c;
}
}
