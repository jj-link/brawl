#pragma force_active on
#include <mt/mt_vector.h>
#include <st/se_util.h>
#include <snd/snd_3d_generator.h>

extern "C" void fn_57_3980(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern char lbl_57_data_1500[];
extern char lbl_57_data_1740[];
struct Constants { float f[6]; };
extern "C" const Constants lbl_57_rodata_210;
struct Inner { int pad; unsigned int flags; };
class Class_2110 {
public:
    virtual void fn_57_C674();
    virtual void fn_57_BA94();
    virtual void fn_57_BAA4();
    virtual void fn_57_ADD8();
    virtual void fn_57_AB4C(int, int);
    Inner* inner;
    int field8;
};
extern "C" char* fn_57_7518(char* self) {
    Constants* d = (Constants*)&lbl_57_rodata_210;
    fn_57_3980(self);
    char* seq = self + 0x1a4;
    *(void**)(self + 0x3c) = lbl_57_data_1500;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 2, seq + 0x38, 2);
    *(void**)seq = lbl_57_data_1740;
    __ct__14snd3DGeneratorFv(self + 0x244);
    *(float*)(self + 0x160) = d->f[0];
    *(int*)(self + 0x164) = 0;
    *(int*)(self + 0x168) = 0;
    *(int*)(self + 0x16c) = 0;
    *(int*)(self + 0x170) = 0;
    *(float*)(self + 0x174) = d->f[0];
    *(float*)(self + 0x178) = d->f[0];
    *(float*)(self + 0x17c) = d->f[0];
    *(float*)(self + 0x180) = d->f[0];
    *(float*)(self + 0x184) = d->f[0];
    *(float*)(self + 0x188) = d->f[0];
    *(float*)(self + 0x18c) = d->f[0];
    *(float*)(self + 0x190) = d->f[0];
    *(float*)(self + 0x194) = d->f[0];
    *(float*)(self + 0x198) = d->f[0];
    *(char*)(self + 0x19c) = 5;
    *(float*)(self + 0x1a0) = d->f[0];
    Class_2110* m = (Class_2110*)(self + 0xd0);
    if (!m) return self;
    m->field8 = 1;
    m->fn_57_AB4C(0, 15);
    m->inner->flags |= 8;
    *(int*)(self + 0x1fc) = 0x1bf9;
    *(int*)(self + 0x200) = 0x1bfa;
    *(int*)(self + 0x204) = 0x1bf9;
    *(float*)(self + 0x208) = d->f[0];
    *(float*)(self + 0x20c) = d->f[1];
    *(float*)(self + 0x210) = d->f[2];
    *(int*)(self + 0x214) = 0x1bfa;
    *(float*)(self + 0x218) = d->f[0];
    *(float*)(self + 0x21c) = d->f[3];
    *(float*)(self + 0x220) = d->f[0];
    *(int*)(self + 0x224) = 0x1bf9;
    *(float*)(self + 0x228) = d->f[0];
    *(float*)(self + 0x22c) = d->f[0];
    *(float*)(self + 0x230) = d->f[4];
    *(int*)(self + 0x234) = 0x1bfa;
    *(float*)(self + 0x238) = d->f[0];
    *(float*)(self + 0x23c) = d->f[4];
    *(float*)(self + 0x240) = d->f[0];
    ((StSeUtil::SeSeq*)(self + 0x1a4))->registId((SndID*)(self + 0x1fc), 2);
    ((StSeUtil::SeSeq*)(self + 0x1a4))->registSeq(0, (StSeUtil::UnkStruct*)(self + 0x204), 2, (Heaps::HeapType)15);
    ((StSeUtil::SeSeq*)(self + 0x1a4))->registSeq(1, (StSeUtil::UnkStruct*)(self + 0x224), 2, (Heaps::HeapType)15);
    ((StSeUtil::SeSeq*)(self + 0x1a4))->m_sndGenerator = (snd3DGenerator*)(self + 0x244);
    *(int*)(self + 0x24c) = -1;
    *(int*)(self + 0x250) = -1;
    return self;
}