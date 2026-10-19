#pragma force_active on
extern "C" {
void fn_27_25CEA4(void* self, int arg);
extern char lbl_27_data_546A0[];
}

extern "C" void* fn_27_25E5E8(void* self) {
    fn_27_25CEA4(self, 1);
    *(void**)self = (void*)lbl_27_data_546A0;
    return self;
}
