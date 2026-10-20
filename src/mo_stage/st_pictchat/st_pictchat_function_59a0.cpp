#pragma force_active on
#define VIRTUAL_1(n) virtual void unused##n();
#define VIRTUAL_2(n) VIRTUAL_1(n##a) VIRTUAL_1(n##b)
#define VIRTUAL_4(n) VIRTUAL_2(n##a) VIRTUAL_2(n##b)
#define VIRTUAL_8(n) VIRTUAL_4(n##a) VIRTUAL_4(n##b)
#define VIRTUAL_16(n) VIRTUAL_8(n##a) VIRTUAL_8(n##b)
#define VIRTUAL_32(n) VIRTUAL_16(n##a) VIRTUAL_16(n##b)
#define VIRTUAL_64(n) VIRTUAL_32(n##a) VIRTUAL_32(n##b)
#define VIRTUAL_128(n) VIRTUAL_64(n##a) VIRTUAL_64(n##b)

class PictchatBase {
    unsigned char padding[0x3c];

public:
    VIRTUAL_128(a)
    VIRTUAL_8(b)
    VIRTUAL_2(c)
    VIRTUAL_1(d)
    virtual void reset(unsigned char);
};

struct Pictchat : PictchatBase {
    unsigned char padding1[0x241];
    unsigned char initialized;
};

extern "C" void fn_73_59A0(Pictchat* self) {
    if (self->initialized != 1) {
        for (unsigned int i = 0; i < 6; ++i) {
            self->reset((unsigned char)i);
        }
        self->initialized = 1;
    }
}
