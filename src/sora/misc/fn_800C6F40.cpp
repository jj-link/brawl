#pragma force_active on
extern "C" int strcmp(const char*, const char*);
extern int lbl_8059E14C;

struct Name {
    unsigned char bytes[65];
};

extern "C" void fn_800C6F40(unsigned char* self, unsigned int a, const char* s) {
    int r = strcmp(s, (const char*)&lbl_8059E14C) != 0;
    if (r) {
        *(Name*)(self + 0x15D) = *(const Name*)s;
        *(unsigned int*)(self + 0x380) = a;
        *(unsigned char**)(self + 0x384) = self + 0x15D;
        *(int*)(self + 0x350) = 5;
    }
}
