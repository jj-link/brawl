#pragma force_active on
extern "C" void __ct__21ftExtendParamAccesserF6ftKind(void* self, int kind);
extern "C" char lbl_113_data_48[];

struct fn_113_Obj {
    void* vtbl;
    int pad;
    void* data;
};

extern "C" void* fn_113_FDF4(void* self) {
    __ct__21ftExtendParamAccesserF6ftKind(self, 0x19);
    fn_113_Obj* obj = (fn_113_Obj*)self;
    obj->data = lbl_113_data_48;
    obj->vtbl = lbl_113_data_48 + 8;
    return self;
}
