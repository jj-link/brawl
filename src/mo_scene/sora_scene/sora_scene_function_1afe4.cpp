#pragma force_active on
extern "C" int fn_1_1AFE4(unsigned char *self, unsigned int type)
{
    if (type != 6) {
        return 0;
    }
    self[4] = 1;
    return 1;
}
