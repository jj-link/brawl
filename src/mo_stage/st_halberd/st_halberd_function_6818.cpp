#pragma force_active on

struct Constants {
    float x[11];
};

extern "C" const Constants lbl_57_rodata_1C8;
extern "C" void* lbl_57_data_1250[];
extern "C" void* lbl_57_data_1470[];

extern "C" void fn_57_3980(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" void registId__Q28StSeUtil5SeSeqFP5SndIDUl(void*, void*, unsigned long);
extern "C" void registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(void*, int, void*, unsigned long, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, void*);

struct Elem {
    unsigned int id;
    float a, b, c;
};

struct Self {
    char pad0[0x3c];
    void* vtbl;
    char pad1[0x160 - 0x40];
    unsigned char b160, b161;
    char pad2[2];
    float f164;
    int i168;
    char seq[0x180 - 0x16c];
    void* p180;
    char pad3[0x1e4 - 0x184];
    unsigned int ids[4];
    Elem arr[10];
    Elem arr2[5];
    char gen[0x10];
};

extern "C" Self* fn_57_6818(Self* self) {
    Constants* d = (Constants*)&lbl_57_rodata_1C8;

    fn_57_3980(self);
    self->vtbl = lbl_57_data_1250;

    char* seq = self->seq;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 2, seq + 0x38, 4);
    *(void**)seq = lbl_57_data_1470;
    __ct__14snd3DGeneratorFv(self->gen);

    self->b160 = 0;
    self->b161 = 2;
    self->f164 = d->x[0];
    self->i168 = 0;
    self->ids[0] = 0x1bec;
    self->ids[1] = 0x1bed;
    self->ids[2] = 0x1bee;
    self->ids[3] = 0x1bef;

    self->arr[0].id = 0x1bec; self->arr[0].a = d->x[0]; self->arr[0].b = d->x[1]; self->arr[0].c = d->x[2];
    self->arr[1].id = 0x1bed; self->arr[1].a = d->x[0]; self->arr[1].b = d->x[2]; self->arr[1].c = d->x[0];
    self->arr[2].id = 0x1bee; self->arr[2].a = d->x[0]; self->arr[2].b = d->x[2]; self->arr[2].c = d->x[3];
    self->arr[3].id = 0x1bec; self->arr[3].a = d->x[0]; self->arr[3].b = d->x[4]; self->arr[3].c = d->x[5];
    self->arr[4].id = 0x1bed; self->arr[4].a = d->x[0]; self->arr[4].b = d->x[5]; self->arr[4].c = d->x[0];
    self->arr[5].id = 0x1bec; self->arr[5].a = d->x[0]; self->arr[5].b = d->x[6]; self->arr[5].c = d->x[7];
    self->arr[6].id = 0x1bed; self->arr[6].a = d->x[0]; self->arr[6].b = d->x[7]; self->arr[6].c = d->x[0];
    self->arr[7].id = 0x1bef; self->arr[7].a = d->x[0]; self->arr[7].b = d->x[8]; self->arr[7].c = d->x[0];
    self->arr[8].id = 0x1bec; self->arr[8].a = d->x[0]; self->arr[8].b = d->x[9]; self->arr[8].c = d->x[10];
    self->arr[9].id = 0x1bed; self->arr[9].a = d->x[0]; self->arr[9].b = d->x[10]; self->arr[9].c = d->x[0];

    self->arr2[0].id = 0x1bec; self->arr2[0].a = d->x[0]; self->arr2[0].b = d->x[1]; self->arr2[0].c = d->x[2];
    self->arr2[1].id = 0x1bed; self->arr2[1].a = d->x[0]; self->arr2[1].b = d->x[2]; self->arr2[1].c = d->x[0];
    self->arr2[2].id = 0x1bee; self->arr2[2].a = d->x[0]; self->arr2[2].b = d->x[2]; self->arr2[2].c = d->x[3];
    self->arr2[3].id = 0x1bec; self->arr2[3].a = d->x[0]; self->arr2[3].b = d->x[4]; self->arr2[3].c = d->x[5];
    self->arr2[4].id = 0x1bed; self->arr2[4].a = d->x[0]; self->arr2[4].b = d->x[5]; self->arr2[4].c = d->x[0];

    registId__Q28StSeUtil5SeSeqFP5SndIDUl(seq, self->ids, 4);
    registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(seq, 0, self->arr, 10, 15);
    registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(seq, 1, self->arr2, 5, 15);

    self->p180 = self->gen;
    float v[3];
    v[0] = d->x[0];
    v[1] = d->x[0];
    v[2] = d->x[0];
    setPos__14snd3DGeneratorFP5Vec3f(self->gen, v);
    return self;
}
