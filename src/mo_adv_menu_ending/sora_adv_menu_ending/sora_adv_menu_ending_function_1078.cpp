#pragma force_active on
extern "C" {
extern char lbl_37_data_DC[];
void fn_8007EC08(void*, void*, int, int, int);
}

extern "C" void fn_37_1078(char* self) {
    fn_8007EC08(*(void**)(self + 0x78), lbl_37_data_DC, 0, 0, 0);
}
