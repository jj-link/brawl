#pragma force_active on
extern "C" {
extern char lbl_27_data_544F0[];
void fn_27_25CEA4(void* self, int arg);
}

extern "C" void* fn_27_25DE04(void* self, int arg) {
    fn_27_25CEA4(self, 1);
    *(int*)((char*)self + 0x10) = arg;
    *(char**)self = lbl_27_data_544F0;
    return self;
}
