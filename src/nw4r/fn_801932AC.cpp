#include <types.h>
#include <nw4r/g3d/g3d_resdict.h>
#pragma force_active on

struct Data { char pad[0x10]; int offset; char pad2[8]; u16 frames; };
struct Track { u32 unused; u32 flags; u32 bits[1]; };
extern "C" double fn_804005AC(double);
extern float lbl_805A31C8;

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

extern "C" bool fn_801932AC(Owner* __restrict obj, int index, float frame) {
    Track* track = (Track*)obj->ofs_to_obj<Dic>(obj->ref().offset)[index];
    u32 flags = track->flags;
    Data* data = obj->data;
    if (flags & 2) {
        return (flags & 1) != 0;
    }
    float value;
    if (frame <= lbl_805A31C8) {
        value = lbl_805A31C8;
    } else if ((float)data->frames <= frame) {
        value = (float)data->frames;
    } else {
        value = frame;
    }
    int n = (int)(float)fn_804005AC(value);
    u32 word = track->bits[(u32)n >> 5];
    u32 mask = 0x80000000u >> (n & 31);
    return (word & mask) != 0;
}
