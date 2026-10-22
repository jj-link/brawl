#pragma force_active on
extern "C" {
void fn_8014CD60(void*);
void* memset(void*, int, unsigned long);
extern char lbl_80461048[];
}

extern "C" void* fn_8014E478(void* self) {
    char* p = (char*)self;
    fn_8014CD60(self);
    *(int*)(p + 0x88) = 0;
    *(char**)(p + 0x94) = lbl_80461048;
    *(char**)(p + 0x14) = lbl_80461048 + 8;
    *(char**)(p + 0x18) = lbl_80461048 + 0x14;
    memset(p + 0x30, 0, 0x40);
    *(short*)(p + 0x70) = 0;
    *(int*)(p + 0x74) = 0;
    *(int*)(p + 0x78) = 0;
    *(int*)(p + 0x7c) = 0;
    *(int*)(p + 0x1c) = 0;
    *(int*)(p + 0x20) = 0;
    *(char*)(p + 0x8c) = 1;
    *(int*)(p + 0x90) = 0;
    memset(p + 0x80, 0, 8);
    *(int*)(p + 0x24) = 0;
    *(int*)(p + 0x28) = 0;
    return self;
}
