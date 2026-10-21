#pragma force_active on
extern "C" {
void fn_801C4B08(void);
extern unsigned int lbl_804669C8[];
}

struct Obj {
    void* vtbl;
    unsigned char pad[0xC4 - 4];
    unsigned char flagC4;
    unsigned char flagC5;
    unsigned char flagC6;
    unsigned char padC7[0xCA - 0xC7];
    unsigned char flagCA;
};

extern "C" {
Obj* fn_801C200C(Obj* arg0) {
    fn_801C4B08();
    arg0->vtbl = (void*)lbl_804669C8;
    arg0->flagC5 = 1;
    arg0->flagC6 = 0;
    arg0->flagC4 = 1;
    arg0->flagCA = 0;
    return arg0;
}
}
