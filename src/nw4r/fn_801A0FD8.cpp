#pragma force_active on
struct Entry48 {
    unsigned char data[0x30];
};

struct Entry64 {
    unsigned char data[0x40];
};

struct Data {
    unsigned short flags;
    unsigned short index;
    unsigned char pad[0x30];
    Entry48 a[32];
    Entry64 b[32];
    Entry48 c[32];
    Entry48 d[32];
};

extern "C" {
extern Data lbl_804A7F40;

void fn_801A7DBC(void*, void*);
void fn_801A7E1C(void*, void*);
void fn_801A7EF8(void*, void*);
void fn_801A7FC8(void*, void*);

void fn_801A0FD8(void* arg0, int arg1, int arg2)
{
    if (arg1 < 32 && arg1 >= 0) {
        fn_801A7DBC(arg0, &lbl_804A7F40.a[arg1]);
        fn_801A7E1C(arg0, &lbl_804A7F40.b[arg1]);
        fn_801A7EF8(arg0, &lbl_804A7F40.c[arg1]);
        fn_801A7FC8(arg0, &lbl_804A7F40.d[arg1]);

        if (arg2 != 0) {
            lbl_804A7F40.index = arg1;
            lbl_804A7F40.flags &= 0xFFFE;
        }
    }
}
}
