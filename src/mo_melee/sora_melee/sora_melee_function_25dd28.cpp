#pragma force_active on
extern "C" void fn_27_25CEA4(void* self, int arg);
extern "C" char lbl_27_data_54478[];

extern "C" void* fn_27_25DD28(void* self) {
    fn_27_25CEA4(self, 1);
    ((int*)self)[4] = 0;
    *(void**)self = lbl_27_data_54478;
    return self;
}
