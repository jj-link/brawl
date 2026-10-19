#pragma force_active on
extern "C" {
extern unsigned char lbl_105_data_283C[];
void fn_105_8058(void* obj, int val);
void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void* self, unsigned long id, void* accesser, unsigned char flag);
}

struct ResourceStorage {
    void* vtable;
    unsigned int pad;
    void* ptr;
    unsigned int zero;
};

extern "C" void* fn_105_848C(ResourceStorage* self, int unused1, int unused2, unsigned char flag, void* ptr) {
    fn_105_8058(self, 0);
    self->ptr = ptr;
    self->vtable = lbl_105_data_283C;
    self->zero = 0;
    __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(reinterpret_cast<unsigned char*>(self) + 0x10, 0, self, flag);
    return self;
}
