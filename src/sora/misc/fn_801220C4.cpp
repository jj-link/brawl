#pragma force_active on
struct Info { char pad[0xe]; unsigned short flags; };
struct Entry { Info* info; char pad[12]; };
struct Data { char pad[0x1a]; unsigned short count; Entry* entries; };
struct Class_8045DA20_base {
    char pad0[0x10]; unsigned char flags; char pad11[0xb]; Data* data;
    char pad20[0x2a8]; unsigned char state; char pad2c9; unsigned char result; char pad2cb[0x61];
};
class Class_8045DA20 : public Class_8045DA20_base {
public:
    virtual void fn_80125930();
    virtual void fn_80125E1C();
    virtual void fn_80125E30();
    virtual void fn_80126B48();
    virtual int fn_80126F40(Entry*);
};
struct Class_8045DA58_base { char pad[0x32c]; };
class Class_8045DA58 : public Class_8045DA58_base {
public:
    virtual void fn_80132078();
    virtual void fn_801321FC();
    virtual void fn_80132210();
    virtual void fn_8012407C();
    virtual int fn_80132230(Entry*);
};
extern "C" int fn_801220C4(Class_8045DA20* self) {
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
            self->fn_80126F40(entry)) {
            ++count;
        }
    }
    self->state |= self->result;
    return count != 0;
}