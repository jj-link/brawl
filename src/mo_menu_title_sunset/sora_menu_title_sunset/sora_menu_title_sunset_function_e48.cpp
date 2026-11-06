#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);

extern char lbl_25_data_198[];
extern char lbl_25_data_1C8[];
extern char lbl_25_data_250[];
extern char lbl_25_data_278[];
extern const float lbl_25_rodata_20;

void* fn_25_E48() {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0xB8, 0x2A);
    if (p != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_25_data_198, 8, 0xF, 8, true);
        *(char**)(p + 0x3C) = lbl_25_data_1C8;
        *(int*)(p + 0x40) = 0;
        *(int*)(p + 0x44) = 0;
        *(char**)(p + 0x94) = lbl_25_data_250;
        *(char**)(p + 0x68) = lbl_25_data_278;
        *(float*)(p + 0x58) = lbl_25_rodata_20;
        *(float*)(p + 0x5C) = lbl_25_rodata_20;
        *(float*)(p + 0x60) = lbl_25_rodata_20;
        *(float*)(p + 0x64) = lbl_25_rodata_20;
        *(char**)(p + 0x7C) = lbl_25_data_278;
        *(float*)(p + 0x6C) = lbl_25_rodata_20;
        *(float*)(p + 0x70) = lbl_25_rodata_20;
        *(float*)(p + 0x74) = lbl_25_rodata_20;
        *(float*)(p + 0x78) = lbl_25_rodata_20;
        *(char**)(p + 0x90) = lbl_25_data_278;
        *(float*)(p + 0x80) = lbl_25_rodata_20;
        *(float*)(p + 0x84) = lbl_25_rodata_20;
        *(float*)(p + 0x88) = lbl_25_rodata_20;
        *(float*)(p + 0x8C) = lbl_25_rodata_20;
        *(char**)(p + 0xA8) = lbl_25_data_278;
        *(float*)(p + 0x98) = lbl_25_rodata_20;
        *(float*)(p + 0x9C) = lbl_25_rodata_20;
        *(float*)(p + 0xA0) = lbl_25_rodata_20;
        *(float*)(p + 0xA4) = lbl_25_rodata_20;
        *(int*)(p + 0xB4) = 0;
        *(int*)(p + 0xAC) = 0;
    }
    return p;
}
}
