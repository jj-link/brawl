#pragma force_active on
struct Data { char pad[0xd5]; unsigned char value; };
struct Self {
    char pad0[0x44]; Data* data;
    char pad1[0xc0 - 0x48]; unsigned int flags;
    char pad2[0xcc - 0xc4]; int mask;
    char pad3[0xec - 0xd0]; int idx[256];
};
extern "C" void fn_27_2559E4(Self* self) {
    if (self->flags & 0x80) {
        self->mask = 0xff;
        return;
    }
    self->mask = 0;
    unsigned int t = (*((unsigned char*)self->data + 8) >> 2) & 0x3f;
    if (t != 0 && t != 1) {
        for (int i = 0; i < 4; i++) {
            if (((Data*)((char*)self->data + i * 0x5c))->value) {
                self->mask |= 1 << (((Data*)((char*)self->data + i * 0x5c))->value - 1);
                self->idx[((Data*)((char*)self->data + i * 0x5c))->value] = i;
            }
        }
    }
    if (self->mask == 0) self->mask = 0xff;
}
