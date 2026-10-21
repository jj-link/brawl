#pragma force_active on

typedef unsigned char u8;

struct Entry {
    u8 pad0[0x18];
    u8 f18;
    u8 pad1[0xB];
    u8 f24;
    u8 pad2[3];
};

struct Result {
    u8 pad[0x28];
    u8 count;
};

struct Base {
    u8 pad[0x3C];
};

#define SLOT(n) virtual void unused##n();

struct Self : Base {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34)
    SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    virtual Result* getResult();

    u8 pad1[0x175 - 0x40];
    u8 cur;
    u8 pad2[2];
    Entry* entries;
};

#undef SLOT

extern "C" int fn_68_C8B4(Self* self) {
    Result* r = self->getResult();
    if (r == 0)
        return 0;

    Entry* e;
    u8 i;
    unsigned int n = r->count;
    i = 0;

    while (i != n) {
        if (i != self->cur) {
            e = &self->entries[i];
            if (e->f24 == 5) {
                Entry* c = &self->entries[self->cur];
                if (c->f18 == 1) {
                    if (e->f18 == 1)
                        return 0;
                } else {
                    if (e->f18 == 0)
                        return 0;
                }
            }
        }
        i++;
    }
    return 1;
}
