#pragma force_active on
typedef unsigned char u8;

struct Self {
    u8 flags;
    char pad[0x17c - 1];
    void* field17c;
};

extern "C" void fn_800DDCF8(Self* self, void* arg);

extern "C" void fn_800DDCE4(Self* self) {
    self->flags |= 0x40;
    fn_800DDCF8(self, self->field17c);
}
