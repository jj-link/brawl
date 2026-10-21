#pragma force_active on
typedef struct Entry {
    unsigned short value;
    unsigned char padding[14];
    unsigned char active;
    unsigned char reserved;
} Entry;

extern Entry lbl_80563360[31];

void fn_803C6DC4(void)
{
    int i;
    Entry *p = lbl_80563360;

    for (i = 0; i < 31; ++i, ++p) {
        p->value = 0;
        p->active = 0;
    }
}
