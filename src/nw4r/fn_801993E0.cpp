#include <types.h>
#include <nw4r/g3d/g3d_anmtexsrt.h>

#pragma force_active on

extern "C" {
extern char lbl_80465E70[];
extern char lbl_80465E28[];
extern const unsigned int lbl_8059C648[2];
extern const float lbl_805A3288;
extern const float lbl_805A328C;
unsigned int fn_8018F394(void*);
void* fn_80204E5C(void*, unsigned int);
void fn_80193A74(void*, void*, unsigned int, float);
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

struct AnmSrtData {
    char pad[0x1C];
    unsigned short length;
    unsigned short count;
    unsigned int mode;
    unsigned int loop;
};

struct TexSrtObject {
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

inline void UpdateCache(TexSrtObject* obj)
{
    if (obj->cache) {
        float frame = obj->frame;
        for (unsigned int i = 0; i < obj->count; i++) {
            unsigned short entry = obj->bindings[i];
            if (!(entry & 0x8000)) {
                unsigned int index = entry & 0x3FFF;
                fn_80193A74(&obj->resource, (char*)obj->cache + index * 0xE8, index, frame);
            }
        }
    }
}

inline unsigned int GetAnimationCount(AnmSrtData* data)
{
    return data->count;
}

nw4r::g3d::AnmObjTexSrtRes* nw4r::g3d::AnmObjTexSrtRes::Construct(
    MEMAllocator* allocator, int* pSize, ResAnmTexSrt anm, ResMdl mdl, bool flag)
{
    int* output = pSize;
    unsigned short idx;
    TexSrtObject* obj;
    AnmSrtData* data;
    if (*(AnmSrtData**)&anm == 0 || *(unsigned int*)&mdl == 0)
        return 0;
    idx = GetAnimationCount(*(AnmSrtData**)&anm);
    unsigned int count = fn_8018F394(&mdl);
    int mask = (-(int)flag | (int)flag) >> 31;
    int off = (idx & mask) * 0xE8;
    int size = off + count * 2 + 0x34;
    if (output)
        *output = size;
    if (!allocator)
        return 0;
    obj = (TexSrtObject*)fn_80204E5C(allocator, size);
    if (!obj)
        return 0;
    void* arr = flag ? (void*)((char*)obj + 0x34) : 0;
    unsigned short* tbl = (unsigned short*)((char*)(obj + 1) + off);
    if (obj) {
        data = *(AnmSrtData**)&anm;
        obj->unk04 = 0;
        obj->allocator = allocator;
        obj->unk0C = 0;
        obj->vt = lbl_80465E70;
        obj->count = count;
        obj->bindings = tbl;
        ((Object_vptr_0*)obj)->slot11();
        unsigned int update = lbl_8059C648[data->loop];
        float end = (float)(int)data->length;
        obj->frame = lbl_805A3288;
        obj->rate = lbl_805A328C;
        obj->start = lbl_805A3288;
        obj->end = end;
        obj->update = update;
        obj->vt = lbl_80465E28;
        obj->resource = data;
        obj->cache = arr;
        UpdateCache(obj);
    }
    return (nw4r::g3d::AnmObjTexSrtRes*)obj;
}
