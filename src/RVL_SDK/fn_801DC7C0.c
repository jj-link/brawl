#pragma force_active on
extern int lbl_805A06BC;
extern int lbl_805A06B8;
extern int fn_801DBFEC(int, unsigned short);

static inline int is_lead(unsigned int c)
{
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc);
}

static inline int is_trail(unsigned int c)
{
    return c >= 0x40 && c <= 0xfc && c != 0x7f;
}

unsigned char* fn_801DC7C0(int mode, unsigned char* str, int* table, int* result)
{
    int t;
    unsigned short c = 0;

    switch (mode) {
    case 0:
        c = *str;
        t = lbl_805A06BC;
        if (c)
            ++str;
        break;
    case 1:
        c = *str;
        t = lbl_805A06B8;
        if (c) {
            ++str;
            if (is_lead(c)) {
                unsigned int c2 = *str;
                if (is_trail(c2))
                    c = (c << 8) | *str++;
            }
        }
        break;
    }

    *table = t;
    *result = fn_801DBFEC(mode, c);
    return str;
}
