class Vec3f;
#include <st/se_util.h>

#pragma force_active on

extern "C" void fn_57_3980(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
    void*, void*, unsigned long, void*, unsigned long);
extern "C" void __ct__14snd3DGeneratorFv(void*);

extern char lbl_57_data_8F0[];
extern char lbl_57_data_B18[];
extern "C" const float lbl_57_rodata_118[];

struct Elem {
    int id;
    float a, b, c;

    void initFirst(float value) {
        id = 0x1be9;
        a = value;
    }
};

struct Self {
    char p0[0x3c];
    void* vt;
    char p40[0x160 - 0x40];
    unsigned char f160;
    int f164, f168;
    unsigned char f16c;
    float f170;
    int f174, f178, f17c, f180, f184, f188, f18c, f190, f194, f198;
    char seq[0x284 - 0x19c];
    int ids[11];
    Elem elems[19];
    char gen[4];
};

extern "C" Self* fn_57_3B78(Self* self) {
    float* data = (float*)&lbl_57_rodata_118;
    fn_57_3980(self);
    char* seq = self->seq;
    self->vt = lbl_57_data_8F0;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
        seq, seq + 0x20, 2, seq + 0x38, 11);
    *(void**)seq = lbl_57_data_B18;
    __ct__14snd3DGeneratorFv(self->gen);

    self->f160 = 0;
    self->f164 = 0;
    self->f168 = 0;
    self->f16c = 2;
    self->f170 = data[0];
    self->f184 = 0;
    self->f188 = 0;
    self->f174 = 0;
    self->f178 = 0;
    self->f17c = 0;
    self->f180 = 0;
    self->f18c = 0;
    self->f190 = 0;
    self->f194 = 0;
    self->f198 = 0;

    self->ids[0] = 0x1be6;
    self->ids[1] = 0x1beb;
    self->ids[2] = 0x1be8;
    self->ids[3] = 0x1be9;
    self->ids[4] = 0x1bea;
    self->ids[5] = 0x1bf1;
    self->ids[6] = 0x1bf2;
    self->ids[7] = 0x1bf3;
    self->ids[8] = 0x1bf4;
    self->ids[9] = 0x1bf0;
    self->ids[10] = 0x1be7;

    self->elems[0].id = 0x1beb;
    self->elems[0].a = data[0];
    self->elems[0].b = data[0];
    self->elems[0].c = data[0];
    self->elems[1].id = 0x1be8;
    self->elems[1].a = data[0];
    self->elems[1].b = data[1];
    self->elems[1].c = data[0];
    self->elems[2].id = 0x1bf0;
    self->elems[2].a = data[0];
    self->elems[2].b = data[2];
    self->elems[2].c = data[3];
    self->elems[3].id = 0x1be6;
    self->elems[3].a = data[0];
    self->elems[3].b = data[4];
    self->elems[3].c = data[0];
    self->elems[4].id = 0x1be7;
    self->elems[4].a = data[0];
    self->elems[4].b = data[5];
    self->elems[4].c = data[0];
    self->elems[5].id = 0x1be8;
    self->elems[5].a = data[0];
    self->elems[5].b = data[6];
    self->elems[5].c = data[0];
    self->elems[6].initFirst(data[0]);
    self->elems[6].b = data[7];
    self->elems[6].c = data[0];
    self->elems[7].id = 0x1bf1;
    self->elems[7].a = data[0];
    self->elems[7].b = data[8];
    self->elems[7].c = data[0];
    self->elems[8].id = 0x1bea;
    self->elems[8].a = data[0];
    self->elems[8].b = data[9];
    self->elems[8].c = data[0];
    self->elems[9].id = 0x1bf2;
    self->elems[9].a = data[0];
    self->elems[9].b = data[10];
    self->elems[9].c = data[0];
    self->elems[10].id = 0x1be8;
    self->elems[10].a = data[0];
    self->elems[10].b = data[11];
    self->elems[10].c = data[0];
    self->elems[11].id = 0x1be9;
    self->elems[11].a = data[0];
    self->elems[11].b = data[12];
    self->elems[11].c = data[0];
    self->elems[12].id = 0x1bf3;
    self->elems[12].a = data[0];
    self->elems[12].b = data[13];
    self->elems[12].c = data[0];
    self->elems[13].id = 0x1bea;
    self->elems[13].a = data[0];
    self->elems[13].b = data[14];
    self->elems[13].c = data[0];
    self->elems[14].id = 0x1bf4;
    self->elems[14].a = data[0];
    self->elems[14].b = data[15];
    self->elems[14].c = data[0];
    self->elems[15].id = 0x1bf2;
    self->elems[15].a = data[0];
    self->elems[15].b = data[16];
    self->elems[15].c = data[0];
    self->elems[16].id = 0x1bf0;
    self->elems[16].a = data[0];
    self->elems[16].b = data[17];
    self->elems[16].c = data[18];
    self->elems[17].id = 0x1be8;
    self->elems[17].a = data[0];
    self->elems[17].b = data[19];
    self->elems[17].c = data[0];
    self->elems[18].id = 0x1be9;
    self->elems[18].a = data[0];
    self->elems[18].b = data[20];
    self->elems[18].c = data[0];

    ((StSeUtil::SeSeq*)self->seq)->registId((SndID*)self->ids, 11);
    ((StSeUtil::SeSeq*)self->seq)->registSeq(
        0, (StSeUtil::UnkStruct*)self->elems, 16, (Heaps::HeapType)15);
    ((StSeUtil::SeSeq*)self->seq)->registSeq(
        1, (StSeUtil::UnkStruct*)&self->elems[16], 3, (Heaps::HeapType)15);
    ((StSeUtil::SeSeq*)self->seq)->m_sndGenerator = (snd3DGenerator*)self->gen;
    return self;
}
