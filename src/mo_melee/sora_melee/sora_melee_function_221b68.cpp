#pragma force_active on

struct Trigger {
    char pad00[0x1C];
    void* parent;
    char pad20[4];
    Trigger* next;
};

struct RoData33D0 {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
};

struct Stage {
    char pad00[0x20];
    Trigger* list_head;
    char pad24[0x1C];
    int f40;
    char pad44[5];
    unsigned char f49;
    unsigned char f4A;
    unsigned char f4B;
    unsigned char f4C;
    unsigned char f4D;
    unsigned char f4E;
    unsigned char f4F;
    unsigned char f50;
    char pad51[3];
    int f54;
    float f58;
    float f5C;
    float f60;
    float f64;
    float f68;
    float f6C;
    float f70;
    float f74;
    int f78;
    unsigned char f7C;
    unsigned char f7D;
    char pad7E[2];
    int f80;
    int f84;
    int f88;
    char pad8C[4];
    int f90;
    char pad94[4];
    int f98;
    int f9C;
    void* fA0;
    char padA4[0x18];
    int fBC;
    unsigned char fC0;
    unsigned char fC1;
    unsigned char fC2;
    char padC3[1];
    void* fC4;
    float fC8;
    float fCC;
    float fD0;
    float fD4;
    float fD8;
    float fDC;
    float fE0;
    float fE4;
    unsigned char fE8;
    char padE9[3];
    float fEC;
    float fF0;
    float fF4;
    char padF8[0x8C];
    unsigned char f184;
    char pad185[3];
    int f188;
    float f18C;
    float f190;
};

extern "C" {
extern void* g_GameGlobal;
extern void* lbl_27_bss_5780;
extern const RoData33D0 lbl_27_rodata_33D0;
extern const char lbl_27_data_4A158[];
extern float lbl_27_data_547E0;
extern unsigned char lbl_27_data_547E4;

float fn_8004E94C(void*);
int fn_8004E958(void*);
void* fn_27_2283F0(void*, void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_231E28(void*, const char*);
void* fn_27_22A914(void*);
void fn_27_22A9D4(void*, int);

void initializeStage__5StageFv(Stage* self) {
    const RoData33D0* rd = &lbl_27_rodata_33D0;

    self->f40 = 0;
    self->f78 = 0;
    self->f7C = 0;
    self->f7D = 0;
    self->f4D = 0;
    self->f49 = 0;
    self->f4A = 0;
    self->f4B = 0;
    self->f4C = 0;
    self->f4E = 0;
    self->f4F = 0;
    self->f50 = 0;
    self->f54 = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f90 = 0;
    self->fC4 = 0;
    self->f98 = 0;
    self->f9C = 0;
    self->f184 = 0;
    self->f188 = 0;
    self->f18C = rd->unk08;
    self->f190 = rd->unk08;
    self->f58 = rd->unk0C;
    self->f5C = rd->unk10;
    self->f60 = rd->unk10;
    self->f64 = rd->unk0C;
    self->f68 = rd->unk0C;
    self->f6C = rd->unk10;
    self->f70 = rd->unk10;
    self->f74 = rd->unk0C;

    lbl_27_data_547E0 = fn_8004E94C(g_GameGlobal);
    lbl_27_data_547E4 = fn_8004E958(g_GameGlobal);
    Trigger* obj = (Trigger*)fn_27_2283F0((void*)0x10, (void*)0x18);
    self->fC4 = obj;
    obj->parent = self;
    Trigger* node = self->list_head;
    if (node == 0) {
        self->list_head = obj;
    } else {
        while (node->next != 0) {
            node = node->next;
        }
        node->next = obj;
    }

    void* p = __nw__FUlQ25Heaps8HeapType(0x64, 0xF);
    if (p != 0) {
        p = fn_27_231E28(p, lbl_27_data_4A158);
    }
    self->fA0 = p;

    if (lbl_27_bss_5780 == 0) {
        void* q = __nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (q != 0) {
            q = fn_27_22A914(q);
        }
        lbl_27_bss_5780 = q;
    }
    fn_27_22A9D4(lbl_27_bss_5780, 0x10);

    self->fBC = 0;
    self->fC0 = 0;
    self->fC1 = 0;
    self->fC2 = 0;
    self->fC8 = rd->unk08;
    self->fCC = rd->unk08;
    self->fD0 = rd->unk08;
    self->fD4 = rd->unk08;
    self->fD8 = rd->unk08;
    self->fDC = rd->unk08;
    self->fE0 = rd->unk08;
    self->fE4 = rd->unk08;
    self->fE8 = 0;
    self->fEC = rd->unk08;
    self->fF0 = rd->unk08;
    self->fF4 = rd->unk08;
}
}
