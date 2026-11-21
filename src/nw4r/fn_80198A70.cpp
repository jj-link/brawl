#include <types.h>
#include <nw4r/g3d/g3d_anmtexpat.h>

#pragma force_active on

extern "C" {
extern char lbl_80465DE0[];
extern char lbl_80465D98[];
extern const unsigned int lbl_8059C648[2];
extern const float lbl_805A3278;
extern const float lbl_805A327C;
unsigned int fn_8018F394(void*);
void* fn_80204E5C(void*, unsigned int);
void fn_801935E4(void*, void*, unsigned int, float);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
};

struct AnmPatData {
    char pad[0x2C];
    unsigned short length;
    unsigned short count;
    unsigned int reserved;
    unsigned int loop;
};

struct TexPatObject {
    void* vt;
    unsigned int unk04;
    void* allocator;
    unsigned int unk0C;
    unsigned int count;
    unsigned short* bindings;
    float frame;
    float rate;
    float start;
    float end;
    unsigned int update;
    void* resource;
    void* cache;
};

inline void UpdateCache(TexPatObject* obj)
{
    if (obj->cache) {
        float frame = obj->frame;
        for (unsigned int i = 0; i < obj->count; i++) {
            unsigned short entry = obj->bindings[i];
            if (!(entry & 0x8000)) {
                unsigned int index = entry & 0x3FFF;
                fn_801935E4(&obj->resource, (char*)obj->cache + index * 0x44, index, frame);
            }
        }
    }
}

inline unsigned int GetAnimationCount(AnmPatData* data)
{
    return data->count;
}

nw4r::g3d::AnmObjTexPatRes* nw4r::g3d::AnmObjTexPatRes::Construct(
    MEMAllocator* allocator, int* pSize, ResAnmTexPat anm, ResMdl mdl, bool flag)
{
    int* output = pSize;
    unsigned short idx;
    TexPatObject* obj;
    AnmPatData* data;
    if (*(AnmPatData**)&anm == 0 || *(unsigned int*)&mdl == 0)
        return 0;
    idx = GetAnimationCount(*(AnmPatData**)&anm);
    unsigned int count = fn_8018F394(&mdl);
    int mask = (-(int)flag | (int)flag) >> 31;
    int off = (idx & mask) * 0x44;
    int size = off + count * 2 + 0x34;
    if (output)
        *output = size;
    if (!allocator)
        return 0;
    obj = (TexPatObject*)fn_80204E5C(allocator, size);
    if (!obj)
        return 0;
    void* arr = flag ? (void*)((char*)obj + 0x34) : 0;
    unsigned short* tbl = (unsigned short*)((char*)(obj + 1) + off);
    if (obj) {
        data = *(AnmPatData**)&anm;
        obj->unk04 = 0;
        obj->allocator = allocator;
        obj->unk0C = 0;
        obj->vt = lbl_80465DE0;
        obj->count = count;
        obj->bindings = tbl;
        ((Object_vptr_0*)obj)->slot11();
        unsigned int update = lbl_8059C648[data->loop];
        float end = (float)(int)data->length;
        obj->frame = lbl_805A3278;
        obj->rate = lbl_805A327C;
        obj->start = lbl_805A3278;
        obj->end = end;
        obj->update = update;
        obj->vt = lbl_80465D98;
        obj->resource = data;
        obj->cache = arr;
        UpdateCache(obj);
    }
    return (nw4r::g3d::AnmObjTexPatRes*)obj;
}
