#include <types.h>
#include <nw4r/g3d/g3d_anmvis.h>

#pragma force_active on

extern "C" {
extern char lbl_80465C80[];
extern char lbl_80465CC4[];
extern const float lbl_805A3258;
extern const float lbl_805A325C;
extern const unsigned int lbl_8059C648[2];
void* fn_80204E5C(MEMAllocator*, unsigned int);
}

class ObjectVtable {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8();
    virtual void slot9(); virtual void slot10(); virtual void slot11();
};

struct VisObject {
    void* vt;
    unsigned int unk04;
    MEMAllocator* allocator;
    unsigned int unk0c;
    unsigned int count;
    unsigned short* bindings;
    float frame;
    float rate;
    float start;
    float end;
    unsigned int update;
    nw4r::g3d::ResAnmVisData* resource;
};

inline nw4r::g3d::ResAnmVisData* GetData(nw4r::g3d::ResAnmVis anim) { return anim.ptr(); }
inline void InitVis(VisObject* obj, MEMAllocator* allocator, unsigned int count,
                    unsigned short* bindings, nw4r::g3d::ResAnmVis& anim) {
    if (obj) {
        nw4r::g3d::ResAnmVisData* data = GetData(anim);
        obj->unk04 = 0;
        obj->allocator = allocator;
        obj->unk0c = 0;
        obj->vt = lbl_80465CC4;
        obj->count = count;
        obj->bindings = bindings;
        ((ObjectVtable*)obj)->slot11();
        unsigned int update = lbl_8059C648[*(unsigned int*)((char*)data + 0x20)];
        float end = (float)(int)data->m_animLength;
        obj->frame = lbl_805A3258;
        obj->rate = lbl_805A325C;
        obj->start = lbl_805A3258;
        obj->end = end;
        obj->update = update;
        obj->vt = lbl_80465C80;
        obj->resource = data;
    }
}

nw4r::g3d::AnmObjVisRes* nw4r::g3d::AnmObjVisRes::Construct(
    MEMAllocator* allocator, int* instanceSize, ResAnmVis anim, ResMdl mdl) {
    int* output = instanceSize;
    VisObject* obj;
    if (anim.ptr() == 0 || mdl.ptr() == 0) return 0;
    unsigned int count = mdl.GetResNodeNumEntries();
    unsigned int size = count * 2 + 0x30;
    if (output) *output = size;
    if (!allocator) return 0;
    obj = (VisObject*)fn_80204E5C(allocator, size);
    if (!obj) return 0;
    unsigned short* bindings = (unsigned short*)((char*)obj + 0x30);
    InitVis(obj, allocator, count, bindings, anim);
    return (AnmObjVisRes*)obj;
}
