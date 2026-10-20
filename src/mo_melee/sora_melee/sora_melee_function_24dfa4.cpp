#pragma force_active on
extern "C" void fn_27_247D98(void*);
extern "C" char lbl_27_data_4F488[];
extern "C" const float lbl_27_rodata_4058;

extern "C" void* fn_27_24DFA4(void* self) {
    fn_27_247D98(self);
    *(void**)((char*)self + 0x3C) = lbl_27_data_4F488;
    *((char*)self + 0x40) = 0;
    *(float*)((char*)self + 0xCC) = lbl_27_rodata_4058;
    return self;
}
