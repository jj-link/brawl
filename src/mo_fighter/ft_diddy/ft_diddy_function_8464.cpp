#pragma force_active on
extern char lbl_115_data_2BF0[];

struct FtObj {
    void *vtbl;
    int pad[3];
    int a;
    int b;
    int c;
};

extern "C" {
void fn_115_8464(FtObj *p, int a, int b, int c)
{
    p->vtbl = lbl_115_data_2BF0;
    p->a = a;
    p->b = b;
    p->c = c;
}
}
