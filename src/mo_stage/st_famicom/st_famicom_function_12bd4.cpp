#pragma force_active on
extern "C" {
void* fn_68_2398(void* self, const char* name);
void* memset(void* s, int c, unsigned long n);
extern char lbl_68_data_3388[];
}

extern "C" void* fn_68_12BD4(void* self, const char* name) {
    char* p = (char*)self;
    fn_68_2398(self, name);
    *(char**)(p + 0x3c) = lbl_68_data_3388;
    *(int*)(p + 0x158) = 0;
    *(int*)(p + 0x15c) = 0;
    *(int*)(p + 0x160) = 0;
    *(int*)(p + 0x164) = 0;
    *(int*)(p + 0x168) = 0;
    *(int*)(p + 0x16c) = 0;
    *(int*)(p + 0x170) = 0;
    *(int*)(p + 0x174) = 0;
    memset(p + 0x178, 0, 0x1c);
    *(int*)(p + 0x194) = 0;
    memset(p + 0x198, 0, 0x10);
    memset(p + 0x1a8, 0, 0x10);
    memset(p + 0x1b8, 0, 0x10);
    return self;
}
