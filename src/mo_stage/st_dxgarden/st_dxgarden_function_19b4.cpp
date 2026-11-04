#pragma force_active on

extern "C" void fn_77_EF0(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" void registId__Q28StSeUtil5SeSeqFP5SndIDUl(void*, void*, unsigned long);
extern "C" void registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(void*, int, void*, unsigned long, int);
extern char lbl_77_data_1068[];
extern char lbl_77_data_1290[];

struct Constants { float f[5]; };
extern "C" const Constants lbl_77_rodata_48;

struct Inner { int pad; unsigned int flags; };
struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int, int);
    Inner* inner;
    int field8;
};

extern "C" char* fn_77_19B4(char* self) {
    Constants* d = (Constants*)&lbl_77_rodata_48;
    fn_77_EF0(self);
    char* seq = self + 0x17c;
    *(void**)(self + 0x3c) = lbl_77_data_1068;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 1, seq + 0x2c, 2);
    *(void**)seq = lbl_77_data_1290;
    __ct__14snd3DGeneratorFv(self + 0x210);

    *(char*)(self + 0x158) = 1;
    *(float*)(self + 0x15c) = d->f[0];
    *(float*)(self + 0x160) = d->f[0];
    *(float*)(self + 0x164) = d->f[0];
    *(float*)(self + 0x168) = d->f[0];
    *(float*)(self + 0x16c) = d->f[0];
    *(int*)(self + 0x170) = 0;
    *(char*)(self + 0x174) = 0;
    *(char*)(self + 0x175) = 0;
    *(char*)(self + 0x176) = 0;
    *(int*)(self + 0x178) = 0;

    Sub* sub = (Sub*)(self + 0xD0);
    if (!sub) return self;
    sub->field8 = 1;
    sub->v4(0, 15);
    sub->inner->flags |= 0x10;

    *(int*)(self + 0x1c8) = 0x1da4;
    *(int*)(self + 0x1cc) = 0x1da5;
    *(int*)(self + 0x1d0) = 0x1da4;
    *(float*)(self + 0x1d4) = d->f[0];
    *(float*)(self + 0x1d8) = d->f[1];
    *(float*)(self + 0x1dc) = d->f[0];
    *(int*)(self + 0x1e0) = 0x1da5;
    *(float*)(self + 0x1e4) = d->f[0];
    *(float*)(self + 0x1e8) = d->f[2];
    *(float*)(self + 0x1ec) = d->f[0];
    *(int*)(self + 0x1f0) = 0x1da4;
    *(float*)(self + 0x1f4) = d->f[0];
    *(float*)(self + 0x1f8) = d->f[3];
    *(float*)(self + 0x1fc) = d->f[0];
    *(int*)(self + 0x200) = 0x1da5;
    *(float*)(self + 0x204) = d->f[0];
    *(float*)(self + 0x208) = d->f[4];
    *(float*)(self + 0x20c) = d->f[0];

    registId__Q28StSeUtil5SeSeqFP5SndIDUl(self + 0x17c, self + 0x1c8, 2);
    registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(self + 0x17c, 0, self + 0x1d0, 4, 15);
    *(void**)(self + 0x190) = self + 0x210;
    return self;
}