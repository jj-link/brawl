#pragma force_active on

#define SLOT(n) virtual void unused##n();

struct Object {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17)
    virtual int method50(int);
    virtual void* method54(int, void*);
};

#undef SLOT

extern "C" int fn_802D7260(void*, void*, void*, float);
extern "C" int __cntlzw(unsigned int);
extern float lbl_8059EFC8;

extern "C" int fn_802D52FC(Object* self) {
    __declspec(align(16)) unsigned char buffer[0x200];
    void* data = self->method54(0, buffer);

    int result = fn_802D7260(
        (char*)data + 0x10,
        (char*)data + 0x20,
        (char*)data + 0x30,
        lbl_8059EFC8
    );

    signed char zero =
        (__cntlzw((unsigned int)(signed char)((unsigned int)result >> 24)) >> 5) & 0xFF;
    if (((unsigned int)(-(signed char)zero | (signed char)zero) >> 31) != 0)
        return 0;

    return self->method50(0);
}
