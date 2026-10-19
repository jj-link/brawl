#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void fn_118_98F4(void*);
extern "C" char lbl_118_data_600[];
extern "C" char lbl_118_data_2250[];

extern "C" void fn_118_104F0(void*, unsigned char* obj) {
    fn_118_98F4(__dynamic_cast(*(void**)(obj + 0x8), 0x3c, lbl_118_data_600, lbl_118_data_2250, 1));
}
