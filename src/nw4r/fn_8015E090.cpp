#pragma force_active on
extern "C" unsigned char fn_8015E090(void *a) {
    unsigned char **p = *(unsigned char ***)((unsigned char *)a + 0x14);
    unsigned char *v = *(unsigned char **)((unsigned char *)p + 0x8);
    return v[1];
}
