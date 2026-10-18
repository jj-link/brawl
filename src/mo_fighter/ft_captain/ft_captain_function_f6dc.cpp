#pragma force_active on
extern "C" {

extern unsigned char lbl_100_data_6878[0x40];

void fn_100_F6DC(void** dest)
{
    *dest = &lbl_100_data_6878;
}

}
