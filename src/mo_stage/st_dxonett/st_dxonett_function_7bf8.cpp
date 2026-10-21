#pragma force_active on

struct Constants {
    float x[3];
};

extern "C" const Constants lbl_78_rodata_E8;
extern "C" void* lbl_78_data_2500[];
extern "C" void* lbl_78_data_2730[];

extern "C" void fn_78_1768(void*, const char*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void registId__Q28StSeUtil5SeSeqFP5SndIDUl(void*, void*, unsigned long);
extern "C" void registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(void*, int, void*, unsigned long, int);

struct Elem {
    unsigned int id;
    float a, b, c;
};

struct Self {
    char pad0[0x3c];
    void* vtbl;
    char pad1[0x15c - 0x40];
    int i15c, i160, i164;
    unsigned char b168, b169, b16a, b16b;
    float f16c;
    char seq[0x1bc - 0x170];
    unsigned int ids[2];
    Elem arr[2];
};

extern "C" Self* fn_78_7BF8(Self* self, const char* name) {
    Constants* data = (Constants*)&lbl_78_rodata_E8;

    fn_78_1768(self, name);
    self->vtbl = lbl_78_data_2500;

    char* seq = self->seq;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 1, seq + 0x2c, 2);
    *(void**)seq = lbl_78_data_2730;

    self->b16b = 5;
    self->f16c = data->x[0];
    self->i15c = 0;
    self->i160 = 0;
    self->i164 = 0;
    self->b168 = 0;
    self->b169 = 0;
    self->b16a = 0;
    self->ids[0] = 0x1dd0;
    self->ids[1] = 0x1dd1;
    self->arr[0].id = 0x1dd0;
    self->arr[0].a = data->x[0];
    self->arr[0].b = data->x[1];
    self->arr[0].c = data->x[0];
    self->arr[1].id = 0x1dd1;
    self->arr[1].a = data->x[0];
    self->arr[1].b = data->x[2];
    self->arr[1].c = data->x[0];

    registId__Q28StSeUtil5SeSeqFP5SndIDUl(seq, self->ids, 2);
    registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(seq, 0, self->arr, 2, 15);

    return self;
}
