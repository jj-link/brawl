#include <types.h>
#include <nw4r/g3d/g3d_resdict.h>
#pragma force_active on

struct Data { char pad[0x10]; int offset; char pad2[8]; u16 duration; };
struct Self { Data* data; };
struct Entry { u32 a; int b; };
struct Record { u32 unk; u32 flags; Entry entries[1]; };
struct Output { u32 flags; u32 values[11]; u32 attrs[11]; };
extern "C" u32 fn_801931AC(const u32*, float);
extern float lbl_805A31D8;

template <typename T> class Resource {
public:
    T* data;
    Resource(void* p) : data((T*)p) {}
    T& ref() const { return *data; }
    template <typename U> const U* ofs_to_ptr(int ofs) const {
        const u8* p = (const u8*)data;
        if (ofs) return (const U*)(p + ofs);
        return 0;
    }
    template <typename U> U ofs_to_obj(int ofs) const {
        u8* p = (u8*)data;
        if (ofs) return U(p + ofs);
        return U((void*)0);
    }
};
class Dic : public Resource<nw4r::g3d::ResDicData> {
public:
    Dic(void* p) : Resource<nw4r::g3d::ResDicData>(p) {}
    void* operator[](int index) const {
        if (data) return const_cast<void*>(ofs_to_ptr<void>(ref().data[index + 1].ofsData));
        return 0;
    }
};
class Owner : public Resource<Data> {};

static inline void doWork(Owner* self, Output* out, int index, float frame) {
    u32 flags;
    int i;
    Entry* entry;
    Output* dest;
    Record* record = (Record*)self->ofs_to_obj<Dic>(self->ref().offset)[index];
    flags = record->flags;
    entry = record->entries;
    Data* data = self->data;
    out->flags = 0;
    if (flags) {
        float f;
        if (frame <= lbl_805A31D8) f = lbl_805A31D8;
        else {
            u32 duration = data->duration;
            if ((float)duration <= frame) f = (float)duration;
            else f = frame;
        }
        dest = out;
        for (i = 0; i < 11; i++, flags >>= 2) {
            if (flags & 1) {
                out->flags |= 1 << i;
                dest->attrs[0] = entry->a;
                u32 result;
                if (flags & 2) result = entry->b;
                else result = fn_801931AC((u32*)((char*)entry + entry->b + 4), f);
                dest->values[0] = result;
                entry++;
            }
            dest = (Output*)((char*)dest + 4);
        }
    }
}

extern "C" void fn_801933CC(Owner* self, Output* out, int index, float frame) {
    doWork(self, out, index, frame);
}
