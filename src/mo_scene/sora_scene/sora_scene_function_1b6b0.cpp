#pragma force_active on
extern "C" {
typedef unsigned char u8;

int fn_1_1B6B0(void *self)
{
    int ret = 3;
    if (((u8 *)self)[0x104] != 0) {
        ret = 1;
    }
    return ret;
}
}
