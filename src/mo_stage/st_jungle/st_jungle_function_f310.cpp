#pragma force_active on
typedef unsigned char u8;

extern "C" const float lbl_51_rodata_120;
extern "C" const float lbl_51_rodata_124;

extern "C" void fn_51_F310(void* self) {
    u8* p = (u8*)self;
    *(u8*)(p + 0x1b4) = 0;
    *(float*)(p + 0x1c4) = lbl_51_rodata_124;
    *(float*)(p + 0x19c) = lbl_51_rodata_120;
    *(float*)(p + 0x1a0) = lbl_51_rodata_120;
    *(float*)(p + 0x1a4) = lbl_51_rodata_120;
}
