#pragma force_active on
extern char lbl_805639C0[];
extern char lbl_805644C0[];
int fn_803D8988(const unsigned int *p);

unsigned char fn_803EEEB4(unsigned int arg0, unsigned char *arg1, unsigned int arg2) {
    unsigned int i;
    unsigned char count;
    unsigned char *out;
    char *entry;
    unsigned char j;
    char *rec;

    if (arg1 == 0 || arg2 == 0) {
        return 0;
    }
    out = arg1;
    count = 0;
    entry = lbl_805639C0 + 0x61C;
    for (i = 0; i < 26; i++) {
        if (fn_803D8988((const unsigned int *)entry) != 0 && *(unsigned int *)(entry + 4) == arg0) {
            rec = lbl_805644C0 + 0xA0;
            for (j = 0; j < 26; j++) {
                if (*(unsigned int *)(rec + 0x1FBC) == (unsigned int)entry) {
                    count++;
                    *out++ = rec[0x1F8E];
                    if (count == arg2) {
                        break;
                    }
                }
                rec += 0x1FC8;
            }
        }
        if (count == arg2) {
            break;
        }
        entry += 0x28;
    }
    return count;
}