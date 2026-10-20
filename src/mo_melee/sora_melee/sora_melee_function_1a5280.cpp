#pragma force_active on
struct Work {
    void *a;
    void *b;
    unsigned int c;
};

extern "C" {
extern char lbl_27_data_34F78[];
}

extern "C" void fn_27_1A5280(Work *p)
{
    unsigned int c = p->c;
    char *base = lbl_27_data_34F78;
    char *next = base + 0x48;
    c &= 0x1FFF;
    p->a = base;
    p->b = next;
    p->c = c;
}
