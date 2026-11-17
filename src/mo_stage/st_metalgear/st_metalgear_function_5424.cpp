#include <mt/mt_vector.h>
#include <st/se_util.h>
#pragma force_active on

struct Constants { float x[70]; };
extern "C" const Constants lbl_71_rodata_58;
extern "C" void* lbl_71_data_BF8[];
extern "C" void* lbl_71_data_E28[];
extern "C" void fn_71_2BC0(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(StSeUtil::SeSeq*, StSeUtil::UnkStruct2*, unsigned long, StSeUtil::UnkStruct3*, unsigned long);

struct Self {
 char pad0[0x3c]; void* vtbl;
 char pad1[0x198-0x40];
 char seq[0xfc];
 SndID ids[10];
 StSeUtil::UnkStruct arr[33];
};

extern "C" Self* fn_71_5424(Self* self) {
 Constants* d = (Constants*)&lbl_71_rodata_58;
 fn_71_2BC0(self);
 self->vtbl = lbl_71_data_BF8;
 StSeUtil::SeSeq* seq = (StSeUtil::SeSeq*)self->seq;
 __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, (StSeUtil::UnkStruct2*)((char*)seq + 0x20), 5, (StSeUtil::UnkStruct3*)((char*)seq + 0x5c), 10);
 *(void**)seq = lbl_71_data_E28;
 self->ids[0] = (SndID)0x1d05;
 self->ids[1] = (SndID)0x1d06;
 self->ids[2] = (SndID)0x1d07;
 self->ids[3] = (SndID)0x1d08;
 self->ids[4] = (SndID)0x1d09;
 self->ids[5] = (SndID)0x1d0a;
 self->ids[6] = (SndID)0x1d0b;
 self->ids[7] = (SndID)0x1d0c;
 self->ids[8] = (SndID)0x1d0f;
 self->ids[9] = (SndID)0x1d04;
 self->arr[0].id = (SndID)0x1d07; self->arr[0].unk4 = d->x[0]; self->arr[0].unk8 = d->x[15]; self->arr[0].unkC = d->x[0];
 self->arr[1].id = (SndID)0x1d04; self->arr[1].unk4 = d->x[0]; self->arr[1].unk8 = d->x[18]; self->arr[1].unkC = d->x[0];
 self->arr[2].id = (SndID)0x1d05; self->arr[2].unk4 = d->x[0]; self->arr[2].unk8 = d->x[49]; self->arr[2].unkC = d->x[0];
 self->arr[3].id = (SndID)0x1d05; self->arr[3].unk4 = d->x[0]; self->arr[3].unk8 = d->x[1]; self->arr[3].unkC = d->x[0];
 self->arr[4].id = (SndID)0x1d06; self->arr[4].unk4 = d->x[0]; self->arr[4].unk8 = d->x[50]; self->arr[4].unkC = d->x[0];
 self->arr[5].id = (SndID)0x1d05; self->arr[5].unk4 = d->x[0]; self->arr[5].unk8 = d->x[51]; self->arr[5].unkC = d->x[0];
 self->arr[6].id = (SndID)0x1d06; self->arr[6].unk4 = d->x[0]; self->arr[6].unk8 = d->x[44]; self->arr[6].unkC = d->x[0];
 self->arr[7].id = (SndID)0x1d05; self->arr[7].unk4 = d->x[0]; self->arr[7].unk8 = d->x[1]; self->arr[7].unkC = d->x[0];
 self->arr[8].id = (SndID)0x1d06; self->arr[8].unk4 = d->x[0]; self->arr[8].unk8 = d->x[50]; self->arr[8].unkC = d->x[0];
 self->arr[9].id = (SndID)0x1d05; self->arr[9].unk4 = d->x[0]; self->arr[9].unk8 = d->x[51]; self->arr[9].unkC = d->x[0];
 self->arr[10].id = (SndID)0x1d06; self->arr[10].unk4 = d->x[0]; self->arr[10].unk8 = d->x[26]; self->arr[10].unkC = d->x[0];
 self->arr[11].id = (SndID)0x1d0f; self->arr[11].unk4 = d->x[0]; self->arr[11].unk8 = d->x[52]; self->arr[11].unkC = d->x[0];
 self->arr[12].id = (SndID)0x1d05; self->arr[12].unk4 = d->x[0]; self->arr[12].unk8 = d->x[6]; self->arr[12].unkC = d->x[0];
 self->arr[13].id = (SndID)0x1d06; self->arr[13].unk4 = d->x[0]; self->arr[13].unk8 = d->x[53]; self->arr[13].unkC = d->x[0];
 self->arr[14].id = (SndID)0x1d05; self->arr[14].unk4 = d->x[0]; self->arr[14].unk8 = d->x[54]; self->arr[14].unkC = d->x[0];
 self->arr[15].id = (SndID)0x1d06; self->arr[15].unk4 = d->x[0]; self->arr[15].unk8 = d->x[55]; self->arr[15].unkC = d->x[0];
 self->arr[16].id = (SndID)0x1d05; self->arr[16].unk4 = d->x[0]; self->arr[16].unk8 = d->x[1]; self->arr[16].unkC = d->x[0];
 self->arr[17].id = (SndID)0x1d06; self->arr[17].unk4 = d->x[0]; self->arr[17].unk8 = d->x[18]; self->arr[17].unkC = d->x[0];
 self->arr[18].id = (SndID)0x1d07; self->arr[18].unk4 = d->x[0]; self->arr[18].unk8 = d->x[56]; self->arr[18].unkC = d->x[0];
 self->arr[19].id = (SndID)0x1d08; self->arr[19].unk4 = d->x[0]; self->arr[19].unk8 = d->x[57]; self->arr[19].unkC = d->x[0];
 self->arr[20].id = (SndID)0x1d07; self->arr[20].unk4 = d->x[0]; self->arr[20].unk8 = d->x[58]; self->arr[20].unkC = d->x[0];
 self->arr[21].id = (SndID)0x1d05; self->arr[21].unk4 = d->x[0]; self->arr[21].unk8 = d->x[54]; self->arr[21].unkC = d->x[0];
 self->arr[22].id = (SndID)0x1d06; self->arr[22].unk4 = d->x[0]; self->arr[22].unk8 = d->x[55]; self->arr[22].unkC = d->x[0];
 self->arr[23].id = (SndID)0x1d05; self->arr[23].unk4 = d->x[0]; self->arr[23].unk8 = d->x[1]; self->arr[23].unkC = d->x[0];
 self->arr[24].id = (SndID)0x1d06; self->arr[24].unk4 = d->x[0]; self->arr[24].unk8 = d->x[18]; self->arr[24].unkC = d->x[0];
 self->arr[25].id = (SndID)0x1d0a; self->arr[25].unk4 = d->x[0]; self->arr[25].unk8 = d->x[59]; self->arr[25].unkC = d->x[0];
 self->arr[26].id = (SndID)0x1d09; self->arr[26].unk4 = d->x[0]; self->arr[26].unk8 = d->x[4]; self->arr[26].unkC = d->x[0];
 self->arr[27].id = (SndID)0x1d0b; self->arr[27].unk4 = d->x[0]; self->arr[27].unk8 = d->x[60]; self->arr[27].unkC = d->x[0];
 self->arr[28].id = (SndID)0x1d0a; self->arr[28].unk4 = d->x[0]; self->arr[28].unk8 = d->x[61]; self->arr[28].unkC = d->x[0];
 self->arr[29].id = (SndID)0x1d0c; self->arr[29].unk4 = d->x[0]; self->arr[29].unk8 = d->x[62]; self->arr[29].unkC = d->x[63];
 self->arr[30].id = (SndID)0x1d09; self->arr[30].unk4 = d->x[0]; self->arr[30].unk8 = d->x[64]; self->arr[30].unkC = d->x[0];
 self->arr[31].id = (SndID)0x1d05; self->arr[31].unk4 = d->x[0]; self->arr[31].unk8 = d->x[65]; self->arr[31].unkC = d->x[0];
 self->arr[32].id = (SndID)0x1d06; self->arr[32].unk4 = d->x[0]; self->arr[32].unk8 = d->x[66]; self->arr[32].unkC = d->x[0];
 seq->registId(self->ids, 10);
 seq->registSeq(0, self->arr, 3, (Heaps::HeapType)15);
 seq->registSeq(1, self->arr+3, 4, (Heaps::HeapType)15);
 seq->registSeq(2, self->arr+7, 9, (Heaps::HeapType)15);
 seq->registSeq(3, self->arr+16, 7, (Heaps::HeapType)15);
 seq->registSeq(4, self->arr+23, 10, (Heaps::HeapType)15);
 return self;
}
