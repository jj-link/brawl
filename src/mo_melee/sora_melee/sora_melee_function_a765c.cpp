#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_157C8[];
extern "C" char lbl_27_data_157D8[];
extern "C" void fn_8001133C(void*, const float*, const float*);

extern "C" void fn_27_A765C(char* self, const float* a, const float* b) {
    fn_8001133C(__dynamic_cast(*(void**)(self + 4), 0x44, lbl_27_data_157C8, lbl_27_data_157D8, 1), a, b);
    *(float*)(self + 0xC) = a[0];
    *(float*)(self + 0x10) = a[1];
    *(float*)(self + 0x14) = b[0];
    *(float*)(self + 0x18) = b[1];
}
