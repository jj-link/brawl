#pragma force_active on
extern "C" void fn_8015DF8C(void* self);
extern "C" unsigned char lbl_804647D0[];

extern "C" void* fn_8015E5EC(void** self) {
    fn_8015DF8C(self);
    *self = lbl_804647D0;
    return self;
}
