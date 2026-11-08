#pragma force_active on

extern "C" {
extern char lbl_16_data_3318[];
extern char lbl_16_data_3568[];
extern char lbl_16_data_35F0[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void fn_16_3B4(void*);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_16_1FC0(void* p) {
    char* self = (char*)p;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_16_data_3318, 8, 0xF, 8, true);
    *(void**)(self + 0x3C) = lbl_16_data_3568;
    *(int*)(self + 0x98) = 0;
    *(int*)(self + 0x9C) = 0;
    *(int*)(self + 0xA0) = 0x19;
    *(int*)(self + 0xA4) = 0;
    *(int*)(self + 0xA8) = 0;
    fn_800B96E8(self + 0xAC, 0xFF);
    *(int*)(self + 0x154) = 0;
    fn_16_3B4(self + 0x158);
    *(short*)(self + 0x1EC) = 0;
    *(short*)(self + 0x1EE) = 0;
    *(int*)(self + 0x3DC) = 0;
    *(int*)(self + 0x3E0) = 0;
    *(int*)(self + 0x3E8) = 0;
    *(int*)(self + 0x3EC) = 0;
    *(int*)(self + 0x3F0) = 0;
    self[0x3F4] = 0;
    *(int*)(self + 0x3F8) = 0;
    *(int*)(self + 0x3FC) = 0;
    *(int*)(self + 0x400) = 4;
    *(int*)(self + 0x404) = 0;
    *(int*)(self + 0x408) = 0;
    *(int*)(self + 0x44C) = 0;
    *(int*)(self + 0x454) = 0;
    *(int*)(self + 0x458) = 0;
    *(int*)(self + 0x45C) = 0;
    *(int*)(self + 0x460) = 0;
    *(int*)(self + 0x46C) = 0;
    *(void**)(self + 0x470) = lbl_16_data_35F0;
    self[0x474] = 1;
    *(int*)(self + 0x478) = -1;
    *(int*)(self + 0x47C) = 0;
    self[0x2C] &= ~2;
    *(int*)(self + 0x40) = 0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5C) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x64) = 0;
    *(int*)(self + 0x68) = 0;
    *(int*)(self + 0x6C) = 0;
    *(int*)(self + 0x70) = 0;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x7C) = 0;
    *(int*)(self + 0x80) = 0;
    *(int*)(self + 0x84) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0x8C) = 0;
    *(int*)(self + 0x90) = 0;
    *(int*)(self + 0x94) = 0;
    memset(self + 0x1F0, 0, 0x1E8);
    memset(self + 0x40C, 0, 0x40);
    memset(self + 0x450, 0, 3);
    return p;
}
