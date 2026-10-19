#pragma force_active on
extern "C" void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern "C" char lbl_41_data_38D8[];

extern "C" void* fn_41_2B0E0(void* self, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7, void* a8, int a9, unsigned char a10) {
    fn_27_73930(self, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    char* base = lbl_41_data_38D8;
    *(char**)((char*)self + 0x00) = base;
    *(char**)((char*)self + 0x08) = base + 0xA4;
    *(char**)((char*)self + 0x14) = base + 0xB0;
    *(char**)((char*)self + 0x20) = base + 0xC4;
    *(int*)((char*)self + 0xAC) = -50;
    *(int*)((char*)self + 0xB0) = 250;
    return self;
}
