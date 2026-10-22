#pragma force_active on
extern "C" void *fn_80197138(void *, unsigned int);
extern "C" void fn_801963D0(void **, void *, float);

extern "C" void *fn_8019D484(unsigned char *self, void *out, unsigned int arg) {
    void *sp8;
    void *r;
    sp8 = fn_80197138(self + 0x20, arg);
    if (sp8 == 0) {
        *(int *)out = 0;
        return out;
    }
    if (*(unsigned char **)(self + 0x30) != 0) {
        return *(unsigned char **)(self + 0x30) + (*(unsigned int *)((unsigned char *)sp8 + 0xC) << 4);
    }
    fn_801963D0(&sp8, out, *(float *)(self + 0xC));
    return out;
}
