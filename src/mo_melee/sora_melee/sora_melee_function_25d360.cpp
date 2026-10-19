#pragma force_active on
extern "C" {
extern char lbl_27_data_54238[];
void fn_27_25CEA4(void* self, int flag);
}

extern "C" void* fn_27_25D360(void* self) {
    fn_27_25CEA4(self, 1);
    *(void**)self = lbl_27_data_54238;
    return self;
}
