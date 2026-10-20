#pragma force_active on
struct Entry {
    unsigned char padding[0x36];
    unsigned short flags;
};

struct EntryArray {
    virtual void unused();
    virtual Entry& at(unsigned int index) const;
};

struct Object {
    unsigned char padding[0x28];
    EntryArray* entries;
};

extern "C" bool fn_27_2997C(const Object* self, unsigned int bit, unsigned int index) {
    Entry& entry = self->entries->at(index);
    return entry.flags & (1 << bit);
}
