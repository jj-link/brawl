#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_17E50[];

void fn_27_C410C(unsigned int *self, unsigned int value)
{
    unsigned int old = self[3];
    self[0] = value;
    self[1] = (unsigned int)lbl_27_data_17E50;
    self[2] = (unsigned int)(lbl_27_data_17E50 + 0x48);
    self[3] = old & 0x1FFF;
}
}
