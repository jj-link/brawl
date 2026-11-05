#pragma force_active on
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcat(char*, const char*);
extern char lbl_8059E148;
extern char lbl_8059E14C;

struct Name {
    unsigned char bytes[65];
};

extern "C" void fn_800C6FDC(unsigned char* self, unsigned int arg1, const char* arg2) {
    unsigned char buf[65];
    int r = strcmp(arg2, (const char*)&lbl_8059E14C);
    if ((unsigned int)(-r | r) >> 31) {
        buf[0] = 0;
        strcat((char*)buf, (const char*)&lbl_8059E148);
        buf[0] = 0;
        strcat((char*)buf, arg2);
        *(Name*)(self + 0x15D) = *(const Name*)buf;
        *(unsigned int*)(self + 0x380) = arg1;
        *(unsigned char**)(self + 0x384) = self + 0x15D;
        *(int*)(self + 0x350) = 6;
    }
}