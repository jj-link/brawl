#pragma force_active on

extern void OSReport(const char* fmt, ...);
extern unsigned int lbl_804E4720[];
extern int lbl_804E4740[];
extern unsigned char lbl_805A09B8;
extern unsigned char lbl_805A09B9;
extern unsigned char lbl_805A09D8;
extern char lbl_80477190[];

struct CallbackObject {
    unsigned int (*callback)(unsigned int);
    unsigned char padding[4];
    unsigned char unk8;
    unsigned char padding2[3];
    unsigned int unkC;
};

unsigned int fn_801FC82C(unsigned int flags, struct CallbackObject* self) {
    lbl_805A09B8 = 0;
    lbl_804E4720[1] = lbl_804E4740[0];

    if (self->unkC + 0x01150000 != 0x0000DAED) {
        OSReport(lbl_80477190);
        self->unkC = 0xFEEBDAED;
    } else if (self->callback != 0) {
        lbl_805A09B9 = 1;
        if (lbl_805A09D8 == 1) {
            lbl_805A09D8 = 0;
            flags |= 8;
        }
        self->callback(flags);
        lbl_805A09B9 = 0;
    }

    self->unk8 = 0;
    return 0;
}
