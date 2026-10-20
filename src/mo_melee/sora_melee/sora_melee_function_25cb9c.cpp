#pragma force_active on
extern "C" {
extern char lbl_27_data_53E5C[];
extern char lbl_27_data_53FE8[];
extern unsigned int lbl_27_data_53E58;

void* fn_27_241E30(void* self, const char* name);
}

struct Object {
    char pad0[0x2C];
    unsigned char flags;
    char pad2D[0xF];
    void* table;
    char pad40[8];
    unsigned int value;
    unsigned int zero;
    unsigned char enabled;
};

extern "C" void* fn_27_25CB9C(Object* self) {
    fn_27_241E30(self, lbl_27_data_53E5C);
    self->table = lbl_27_data_53FE8;
    self->value = lbl_27_data_53E58;
    self->zero = 0;
    self->enabled = 0;
    self->value = lbl_27_data_53E58;
    self->zero = 0;
    self->flags &= ~2;
    return self;
}
