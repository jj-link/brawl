#pragma force_active on
void *fn_80397694(void *dest, const void *src, unsigned int len) {
    unsigned int i;
    for (i = 0; i < len; i++) {
        ((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
    }
    return dest;
}