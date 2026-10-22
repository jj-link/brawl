#pragma force_active on
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_80459C28[];
extern char lbl_80459C38[];
}

extern "C" void* fn_800DAAEC(void* self) {
    unsigned int flags;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80459C28, 8, 0xF, 8, true);
    flags = *(unsigned char*)((char*)self + 0x2C);
    *(char**)((char*)self + 0x3C) = lbl_80459C38;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    *(int*)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
    *(int*)((char*)self + 0x50) = 0;
    *(int*)((char*)self + 0x54) = 6;
    *(int*)((char*)self + 0x58) = 1;
    *(int*)((char*)self + 0x5C) = 0;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x68) = 0;
    *(char*)((char*)self + 0x6C) = 0;
    flags = flags & ~2u;
    *(unsigned char*)((char*)self + 0x2C) = (unsigned char)flags;
    return self;
}
