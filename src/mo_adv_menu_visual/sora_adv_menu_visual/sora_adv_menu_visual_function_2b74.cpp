#pragma force_active on
struct Obj {
    unsigned char pad[0xB4];
    int result;
    unsigned char pad2[0x340 - 0xB8];
    int count;
    int state;
};

extern "C" int fn_29_2B74(Obj* self) {
    int count = ++self->count;
    if (count >= 0x78) {
        self->state = 2;
        return 3;
    }
    return self->result;
}
