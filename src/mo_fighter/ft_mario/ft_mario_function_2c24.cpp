#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_8E80[];

struct FtMarioObj12 {
    void* vtbl;
    void* arg;
    int zero;
    int neg1a;
    int neg1b;
    int zero2;
};

void fn_91_2C24(FtMarioObj12* self, void* arg) {
    int local;
    self->vtbl = lbl_27_data_8E80;
    self->arg = arg;
    self->zero = 0;
    local = 0;
    self->neg1a = (int)&local;
    self->neg1a = -1;
    self->neg1b = -1;
    self->zero2 = 0;
}
}
