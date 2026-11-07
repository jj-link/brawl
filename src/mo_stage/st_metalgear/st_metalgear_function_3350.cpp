#include <mt/mt_vector.h>
#include <st/se_util.h>
#pragma force_active on
struct Constants { float x[26]; };
extern "C" const Constants lbl_71_rodata_58;
extern "C" void* lbl_71_data_10D8[];
extern "C" void* lbl_71_data_1318[];
extern "C" void fn_71_2BC0(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(StSeUtil::SeSeq*, StSeUtil::UnkStruct2*, unsigned long, StSeUtil::UnkStruct3*, unsigned long);
struct Self {
 char pad0[0x3c]; void* vtbl;
 char pad1[0x198-0x40]; float f[6]; unsigned char b; char pad2[3]; int i;
 char seq[0xac]; SndID ids[5]; StSeUtil::UnkStruct arr[22];
};
extern "C" Self* fn_71_3350(Self* self) {
 Constants* d = (Constants*)&lbl_71_rodata_58;
 fn_71_2BC0(self);
 self->vtbl = lbl_71_data_10D8;
 StSeUtil::SeSeq* seq = (StSeUtil::SeSeq*)self->seq;
 __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, (StSeUtil::UnkStruct2*)((char*)seq+0x20), 5, (StSeUtil::UnkStruct3*)((char*)seq+0x5c), 5);
 *(void**)seq = lbl_71_data_1318;
 self->f[0] = d->x[0];
 self->f[1] = d->x[0];
 self->f[2] = d->x[0];
 self->f[3] = d->x[0];
 self->f[4] = d->x[0];
 self->f[5] = d->x[0];
 self->b = 0; self->i = -1;
 self->ids[0] = (SndID)0x1d12;
 self->ids[1] = (SndID)0x1d13;
 self->ids[2] = (SndID)0x1d14;
 self->ids[3] = (SndID)0x1d15;
 self->ids[4] = (SndID)0x1d10;
 self->arr[0].id = (SndID)0x1d12; self->arr[0].unk4 = d->x[0]; self->arr[0].unk8 = d->x[4]; self->arr[0].unkC = d->x[0];
 self->arr[1].id = (SndID)0x1d13; self->arr[1].unk4 = d->x[0]; self->arr[1].unk8 = d->x[5]; self->arr[1].unkC = d->x[0];
 self->arr[2].id = (SndID)0x1d10; self->arr[2].unk4 = d->x[0]; self->arr[2].unk8 = d->x[6]; self->arr[2].unkC = d->x[0];
 self->arr[3].id = (SndID)0x1d12; self->arr[3].unk4 = d->x[0]; self->arr[3].unk8 = d->x[7]; self->arr[3].unkC = d->x[0];
 self->arr[4].id = (SndID)0x1d13; self->arr[4].unk4 = d->x[0]; self->arr[4].unk8 = d->x[8]; self->arr[4].unkC = d->x[0];
 self->arr[5].id = (SndID)0x1d14; self->arr[5].unk4 = d->x[0]; self->arr[5].unk8 = d->x[9]; self->arr[5].unkC = d->x[0];
 self->arr[6].id = (SndID)0x1d15; self->arr[6].unk4 = d->x[0]; self->arr[6].unk8 = d->x[10]; self->arr[6].unkC = d->x[0];
 self->arr[7].id = (SndID)0x1d14; self->arr[7].unk4 = d->x[0]; self->arr[7].unk8 = d->x[11]; self->arr[7].unkC = d->x[0];
 self->arr[8].id = (SndID)0x1d15; self->arr[8].unk4 = d->x[0]; self->arr[8].unk8 = d->x[12]; self->arr[8].unkC = d->x[0];
 self->arr[9].id = (SndID)0x1d12; self->arr[9].unk4 = d->x[0]; self->arr[9].unk8 = d->x[13]; self->arr[9].unkC = d->x[0];
 self->arr[10].id = (SndID)0x1d13; self->arr[10].unk4 = d->x[0]; self->arr[10].unk8 = d->x[14]; self->arr[10].unkC = d->x[0];
 self->arr[11].id = (SndID)0x1d13; self->arr[11].unk4 = d->x[0]; self->arr[11].unk8 = d->x[15]; self->arr[11].unkC = d->x[0];
 self->arr[12].id = (SndID)0x1d14; self->arr[12].unk4 = d->x[0]; self->arr[12].unk8 = d->x[16]; self->arr[12].unkC = d->x[0];
 self->arr[13].id = (SndID)0x1d15; self->arr[13].unk4 = d->x[0]; self->arr[13].unk8 = d->x[17]; self->arr[13].unkC = d->x[0];
 self->arr[14].id = (SndID)0x1d12; self->arr[14].unk4 = d->x[0]; self->arr[14].unk8 = d->x[18]; self->arr[14].unkC = d->x[0];
 self->arr[15].id = (SndID)0x1d13; self->arr[15].unk4 = d->x[0]; self->arr[15].unk8 = d->x[19]; self->arr[15].unkC = d->x[0];
 self->arr[16].id = (SndID)0x1d12; self->arr[16].unk4 = d->x[0]; self->arr[16].unk8 = d->x[20]; self->arr[16].unkC = d->x[0];
 self->arr[17].id = (SndID)0x1d13; self->arr[17].unk4 = d->x[0]; self->arr[17].unk8 = d->x[21]; self->arr[17].unkC = d->x[0];
 self->arr[18].id = (SndID)0x1d15; self->arr[18].unk4 = d->x[0]; self->arr[18].unk8 = d->x[22]; self->arr[18].unkC = d->x[0];
 self->arr[19].id = (SndID)0x1d12; self->arr[19].unk4 = d->x[0]; self->arr[19].unk8 = d->x[23]; self->arr[19].unkC = d->x[0];
 self->arr[20].id = (SndID)0x1d12; self->arr[20].unk4 = d->x[0]; self->arr[20].unk8 = d->x[24]; self->arr[20].unkC = d->x[0];
 self->arr[21].id = (SndID)0x1d13; self->arr[21].unk4 = d->x[0]; self->arr[21].unk8 = d->x[25]; self->arr[21].unkC = d->x[0];
 seq->registId(self->ids, 5);
 seq->registSeq(0, self->arr, 7, (Heaps::HeapType)15);
 seq->registSeq(1, self->arr+7, 4, (Heaps::HeapType)15);
 seq->registSeq(2, self->arr+11, 3, (Heaps::HeapType)15);
 seq->registSeq(3, self->arr+14, 6, (Heaps::HeapType)15);
 seq->registSeq(4, self->arr+20, 2, (Heaps::HeapType)15);
 return self;
}