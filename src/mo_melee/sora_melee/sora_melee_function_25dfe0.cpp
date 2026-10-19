#pragma force_active on
extern "C" {
extern char lbl_27_data_54548[];
void fn_27_25CEA4(void* self, int flag);
}

extern "C" void* fn_27_25DFE0(void* self) {
    fn_27_25CEA4(self, 1);
    *((char*)self + 0x10) = 0;
    *(void**)self = lbl_27_data_54548;
    return self;
}
