#pragma force_active on
extern "C" {
void fn_27_2D90B0(void* self);
extern char lbl_27_data_87998[];
}

extern "C" void* fn_27_328A0C(void* self) {
    fn_27_2D90B0(self);
    *(void**)self = (void*)lbl_27_data_87998;
    return self;
}
