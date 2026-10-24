#pragma force_active on
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_804620F8[];
extern char lbl_80462130[];
}

extern "C" void* fn_8015820C(void* self, int arg1) {
    unsigned char* p = (unsigned char*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_804620F8, 0x26, 0xE, 0xD, true);
    *(void**)(p + 0x3C) = lbl_80462130;
    *(void**)(p + 0x40) = lbl_80462130 + 0x64;
    *(int*)(p + 0x44) = arg1;
    *(int*)(p + 0x48) = 0;
    p[0x4C] = 0;
    *(int*)(p + 0x5C) = 0;
    *(int*)(p + 0x50) = 0;
    *(unsigned short*)(p + 0x54) = 0;
    *(unsigned short*)(p + 0x56) = 0;
    *(unsigned short*)(p + 0x58) = 0;
    p[0x2C] = p[0x2C] & ~2;
    return self;
}
