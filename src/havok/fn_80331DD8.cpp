#pragma force_active on
extern "C" {
extern char lbl_80488F30[];
void __ct__14Class_8027D01CFv(void* self, void* data);

void* fn_80331DD8(void* self) {
    char* p = static_cast<char*>(self);
    *(short*)(p + 0x6) = 1;
    *(void**)(p + 0x0) = lbl_80488F30;
    *(int*)(p + 0x8) = 0;
    __ct__14Class_8027D01CFv(p + 0xC, lbl_80488F30);
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x1C) = 0;
    *(unsigned int*)(p + 0x20) = 0x80000000;
    *(int*)(p + 0x24) = 0;
    *(int*)(p + 0x28) = 0;
    *(unsigned int*)(p + 0x2C) = 0x80000000;
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x34) = 0;
    *(unsigned int*)(p + 0x38) = 0x80000000;
    *(int*)(p + 0x3C) = 0;
    *(int*)(p + 0x40) = 0;
    *(unsigned int*)(p + 0x44) = 0x80000000;
    return self;
}
}
