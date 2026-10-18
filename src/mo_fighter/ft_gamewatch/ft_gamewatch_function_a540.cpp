#pragma force_active on
extern "C" {
extern unsigned char lbl_107_data_3FA8[];

void fn_107_A540(void *self, void *a, void *b, void *c)
{
    ((void **)self)[0] = lbl_107_data_3FA8;
    ((void **)self)[4] = a;
    ((void **)self)[5] = b;
    ((void **)self)[6] = c;
}
}
