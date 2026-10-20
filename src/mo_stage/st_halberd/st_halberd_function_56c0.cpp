#pragma force_active on
extern "C" void fn_57_3980(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" void registId__Q28StSeUtil5SeSeqFP5SndIDUl(void*, void*, unsigned long);
extern "C" void registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(void*, int, void*, unsigned long, int);
extern char lbl_57_data_ED8[];
extern char lbl_57_data_1110[];
extern const float lbl_57_rodata_198;
extern const float lbl_57_rodata_19C;

struct Inner { int pad; unsigned int flags; };
struct Mod {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(int, int);
    Inner* inner;
    int field8;
};

extern "C" char* fn_57_56C0(char* self) {
    fn_57_3980(self);
    char* seq = self + 0x18c;
    *(void**)(self + 0x3c) = lbl_57_data_ED8;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 1, seq + 0x2c, 3);
    *(void**)seq = lbl_57_data_1110;
    __ct__14snd3DGeneratorFv(self + 0x224);
    *(int*)(self + 0x160) = 0;
    *(int*)(self + 0x164) = 0;
    *(int*)(self + 0x168) = 0;
    *(char*)(self + 0x16c) = 1;
    *(float*)(self + 0x170) = lbl_57_rodata_198;
    *(int*)(self + 0x174) = 0;
    *(int*)(self + 0x178) = 0;
    *(int*)(self + 0x17c) = 0;
    *(int*)(self + 0x180) = 0;
    *(int*)(self + 0x184) = 0;
    *(int*)(self + 0x188) = 0;
    Mod* m = (Mod*)(self + 0xd0);
    if (!m) return self;
    m->field8 = 1;
    m->v4(0, 15);
    m->inner->flags |= 8;
    *(int*)(self + 0x1e8) = 0x1be1;
    *(int*)(self + 0x1ec) = 0x1be2;
    *(int*)(self + 0x1f0) = 0x1be3;
    *(int*)(self + 0x1f4) = 0x1be1;
    *(float*)(self + 0x1f8) = lbl_57_rodata_198;
    *(float*)(self + 0x1fc) = lbl_57_rodata_198;
    *(float*)(self + 0x200) = lbl_57_rodata_198;
    *(int*)(self + 0x204) = 0x1be2;
    *(float*)(self + 0x208) = lbl_57_rodata_198;
    *(float*)(self + 0x20c) = lbl_57_rodata_198;
    *(float*)(self + 0x210) = lbl_57_rodata_19C;
    *(int*)(self + 0x214) = 0x1be3;
    *(float*)(self + 0x218) = lbl_57_rodata_198;
    *(float*)(self + 0x21c) = lbl_57_rodata_19C;
    *(float*)(self + 0x220) = lbl_57_rodata_198;
    registId__Q28StSeUtil5SeSeqFP5SndIDUl(self + 0x18c, self + 0x1e8, 3);
    registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(self + 0x18c, 0, self + 0x1f4, 3, 15);
    *(void**)(self + 0x1a0) = self + 0x224;
    return self;
}
