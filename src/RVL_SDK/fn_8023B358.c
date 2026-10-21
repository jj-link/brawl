#pragma force_active on
extern char lbl_80529CF8[];

typedef struct {
    unsigned short a, b, c, d, e;
} Data;

int fn_8023B358(Data *dst)
{
    unsigned char *base = (unsigned char *)lbl_80529CF8;

    if (base[0x64E] < 4) {
        return 12;
    }

    *dst = *(Data *)(base + 0x636);
    return 0;
}
