#pragma force_active on
extern "C" {
void *fn_802DBBF4(void *self, int index)
{
    char *base = *(char **)self;
    return base + index * 0x4c;
}
}
