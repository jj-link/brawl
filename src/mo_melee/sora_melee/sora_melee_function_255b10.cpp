#pragma force_active on
struct Data { char pad[0xd5]; unsigned char value; };
struct Self {
    char pad0[0x44]; Data* data; char pad1[0x78]; unsigned int flags;
    char pad2[4]; int mask1; int mask2; char pad3[0x1c]; int indices[256];
};
extern "C" void fn_27_255B10(Self* self) {
    if (self->flags & 0x80) {
        self->mask1 = 0xff;
        self->mask2 = 0xff;
        return;
    }
    self->mask1 = 0;
    self->mask2 = 0;
    for (int i = 0; i < 4; i++) {
        if (((Data*)((char*)self->data + i * 0x5c))->value) {
            self->mask1 |= 1 << i;
            self->mask2 |= 1 << (((Data*)((char*)self->data + i * 0x5c))->value - 1);
            self->indices[((Data*)((char*)self->data + i * 0x5c))->value] = i;
        }
    }
    if (self->mask2 == 0) self->mask2 = 0xff;
    if (self->mask1 == 0) self->mask1 = 0xff;
}
