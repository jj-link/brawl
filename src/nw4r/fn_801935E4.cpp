#include <types.h>
#pragma force_active on

extern "C" const void* fn_80193538(const void*, float);

struct Data {
    char pad[0x10];
    int anim;
    char pad2[8];
    int table1;
    int table2;
};

struct Node {
    u16 ref, flag, left, right;
    int stringOffset, dataOffset;
};
struct DicData {
    u32 size, count;
    Node nodes[1];
};
template <typename T>
class Resource {
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
class Dic : public Resource<DicData> {
public:
    Dic(void* p) : Resource<DicData>(p) {}
    void* operator[](int index) const {
        if (data) return const_cast<void*>(ofs_to_ptr<void>(ref().nodes[index + 1].dataOffset));
        return 0;
    }
};
class Owner : public Resource<Data> {};

struct Result {
    u8 flags1;
    u8 flags2;
    u8 pad[2];
    u32 table1[8];
    u32 table2[8];
};

extern "C" void fn_801935E4(Owner* self, Result* out, int index, float frame) {
    char* entry = (char*)self->ofs_to_obj<Dic>(self->ref().anim)[index];
    u32* table1;
    u32* table2;
    Result* dest;
    u32* cursor;
    u32 flags;
    Data* data = self->data;
    cursor = (u32*)(entry + 8);
    flags = *(u32*)(entry + 4);
    if (data->table1)
        table1 = (u32*)((char*)data + data->table1);
    else
        table1 = 0;
    if (data->table2)
        table2 = (u32*)((char*)data + data->table2);
    else
        table2 = 0;
    dest = out;
    out->flags1 = 0;
    out->flags2 = 0;
    for (int i = 0; i < 8; i++) {
        if (flags & 1) {
            u32 a, b;
            if (flags & 2) {
                a = ((u16*)cursor)[0];
                b = ((u16*)cursor)[1];
            } else {
                const u16* p = (const u16*)fn_80193538((void*)(*cursor + (u32)entry), frame);
                a = p[2];
                b = p[3];
            }
            int bit = 1 << i;
            if (flags & 4) {
                u32 v = table1[a];
                if (v) {
                    dest->table1[0] = v;
                    out->flags1 |= bit;
                }
            }
            if (flags & 8) {
                u32 v = table2[b];
                if (v) {
                    dest->table2[0] = v;
                    out->flags2 |= bit;
                }
            }
            cursor++;
        }
        flags >>= 4;
        dest = (Result*)((char*)dest + 4);
    }
}
