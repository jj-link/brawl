#pragma force_active on
extern "C" {

void OSReport(const char* msg, ...);
void fn_8001B9E8(int arg0);
int fn_803C4054(unsigned char* buf, unsigned char val);
extern unsigned char lbl_805A14C4;
extern unsigned char lbl_805A14C5;
extern char lbl_80421420[];

struct Foo {
    char pad[0x14];
    unsigned int field : 8;
    unsigned int rest : 24;
};

void fn_8001EA68(Foo* arg0) {
    unsigned char buf[2];
    int result;

    buf[0] = lbl_805A14C4;
    buf[1] = lbl_805A14C5;
    buf[0] = lbl_805A14C4 + arg0->pad[0x15];

    result = fn_803C4054(buf, lbl_805A14C4);
    if (result != 0) {
        OSReport(lbl_80421420, buf, result);
        fn_8001B9E8(result);
        result = 0xC;
    } else {
        result = 0;
    }
    arg0->field = (unsigned int)result;
}

}
