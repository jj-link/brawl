#pragma force_active on
extern "C" void* fn_27_2407E0(void* self);
extern "C" char lbl_27_data_4DAD0[];

extern "C" void* fn_27_24113C(void* self) {
    fn_27_2407E0(self);
    signed char* p = (signed char*)self;
    *(char**)((char*)self + 0x3C) = lbl_27_data_4DAD0;
    p[0x64] &= ~0xE0;
    return self;
}
