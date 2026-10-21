#pragma force_active on
extern void fn_8027EABC(void*, void*, unsigned int, int);

void fn_8027EBF4(void* self) {
    int* s = (int*)self;
    int* r7 = (int*)s[0x18 / 4];
    int off = ((char*)s[0x1c / 4] - (char*)r7) + 0x10;
    s[0x10 / 4] = r7[-4];
    s[0x14 / 4] = r7[-3];
    s[0x18 / 4] = r7[-2];
    s[0x1c / 4] = r7[-1];
    fn_8027EABC(self, (void*)(r7 - 4), (unsigned int)off, 0x15);
}
