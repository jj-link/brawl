#pragma force_active on
extern "C" {
void fn_100_6B88(void*, int);
extern char lbl_100_data_7108[];
}

struct CaptainObject {
    void* vtbl;
    int pad4;
    int field8;
    int fieldC;
};

extern "C" CaptainObject* fn_100_12E94(CaptainObject* self, int value) {
    fn_100_6B88(self, 0);
    self->vtbl = lbl_100_data_7108;
    self->field8 = value;
    self->fieldC = -1;
    return self;
}
