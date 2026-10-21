#pragma force_active on

extern "C" void fn_123_6D30(void* object, unsigned int value);
extern "C" unsigned char lbl_123_data_782C[];

struct SonicParamAccesser {
    void* vtable;
    int pad4;
    void* data;
    int fieldC;
    int field10;
    int field14;
    int field18;
    void* param;
    void* param4;
    void* param8;
    void* paramC;
    void* param10;
    void* param14;
    void* param18;
    void* param1C;
    void* param20;
    void* param24;
    void* pad44;
    void* param28;
    void* param2C;
};

extern "C" void* fn_123_14EF4(SonicParamAccesser* self, unsigned char* param) {
    fn_123_6D30(self, 0);
    self->fieldC = 0x7C;
    self->field10 = 0xF9F;
    self->field14 = 0x5DBF;
    self->field18 = 0;
    self->data = lbl_123_data_782C;
    self->vtable = &lbl_123_data_782C[8];
    self->param = param;
    self->param4 = param + 4;
    self->param8 = param + 8;
    self->paramC = param + 0xC;
    self->param10 = param + 0x10;
    self->param14 = param + 0x14;
    self->param18 = param + 0x18;
    self->param1C = param + 0x1C;
    self->param20 = param + 0x20;
    self->param24 = param + 0x24;
    self->param28 = param + 0x28;
    self->param2C = param + 0x2C;
    return self;
}
