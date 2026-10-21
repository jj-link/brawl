#pragma force_active on

extern "C" {
extern char lbl_8045B8A8[];
extern char lbl_8045B8EC[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_80153488(void*);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_800F19B0(void* p) {
    char* self = (char*)p;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_8045B8A8, 0x12, 0xE, 6, true);
    *(void**)(self + 0x3C) = lbl_8045B8EC;
    *(int*)(self + 0x40) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x68) = 2;
    *(int*)(self + 0x6C) = 0;
    *(int*)(self + 0x84) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0x90) = 0;
    fn_80153488(self + 0x9C);
    *(int*)(self + 0xA4) = 0;
    *(int*)(self + 0xA8) = 0;
    *(int*)(self + 0xAC) = 0;
    self[0xB0] = 0;
    *(int*)(self + 0xB4) = 0;
    *(int*)(self + 0xB8) = 0;
    *(int*)(self + 0xBC) = 0;
    *(int*)(self + 0xC4) = 0;
    *(int*)(self + 0xCC) = 0;
    *(int*)(self + 0xC8) = 0;
    *(int*)(self + 0xD0) = 0;
    *(int*)(self + 0xD4) = 0xFF;
    self[0xD8] = 0;
    self[0xD9] = 0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5C) = 0;
    memset(self + 0x64, 0, 4);
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x7C) = 0;
    *(int*)(self + 0x80) = 0;
    return p;
}
