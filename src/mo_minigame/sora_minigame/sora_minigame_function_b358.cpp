#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

extern "C" void fn_20_2CF4(void*);
extern "C" unsigned char lbl_20_data_A4C[];
extern "C" const float lbl_20_rodata_1D8;
extern "C" const float lbl_20_rodata_1DC;

extern "C" void* fn_20_B358(void* p) {
    fn_20_2CF4(p);

    unsigned char* data = lbl_20_data_A4C;
    *(void**)((char*)p + 0x00) = data;
    *(void**)((char*)p + 0x18) = data + 0x18;
    *(void**)((char*)p + 0x1C) = data + 0x34;
    *(u32*)((char*)p + 0x24) = 0;
    *(u32*)((char*)p + 0x28) = 0;
    *(f32*)((char*)p + 0x2C) = lbl_20_rodata_1D8;
    *(f32*)((char*)p + 0x30) = lbl_20_rodata_1DC;
    *(u32*)((char*)p + 0x38) = 30;
    *((u8*)p + 0x3E) = 0;
    *((u8*)p + 0x3F) = 0;
    return p;
}
