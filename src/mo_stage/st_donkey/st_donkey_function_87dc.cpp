#pragma force_active on
struct Constants {
    float x[18];
};

extern "C" const Constants lbl_50_rodata_100;
extern "C" void* lbl_50_data_2480[];
extern "C" void* lbl_50_data_26B8[];

extern "C" void fn_50_1F78(void*);
extern "C" void __ct__14snd3DGeneratorFv(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void registId__Q28StSeUtil5SeSeqFP5SndIDUl(void*, void*, unsigned long);
extern "C" void registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(void*, int, void*, unsigned long, int);

struct Elem {
    unsigned int id;
    float a;
    float b;
    float c;
};

struct Self {
    char pad0[0x3c];
    void* vtbl;
    char pad1[0x164 - 0x40];
    unsigned char f164;
    int i168;
    float f16c;
    float f170;
    float f174;
    unsigned char b178;
    unsigned char b179;
    unsigned char b17a;
    void* p17c;
    int i180;
    unsigned char b184;
    float f188;
    float f18c;
    char gen[0x198 - 0x190];
    int i198;
    int i19c;
    char seq[0x1b4 - 0x1a0];
    void* p1b4;
    char pad2[0x1dc - 0x1b8];
    unsigned int sndId;
    Elem arr[5];
};

extern "C" Self* fn_50_87DC(Self* self) {
    Constants* data = (Constants*)&lbl_50_rodata_100;

    fn_50_1F78(self);
    self->vtbl = lbl_50_data_2480;
    __ct__14snd3DGeneratorFv(self->gen);

    char* seq = self->seq;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 1, seq + 0x2c, 1);
    *(void**)seq = lbl_50_data_26B8;

    self->f164 = 1;
    self->i168 = 0;
    self->f16c = data->x[0];
    self->f170 = data->x[0];
    self->f174 = data->x[0];
    self->b178 = 0;
    self->b179 = 0;
    self->b17a = 0;
    self->p17c = 0;
    self->b184 = 1;
    self->f188 = data->x[0];
    self->f18c = data->x[0];
    self->i198 = -1;
    self->i19c = -1;
    self->i180 = 0;
    self->sndId = 0x1b87;
    self->arr[0].id = 0x1b87;
    self->arr[0].a = data->x[0];
    self->arr[0].b = data->x[1];
    self->arr[0].c = data->x[0];
    self->arr[1].id = 0x1b87;
    self->arr[1].a = data->x[0];
    self->arr[1].b = data->x[2];
    self->arr[1].c = data->x[0];
    self->arr[2].id = 0x1b87;
    self->arr[2].a = data->x[0];
    self->arr[2].b = data->x[3];
    self->arr[2].c = data->x[0];
    self->arr[3].id = 0x1b87;
    self->arr[3].a = data->x[0];
    self->arr[3].b = data->x[4];
    self->arr[3].c = data->x[0];
    self->arr[4].id = 0x1b87;
    self->arr[4].a = data->x[0];
    self->arr[4].b = data->x[5];
    self->arr[4].c = data->x[0];

    registId__Q28StSeUtil5SeSeqFP5SndIDUl(seq, &self->sndId, 1);
    registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(seq, 0, self->arr, 5, 0xf);

    self->p1b4 = self->gen;
    char* p = (char*)self + 0xd0;
    if (!p) {
        return self;
    }
    *(unsigned int*)(*(char**)(p + 4) + 4) |= 0x10;
    return self;
}
