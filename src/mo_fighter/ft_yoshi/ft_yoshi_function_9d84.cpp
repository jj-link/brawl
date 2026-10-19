#pragma force_active on
extern "C" {
extern char lbl_95_data_30C8[];

void fn_95_9D84(int *p, int a, int b, int c)
{
    p[0] = (int)lbl_95_data_30C8;
    p[4] = a;
    p[5] = b;
    p[6] = c;
}
}
