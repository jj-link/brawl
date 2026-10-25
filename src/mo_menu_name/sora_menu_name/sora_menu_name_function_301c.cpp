#pragma force_active on
struct Entry {
    unsigned char flag : 1;
    unsigned char other : 7;
    short value;
};
struct Menu {
    unsigned char pad[0x1f0];
    Entry entries[122];
    unsigned short count;
};

extern "C" void fn_16_301C(Menu* self, short value) {
    for (int i = self->count - 1; i >= 1; --i)
        self->entries[i + 1] = self->entries[i];
    self->entries[1].flag = 0;
    self->entries[1].value = value;
    ++self->count;
    if (self->count > 5) {
        Entry* p = &self->entries[self->count];
        if (p[-1].value != -2) {
            p->value = -2;
            self->entries[self->count].flag = 0;
            ++self->count;
        }
    }
}
