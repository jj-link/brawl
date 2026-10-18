#pragma force_active on
extern "C" {
extern char lbl_97_data_28F8[0x20];

void fn_97_9D7C(void **obj, void *a, void *b, void *c)
{
    obj[0] = lbl_97_data_28F8;
    obj[4] = a;
    obj[5] = b;
    obj[6] = c;
}
}
