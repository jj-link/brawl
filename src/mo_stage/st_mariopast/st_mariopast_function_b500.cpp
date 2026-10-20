#pragma force_active on
typedef struct Entry {
    char data[0x38];
} Entry;

extern "C" {
void *fn_48_B500(char *base, int index)
{
    return base + index * sizeof(Entry) + 0xc;
}
}
