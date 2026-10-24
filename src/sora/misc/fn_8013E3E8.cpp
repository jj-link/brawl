#pragma force_active on
extern "C" {
    void netReport__FPCce(const char*, ...);
    void flushLogToSDCard__Fv();
    extern char lbl_8045E018[];

    struct S {
        unsigned pad : 1;
        signed int code : 8;
        unsigned pad2 : 7;
        unsigned b1da : 8;
        unsigned pad3 : 8;
        int unk1dc;
    };

    int fn_8013E3E8(int* arg0, char arg1) {
        if (arg0[0x2A] != 6 || arg0[0x78] != 0) {
            return 0;
        }
        S* s = (S*)((char*)arg0 + 0x1D8);
        int temp = s->code;
        if (temp != 0) {
            netReport__FPCce(lbl_8045E018, temp);
            return 0;
        }
        s->code = 1;
        s->unk1dc = 0;
        ((char*)arg0)[0x1DA] = arg1;
        flushLogToSDCard__Fv();
        return 1;
    }
}
