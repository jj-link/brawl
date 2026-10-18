#pragma force_active on
extern "C" {
void* fn_99_60A0(void* object, unsigned char value);
extern unsigned char lbl_99_data_1758[];
}

extern "C" void* fn_99_7288(unsigned char* self, void* a1, void* a2, void* a3,
                            void* a4, void* a5, void* a6) {
    fn_99_60A0(self, 0);
    *(void**)(self + 0x8) = (void*)lbl_99_data_1758;
    *(void**)(self + 0x0) = (void*)(lbl_99_data_1758 + 0x8);
    *(void**)(self + 0xC) = a1;
    *(void**)(self + 0x10) = a2;
    *(void**)(self + 0x14) = a3;
    *(void**)(self + 0x18) = a4;
    *(void**)(self + 0x1C) = a5;
    *(void**)(self + 0x20) = a6;
    return self;
}
