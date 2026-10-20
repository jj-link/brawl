#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_247420(u8* self, const char* name);
extern "C" char lbl_27_data_4ED10[];
extern "C" char lbl_27_data_4ED28[];
extern "C" const float lbl_27_rodata_3FF0;

extern "C" {
u8* fn_27_2478EC(u8* self) {
    fn_27_247420(self, lbl_27_data_4ED10);
    *(char**)(self + 0x3c) = lbl_27_data_4ED28;
    *(float*)(self + 0x74) = lbl_27_rodata_3FF0;
    *(float*)(self + 0x70) = lbl_27_rodata_3FF0;
    *(u8*)(self + 0x78) = 0;
    return self;
}
}
