#pragma force_active on
extern "C" {
extern char lbl_123_data_1BF0[];

void fn_123_88E0(int *self, int a, int b, int c)
{
    self[0] = (int)lbl_123_data_1BF0;
    self[4] = a;
    self[5] = b;
    self[6] = c;
}
}
