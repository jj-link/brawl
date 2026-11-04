#pragma force_active on
typedef unsigned char u8;
struct Record {
    int unk0;
    int id;
    unsigned short flags;
    signed char type;
    char pad[0x4a];
    signed char owner;
    char pad2[0x0e];
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
extern "C" int fn_27_218D40(Data* self, signed char owner, int id) {
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
        if ((rec->flags & 1) && rec->type == 0 &&
            (owner < 0 || owner == rec->owner) &&
            (id == -1 || id == rec->id)) {
            ++count;
            self->bits[i / 8] |= 1 << (i % 8);
        }
    }
    self->count = count;
    return count;
}