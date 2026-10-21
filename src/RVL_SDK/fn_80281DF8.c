#pragma force_active on
int fn_80281DF8(signed char **arg0, signed char *arg1)
{
    int i = 0;

    while (*arg1 != 0) {
        signed char value;

        if (i >= *(int *)(*arg0 - 12))
            goto fail;

        value = (*arg0)[i];
        if (value != *arg1) {
fail:
            return 0;
        }

        i++;
        arg1++;
    }

    return 0x01000000;
}
