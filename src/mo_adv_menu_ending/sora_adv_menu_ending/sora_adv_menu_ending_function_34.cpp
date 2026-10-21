#pragma force_active on
extern "C" {
extern char lbl_37_data_0[];
extern char lbl_37_data_234[];
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void* memset(void*, int, unsigned long);
}

extern "C" void* fn_37_34(void* p) {
    char* self = (char*)p;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, lbl_37_data_0, 8, 0xF, 8, true);
    *(int*)(self + 0x40) = 0;
    *(void**)(self + 0x3C) = lbl_37_data_234;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5C) = 0;
    memset(self + 0x60, 0, 8);
    *(int*)(self + 0x68) = 0;
    *(int*)(self + 0x6C) = 0;
    *(int*)(self + 0x70) = 0;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = 0;
    *(int*)(self + 0x88) = 0;
    *(int*)(self + 0x8C) = 0;
    *(int*)(self + 0x90) = 0;
    *(int*)(self + 0x94) = 0;
    *(int*)(self + 0x98) = 0;
    *(int*)(self + 0x9C) = 0;
    *(int*)(self + 0xA0) = 0;
    *(int*)(self + 0xA4) = 0;
    *(int*)(self + 0xC0) = 0;
    *(int*)(self + 0x12C) = 0;
    *(int*)(self + 0x130) = 0;
    return p;
}
