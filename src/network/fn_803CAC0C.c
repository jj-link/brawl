#pragma force_active on
extern int fn_803C7C64(void);

typedef struct {
    unsigned int a;
    unsigned short cyl;
    unsigned char heads;
    unsigned char secs;
    unsigned short bps;
    int c;
    int d;
} Geo;

int fn_803CAC0C(void* arg0, Geo* g) {
    unsigned int n;
    if (arg0 == 0 || g == 0) {
        return -0x14;
    }
    n = (unsigned int)(fn_803C7C64() - 0x1f) >> 9;
    g->a = n;
    g->cyl = n / 255 / 63 >> 9;
    g->heads = 0xff;
    g->secs = 0x3f;
    g->bps = 0x200;
    g->c = 0;
    g->d = 0;
    return 0;
}
