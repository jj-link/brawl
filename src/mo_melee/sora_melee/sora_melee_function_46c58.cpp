#pragma force_active on

extern "C" void fn_27_36074(int, int, int, int);
extern "C" void fn_27_46784(void*, void*);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void* slot1(int index);
};

struct Entry {
    unsigned char pad[0x1C];
    unsigned int flags;
};

struct Header {
    Entry* entries;
    int count;
    unsigned int flags;
};

struct Self {
    void* unk0;
    short unk4;
    short unk6;
    unsigned char pad8[0xA8];
    signed char unkB0;
    signed char unkB1;
    signed char unkB2;
    signed char unkB3;
    signed char unkB4;
};

extern "C" int fn_27_46C58(
    Self* self, int arg1, Object_vptr_0* obj, const Header* hdr, int context, int start)
{
    unsigned int flags = hdr->flags;
    int count = hdr->count;
    int i;
    Entry* entry;

    self->unkB0 = static_cast<signed char>(flags >> 31);
    self->unkB1 = static_cast<signed char>((flags >> 30) & 1);
    self->unkB2 = static_cast<signed char>((flags >> 29) & 1);
    self->unkB4 = static_cast<signed char>((flags >> 28) & 1);

    i = 0;
    entry = hdr->entries;

    while (i < count) {
        fn_27_36074(arg1, i, (entry->flags >> 22) & 1, context);
        fn_27_46784(obj->slot1(start + i), entry);
        entry++;
        i++;
    }

    self->unk4 = static_cast<short>(start);
    self->unk6 = static_cast<short>(i);
    self->unk0 = reinterpret_cast<void*>(context);
    return i;
}
