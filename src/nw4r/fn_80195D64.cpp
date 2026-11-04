#pragma force_active on

typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;

struct Data {
    char pad[0x14];
    int nameOffset;
    u16 index;
    u8 count;
    u8 pad1B;
    int nameOffsets[8];
    u16 indices[1];
};
struct Handle { Data* ptr; };
struct Result { char pad[0xC]; int index; };

extern "C" int fn_80196848(const Handle*);
extern "C" int fn_801968A8(const Handle*);
extern "C" Result* fn_801969E8(const Handle*, char**);
extern "C" Result* fn_80196B9C(const Handle*, char**);

struct Name {
    char* ptr;
    Name(char* p) : ptr(p) {}
};
static inline Name GetName(Data* p) {
    if (p->nameOffset != 0)
        return Name((char*)p + p->nameOffset - 4);
    return Name(0);
}
static inline int IsBound(const Data* data, int& total) {
    int bound = 1;
    total = 1;
    if (data->nameOffset != 0 && data->index == 0xFFFF)
        bound = 0;
    return bound;
}
extern "C" bool fn_80195D64(Handle* self, const Handle* arg) {
    u8 count;
    u16* index;
    int offset;
    Data* data = self->ptr;
    int total = 0;
    int found = 0;
    if (data->nameOffset != 0 && fn_80196848(arg) != 0) {
        Data* p = self->ptr;
        if (IsBound(p, total) == 0) {
            Name name = GetName(p);
            Result* result = fn_801969E8(arg, &name.ptr);
            if (result) {
                found = 1;
                data->index = result->index;
            }
        } else {
            found = 1;
        }
    }
    if (fn_801968A8(arg) != 0) {
        index = data->indices;
        u32 i = 0;
        offset = 0;
        count = self->ptr->count;
        total += count;
        for (; i < count; ++index, offset += 4, ++i) {
            if (*index != 0xFFFF) {
                ++found;
            } else {
                char* base = (char*)self->ptr->nameOffsets;
                char* name = base + *(int*)(base + offset) - 4;
                Result* result = fn_80196B9C(arg, &name);
                if (result) {
                    ++found;
                    *index = result->index;
                }
            }
        }
    }
    return found == total;
}
