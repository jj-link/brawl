#pragma force_active on
#include <mt/mt_vector.h>
#include <st/se_util.h>
#include <snd/snd_3d_generator.h>

extern "C" void fn_57_3980(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern char lbl_57_data_3120[];
extern char lbl_57_data_1740[];
extern const float lbl_57_rodata_390;
extern const float lbl_57_rodata_394;

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

extern "C" char* fn_57_11408(char* self) {
    fn_57_3980(self);
    char* seq = self + 0x170;
    *(void**)(self + 0x3c) = lbl_57_data_3120;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 2, seq + 0x38, 2);
    *(void**)seq = lbl_57_data_1740;
    __ct__14snd3DGeneratorFv(self + 0x1f0);
    *(int*)(self + 0x160) = 0;
    *(char*)(self + 0x164) = 3;
    *(float*)(self + 0x168) = lbl_57_rodata_390;
    *(float*)(self + 0x16c) = lbl_57_rodata_390;
    Class_2110* m = (Class_2110*)(self + 0xd0);
    if (!m) return self;
    m->field8 = 1;
    m->fn_57_AB4C(0, 15);
    m->inner->flags |= 8;
    *(int*)(self + 0x1c8) = 0x1be4;
    *(int*)(self + 0x1cc) = 0x1be5;
    *(int*)(self + 0x1d0) = 0x1be4;
    *(float*)(self + 0x1d4) = lbl_57_rodata_390;
    *(float*)(self + 0x1d8) = lbl_57_rodata_390;
    *(float*)(self + 0x1dc) = lbl_57_rodata_390;
    *(int*)(self + 0x1e0) = 0x1be5;
    *(float*)(self + 0x1e4) = lbl_57_rodata_390;
    *(float*)(self + 0x1e8) = lbl_57_rodata_394;
    *(float*)(self + 0x1ec) = lbl_57_rodata_390;
    ((StSeUtil::SeSeq*)(self + 0x170))->registId((SndID*)(self + 0x1c8), 2);
    ((StSeUtil::SeSeq*)(self + 0x170))->registSeq(0, (StSeUtil::UnkStruct*)(self + 0x1d0), 1, (Heaps::HeapType)15);
    ((StSeUtil::SeSeq*)(self + 0x170))->registSeq(1, (StSeUtil::UnkStruct*)(self + 0x1e0), 1, (Heaps::HeapType)15);
    ((StSeUtil::SeSeq*)(self + 0x170))->m_sndGenerator = (snd3DGenerator*)(self + 0x1f0);
    return self;
}