#pragma force_active on
extern unsigned int SOHtoNl(unsigned int);
extern void *fn_8035CF8C(void);
extern int fn_8035D140(unsigned int *);

unsigned int fn_8038563C(void) {
    int off;
    void *base;
    unsigned int val;
    unsigned int *entry;
    unsigned int last = 0;

    base = fn_8035CF8C();
    if (base == 0) {
        return 0;
    }
    off = 0;
    while (1) {
        entry = *(unsigned int **)((char *)*(void **)((char *)base + 0xC) + off);
        if (entry == 0) {
            break;
        }
        val = *entry;
        if (val != SOHtoNl(0x7F000000 + 1)) {
            last = val;
            if (fn_8035D140(entry) != 0) {
                return val;
            }
        }
        off += 4;
    }
    return last;
}
