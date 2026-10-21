#pragma force_active on
extern "C" int fn_8015227C(int, int);

struct Self {
    char pad0[0x36C];
    unsigned char m_36C;
    char pad1[0x384 - 0x36D];
    unsigned char m_384;
};

extern "C" void fn_80154C8C(Self* self, int unused, int arg) {
    int r;
    r = fn_8015227C(*(int*)((char*)self + 0x368), arg);
    *(int*)((char*)self + 0x380) = r;
    if (r != 0) {
        self->m_384 = 1;
        self->m_36C = 1;
    }
}
