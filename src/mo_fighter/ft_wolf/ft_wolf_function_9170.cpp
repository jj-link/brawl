#pragma force_active on
extern "C" void fn_125_7F88(void* self, unsigned char v);
extern "C" char lbl_125_data_24E0[0x70];

struct FtWolfObj {
    void* vt0;      // +0x00 (lbl_125_data_24E0 + 8)
    int pad04;      // +0x04
    void* vt8;      // +0x08 (lbl_125_data_24E0)
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

extern "C" FtWolfObj* fn_125_9170(FtWolfObj* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    fn_125_7F88(self, 0);
    self->vt8 = lbl_125_data_24E0;
    self->vt0 = lbl_125_data_24E0 + 8;
    self->f0c = a1;
    self->f10 = a2;
    self->f14 = a3;
    self->f18 = a4;
    self->f1c = a5;
    self->f20 = a6;
    return self;
}
