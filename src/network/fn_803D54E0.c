#pragma force_active on
extern int fn_803CD270(void);
extern void *fn_803D4CB8(unsigned int);
extern void *fn_803D5B54(unsigned int);
extern unsigned short fn_803D5254(void *, unsigned int);
extern void *memcpy(void *, const void *, unsigned long);

int fn_803D54E0(void *arg0, int arg1, unsigned int arg2)
{
    struct {
        unsigned char data[0x4A];
        unsigned short checksum;
    } buffer;
    void *src;

    if (fn_803CD270() == 0) {
        return 1;
    }

    switch (arg1) {
    case 0:
        if (arg2 >= 100U) {
            return 15;
        }
        src = fn_803D4CB8(arg2);
        break;
    case 6:
        if (arg2 >= 6U) {
            return 15;
        }
        src = fn_803D5B54(arg2);
        break;
    default:
        src = 0;
        break;
    }

    if (src == 0) {
        return 10;
    }

    memcpy(&buffer, src, 0x4A);
    buffer.checksum = 0;
    buffer.checksum = fn_803D5254(&buffer, 0x4C);
    memcpy(arg0, &buffer, 0x4C);
    return 0;
}
