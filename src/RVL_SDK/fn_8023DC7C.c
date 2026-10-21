#pragma force_active on
extern void *memset(void *s, int c, unsigned long n);
extern char lbl_80529CF8[];

void fn_8023DC7C(int arg0)
{
    char *p;

    p = (char *)((unsigned long)lbl_80529CF8 + arg0 * 0x22);
    p = (char *)((unsigned long)p + 0x4CC);
    memset(p, 0, 0x22);
    p[0x20] = 0;
}
