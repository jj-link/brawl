#pragma force_active on

extern unsigned char lbl_8052D5A8[];
extern char lbl_80483ED0[];
extern char lbl_80483EE8[];
extern void fn_802319FC(int, const char *, unsigned int);
extern void fn_8025466C(unsigned int, unsigned char, unsigned short);
extern void fn_802562B8(unsigned int);
extern void fn_802519F4(unsigned char *);
extern void fn_802564E4(unsigned int);

void fn_8025047C(unsigned int arg0, unsigned int arg1)
{
    unsigned char *entry;
    int i;
    int found;

    found = 1;
    if (lbl_8052D5A8[0x414] >= 4) {
        fn_802319FC(0x90003, lbl_80483ED0, arg1);
    }

    i = 0;
    entry = lbl_8052D5A8 + 0x68;
    do {
        if (*(unsigned int *)(entry + 0x6C) == arg0) {
            found = 0;
            if (arg1 == 0) {
                fn_8025466C(arg0, entry[0xD], *(unsigned short *)(entry + 0x12));
            } else {
                if (lbl_8052D5A8[0x414] >= 2) {
                    fn_802319FC(0x90001, lbl_80483EE8, arg1);
                }
                if (arg1 == 4) {
                    entry[0xE] = 0x18;
                } else {
                    entry[0xE] = 0xC;
                }
                fn_802562B8(arg0);
                *(unsigned int *)(entry + 0x6C) = 0;
                if (*(unsigned int *)(entry + 0x8C) != 0) {
                    if (*(unsigned int *)(entry + 0x88) & 0x8000) {
                        ((void (*)(int, int))(*(unsigned int *)(entry + 0x8C)))(0x8000, entry[0]);
                    }
                }
                if (*(unsigned int *)(entry + 0x90) != 0) {
                    ((void (*)(int, int))(*(unsigned int *)(entry + 0x90)))(0xC, entry[0]);
                }
                fn_802519F4(entry);
            }
        }
        i++;
        entry += 0xA4;
    } while (i < 5);

    if (found) {
        fn_802564E4(arg0);
    }
}