#pragma force_active on
struct Entry {
    unsigned int value;
    unsigned int unk;
};

struct Block {
    unsigned int count;
    unsigned int pad;
    Entry entries[1];
};

struct Owner {
    unsigned int pad0[5];
    Block* block;
};

extern "C" void fn_801CA430(Owner* self, unsigned int min, unsigned int max) {
    if (self->block) {
        for (unsigned int i = 0; i < self->block->count; ++i) {
            if (min <= self->block->entries[i].value && self->block->entries[i].value <= max) {
                self->block->entries[i].value = 0;
            }
        }
    }
}
