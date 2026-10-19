#pragma force_active on
extern "C" char lbl_98_data_83C8[];
extern "C" void fn_98_7374(void*, unsigned char);

extern "C" void* fn_98_13AE8(char* self, void* arg) {
    fn_98_7374(self, 0);
    *(char**)self = lbl_98_data_83C8;
    *(void**)(self + 8) = arg;
    *(int*)(self + 0xc) = -1;
    return self;
}
