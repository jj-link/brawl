#pragma force_active on
int fn_8038E370(unsigned char *self)
{
    int ret = 4;
    unsigned int ptr = *(unsigned int *)(self + 8);
    if (*(unsigned int *)ptr != 0) {
        ret = 0;
    }
    return ret;
}
