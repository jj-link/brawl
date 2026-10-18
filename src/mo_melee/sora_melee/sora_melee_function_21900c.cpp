#pragma force_active on
typedef unsigned char u8;

struct Record {
    int unk0;
    int id;
    unsigned short flags;
    signed char type;
    char pad[0x59];

    int getType() const { return type; }

    int getId() const {
        int t = getType();
        if (t != 1 && t != 4 && t != 5)
            return -1;
        return id;
    }
};

struct Data {
    Record records[64];
    u8 bits[8];
    int count;
    int a;
    int b;
    int size;
};

extern void gfMemFill(void*, unsigned char, unsigned long);

extern "C" int fn_27_21900C(Data* self, int id) {
    self->a = 0;
    self->b = 0;
    if (self->size <= 0) {
        self->count = 0;
        return 0;
    }

    gfMemFill(self->bits, 0, 8);

    int count = 0;
    int i = 0;
    Record* rec = self->records;
    for (; i < 64; ++i, ++rec) {
        if (((*rec).flags & 1) && id == (*rec).getId()) {
            ++count;
            self->bits[i / 8] |= 1 << (i % 8);
        }
    }

    self->count = count;
    return count;
}
