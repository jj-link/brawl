#pragma force_active on
struct Obj {
    char pad0[0x20];
    unsigned char active;
    char pad21[0xc8-0x21];
    unsigned char state;
    char padc9[0xd8-0xc9];
    unsigned char* flags;
    int count;
};
extern "C" void fn_80095B5C(Obj* self, int value) {
    if (self->active == 0) return;
    if (value != 0 && self->state == 0) {
        for (int i = 0; i < self->count; i++)
            self->flags[i] = 1;
    }
    if (value == 0) {
        for (int i = 0; i < self->count; i++)
            self->flags[i] = 0;
    }
    self->state = value;
}