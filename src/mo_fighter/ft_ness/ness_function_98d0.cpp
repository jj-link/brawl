#pragma force_active on
extern "C" unsigned char lbl_27_data_8E80[];

struct FtFalcoLikeState {
    void* vtbl;
    void* owner;
    int f8;
    int fC;
    int f10;
    int f14;
};

extern "C" void fn_101_98D0(FtFalcoLikeState* self, void* owner) {
    int tmp[2];
    int* p = tmp;
    self->vtbl = lbl_27_data_8E80;
    self->owner = owner;
    self->f8 = 0;
    p[0] = 0;
    self->fC = -1;
    self->f10 = -1;
    self->f14 = p[0];
}
