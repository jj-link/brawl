#pragma force_active on
extern char lbl_80529CF8[];
extern char lbl_80481028[];

extern void fn_802319E4(unsigned int, const char *);
extern unsigned char fn_8023A5A4(void);
extern unsigned char fn_80244964(void);
extern void fn_8022F0E0(void *);

int fn_8023C3E0(void)
{
    char *cleanup;
    char *state = lbl_80529CF8;
    int result = 0;

    if (*(unsigned char *)(state + 0x27C0) >= 3U) {
        fn_802319E4(0xD0002, lbl_80481028);
    }

    if (!fn_8023A5A4()) {
        return 6;
    }

    if (*(unsigned char *)(state + 0x1848) != 0 &&
        !(*(unsigned char *)(state + 0x1848) & 4)) {
        *(unsigned char *)(state + 0x1848) = 0;
        *(unsigned char *)(state + 0x1847) = 0;
        *(int *)(state + 0x16B4) = 0;
        *(int *)(state + 0x16B0) = 0;

        if (*(unsigned char *)(state + 0x1844) != 0) {
            *(unsigned char *)(state + 0x1844) = 0;
            ++*(unsigned char *)(state + 0x1845);
        } else if (!fn_80244964()) {
            result = 3;
        }

        ++*(int *)(state + 0x16C0);

        {
            cleanup = lbl_80529CF8;
            if (*(void **)(cleanup + 0x16DC) != 0) {
                fn_8022F0E0(*(void **)(cleanup + 0x16DC));
                *(void **)(cleanup + 0x16DC) = 0;
            }
            *(short *)(cleanup + 0x16E0) = 0;
            *(short *)(cleanup + 0x16E2) = 0;
        }
    }

    return result;
}
