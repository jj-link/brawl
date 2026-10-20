#pragma force_active on
struct Entry {
    int state;
    char pad[0x54];
};

struct Menu {
    char pad[0x70];
    Entry entries[9];
};

extern "C" void fn_11_7DE4(Menu* self) {
    for (int i = 0; i < 9; ++i) {
        if (self->entries[i].state == 2)
            self->entries[i].state = 5;
        else
            self->entries[i].state = 0;
    }
}
