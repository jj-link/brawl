#pragma force_active on
extern void OSReport(const char* fmt, ...);
extern char lbl_80477190[];
extern unsigned char lbl_805A09B8;
extern unsigned char lbl_805A09B9;
extern int lbl_805A09CC;
extern unsigned char lbl_805A09D8;

struct Foo {
    void (*fn)(void);
    char _pad[4];
    unsigned char unk8;
    char _pad2[3];
    unsigned int unkC;
};

unsigned int fn_801FC774(unsigned int flags, struct Foo* self) {
    if (self->unkC + 0x01150000 != 0x0000DAED) {
        OSReport(lbl_80477190);
        self->unkC = 0xFEEBDAED;
    } else {
        lbl_805A09B8 = 0;
        if (self->fn) {
            unsigned char val = lbl_805A09D8;
            lbl_805A09B9 = 1;
            if (val == 1) {
                lbl_805A09D8 = 0;
                flags |= 8;
            }
            if (flags & 1) {
                lbl_805A09CC = 0;
            }
            self->fn();
            lbl_805A09B9 = 0;
        }
    }
    self->unk8 = 0;
    return 0;
}
