#pragma force_active on
struct S {
    unsigned short m0;
    char m2;
    char m3;
    char m4;
    char m5;
    char m6;
    char m7;
};

void fn_80399CD4(struct S *p)
{
    p->m0 = 2000;
    p->m2 = 1;
    p->m3 = 1;
    p->m4 = 12;
    p->m6 = 0;
    p->m5 = 0;
    p->m7 = 0;
}
