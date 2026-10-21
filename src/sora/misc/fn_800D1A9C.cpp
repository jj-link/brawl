#pragma force_active on
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80458770[];

struct Entry {
    char pad[0xC6];
    unsigned char unused : 1;
    unsigned char flag : 1;
    unsigned char rest : 6;
    char padEnd[0x151];
};

extern "C" void fn_800D1A9C(Entry* p) {
    p[0].flag = 0;
    p[1].flag = 0;
    p[2].flag = 0;
    p[3].flag = 0;
    netReport__FPCce(lbl_80458770);
}
