#pragma force_active on
extern "C" {
extern unsigned char lbl_8059E742;
extern unsigned char lbl_8059E745;

int fn_800C8524(void)
{
    int ret = 0;
    unsigned char a = lbl_8059E742;
    if (a == lbl_8059E745 && a != 0xFF) {
        ret = 1;
    }
    return ret;
}
}
