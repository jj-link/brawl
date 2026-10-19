#pragma force_active on
extern "C" {
extern char lbl_27_data_54428[];
void fn_27_25CEA4(void* self, int kind);
}

struct fnObj {
    void* vtbl;
};

extern "C" fnObj* fn_27_25DBC8(fnObj* self) {
    fn_27_25CEA4(self, 1);
    self->vtbl = lbl_27_data_54428;
    return self;
}
