#include <types.h>
#include <nw4r/g3d/g3d_anmchr.h>

#pragma force_active on

extern "C" {
extern char lbl_80465FC0[];
extern char lbl_80465EB8[];
extern const unsigned int lbl_8059C648[2];
extern const float lbl_805A32A8;
extern const float lbl_805A32AC;
void* fn_80204E5C(void*, unsigned int);
void fn_8019564C(void*, void*, unsigned int, float);
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

struct ChrObject {
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
    nw4r::g3d::ResAnmChrData* resource;
    void* cache;
};

inline void UpdateCache(ChrObject* obj)
{
    if (obj->cache) {
        float frame = obj->frame;
        for (unsigned int i = 0; i < obj->count; i++) {
            unsigned short entry = obj->bindings[i];
            if (!(entry & 0x8000)) {
                unsigned int index = entry & 0x3FFF;
                fn_8019564C(&obj->resource,
                    (char*)obj->cache + index * 0x4C, index, frame);
            }
        }
    }
}

inline unsigned int GetAnimationCount(nw4r::g3d::ResAnmChrData* data)
{
    return *(unsigned short*)((char*)data + 0x1E);
}

nw4r::g3d::AnmObjChrRes* nw4r::g3d::AnmObjChrRes::Construct(
    MEMAllocator* allocator, int* pSize, ResAnmChr anm, ResMdl mdl, bool flag)
{
    int* output = pSize;
    unsigned short idx;
    ChrObject* obj;
    ResAnmChrData* data;
    if (anm.ptr() == 0 || !mdl.IsValid())
        return 0;
    idx = GetAnimationCount(anm.ptr());
    unsigned int count = mdl.GetResNodeNumEntries();
    int mask = (-(int)flag | (int)flag) >> 31;
    int off = (idx & mask) * 0x4C;
    int size = off + count * 2 + 0x34;
    if (output)
        *output = size;
    if (!allocator)
        return 0;
    obj = (ChrObject*)fn_80204E5C(allocator, size);
    if (!obj)
        return 0;
    void* arr = flag ? (void*)((char*)obj + 0x34) : 0;
    unsigned short* tbl = (unsigned short*)((char*)(obj + 1) + off);
    if (obj) {
        data = anm.ptr();
        obj->unk04 = 0;
        obj->allocator = allocator;
        obj->unk0C = 0;
        obj->vt = lbl_80465FC0;
        obj->count = count;
        obj->bindings = tbl;
        ((Object_vptr_0*)obj)->slot11();
        unsigned int update = lbl_8059C648[*(unsigned int*)((char*)data + 0x20)];
        float end = (float)(int)data->m_animLength;
        obj->frame = lbl_805A32A8;
        obj->rate = lbl_805A32AC;
        obj->start = lbl_805A32A8;
        obj->end = end;
        obj->update = update;
        obj->vt = lbl_80465EB8;
        obj->resource = data;
        obj->cache = arr;
        UpdateCache(obj);
    }
    return (AnmObjChrRes*)obj;
}
