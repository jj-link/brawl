#pragma force_active on
struct Info { char pad[0xe]; unsigned short flags; };
struct Entry { Info* info; char pad[12]; };
struct Data { char pad[0x1a]; unsigned short count; Entry* entries; };
struct Object_vptr_32c_base {
    char pad0[0x10]; unsigned char flags; char pad11[0xb]; Data* data;
    char pad20[0x2a9]; unsigned char state; unsigned char result; char pad2cb[0x61];
};
class Object_vptr_32c : public Object_vptr_32c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(Entry*);
};
extern "C" int fn_80122D6C(Object_vptr_32c* self) {
    unsigned short total = self->data->count;
    int count = 0;
    unsigned char flags = self->flags;
    unsigned short mask = 0;
    self->result = 0;
    if (flags & 1) mask |= 2;
    if (flags & 8) mask |= 1;
    if (flags & 2) mask |= 4;
    if (flags & 4) mask |= 8;
    for (unsigned int i = 0; i < total; ++i) {
        Entry* entry = &self->data->entries[i];
        if ((entry->info->flags & mask) &&
            (((((unsigned char*)entry->info)[15] >> 1) & 1) || (((unsigned char*)entry->info)[15] & 1)) &&
            self->slot4(entry)) {
            ++count;
        }
    }
    self->state |= self->result;
    return count != 0;
}