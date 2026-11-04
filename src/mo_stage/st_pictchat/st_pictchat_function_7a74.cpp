#include <mt/mt_vector.h>
#include <st/se_util.h>
#pragma force_active on

struct Constants { float x[35]; };
extern "C" const Constants lbl_73_rodata_78;
extern "C" void* lbl_73_data_25F0[];
extern "C" void* lbl_73_data_2878[];
extern "C" void fn_73_34A4(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(StSeUtil::SeSeq*, StSeUtil::UnkStruct2*, unsigned long, StSeUtil::UnkStruct3*, unsigned long);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);

struct Self {
    char pad0[0x3c];
    void* vtbl;
    char pad1[0x294 - 0x40];
    char seq[0x4c];
    SndID ids[2];
    StSeUtil::UnkStruct arr[3];
    char gen[8];
};

extern "C" Self* fn_73_7A74(Self* self) {
    Constants* d = (Constants*)&lbl_73_rodata_78;
    fn_73_34A4(self);
    self->vtbl = lbl_73_data_25F0;
    StSeUtil::SeSeq* seq = (StSeUtil::SeSeq*)self->seq;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, (StSeUtil::UnkStruct2*)((char*)seq + 0x20), 1, (StSeUtil::UnkStruct3*)((char*)seq + 0x2c), 2);
    *(void**)seq = lbl_73_data_2878;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)self->gen);
    self->ids[0] = (SndID)0x1d28;
    self->ids[1] = (SndID)0x1d29;
    self->arr[0].id = (SndID)0x1d28;
    self->arr[0].unk4 = d->x[0];
    self->arr[0].unk8 = d->x[32];
    self->arr[0].unkC = d->x[0];
    self->arr[1].id = (SndID)0x1d29;
    self->arr[1].unk4 = d->x[0];
    self->arr[1].unk8 = d->x[33];
    self->arr[1].unkC = d->x[0];
    self->arr[2].id = (SndID)0x1d29;
    self->arr[2].unk4 = d->x[0];
    self->arr[2].unk8 = d->x[34];
    self->arr[2].unkC = d->x[0];
    seq->registId(self->ids, 2);
    seq->registSeq(0, self->arr, 3, (Heaps::HeapType)15);
    *(snd3DGenerator**)((char*)self + 0x2a8) = (snd3DGenerator*)self->gen;
    float v[3];
    v[0] = d->x[0];
    v[1] = d->x[0];
    v[2] = d->x[0];
    ((snd3DGenerator*)self->gen)->setPos((Vec3f*)v);
    return self;
}
