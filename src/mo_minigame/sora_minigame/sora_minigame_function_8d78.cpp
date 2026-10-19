#pragma force_active on
extern "C" int fn_20_8D78(void *object)
{
    char *words = (char *)object;

    if (*(unsigned int *)(words + 0x4F8) != 0)
        return 0;

    char *flags = (char *)object;
    for (int i = 0; i < 5; i++)
    {
        if (*(unsigned int *)(words + 0x244) != 0 && *(unsigned char *)(flags + 0x428) != 0)
            return 0;
        if (*(unsigned int *)(words + 0x248) != 0 && *(unsigned char *)(flags + 0x429) != 0)
            return 0;
        if (*(unsigned int *)(words + 0x24C) != 0 && *(unsigned char *)(flags + 0x42A) != 0)
            return 0;
        if (*(unsigned int *)(words + 0x250) != 0 && *(unsigned char *)(flags + 0x42B) != 0)
            return 0;
        if (*(unsigned int *)(words + 0x254) != 0 && *(unsigned char *)(flags + 0x42C) != 0)
            return 0;
        if (*(unsigned int *)(words + 0x258) != 0 && *(unsigned char *)(flags + 0x42D) != 0)
            return 0;

        words += 0x1C;
        flags += 6;
    }
    return 1;
}
