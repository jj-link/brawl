#pragma force_active on
extern "C" void __ct__10grYakumonoFPCc(void*, const char*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" void registId__Q28StSeUtil5SeSeqFP5SndIDUl(void*, void*, unsigned long);
extern "C" void registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(void*, int, void*, unsigned long, int);
extern "C" const float lbl_51_rodata_48;
extern "C" unsigned char lbl_51_data_C40[];
extern "C" unsigned char lbl_51_data_9C8[];
extern "C" unsigned char lbl_51_data_BE8[];

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void slot2();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void loadGroundData(void* a, unsigned long b, int c);
    virtual void bindData(void* a);
    virtual void setupMelee();
};

class Class_1FA8 {
public:
    virtual void fn_51_8C18();
    virtual void fn_51_80E0();
    virtual void fn_51_80F0();
    virtual void fn_51_65D8();
    virtual void fn_51_6220(int a, int b);
    void* unk4;
    int unk8;
};

struct Self {
    char pad0[0x3c];
    void* unk3c;
    char pad40[0x150 - 0x40];
    unsigned char unk150;
    char pad151[3];
    float unk154;
    int unk158;
    unsigned char unk15c;
    char pad15d[3];
    float unk160;
    char seq[0x1a0 - 0x164];
    int unk1a0;
    int unk1a4;
    float unk1a8;
    float unk1ac;
    float unk1b0;
};

extern "C" Self* fn_51_29A0(Self* self, const char* name) {
    __ct__10grYakumonoFPCc(self, name);
    self->unk3c = lbl_51_data_C40;
    self->unk150 = 0;
    self->unk154 = lbl_51_rodata_48;
    ((Ground*)self)->setupMelee();
    char* seq = self->seq;
    self->unk3c = lbl_51_data_9C8;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, seq + 0x20, 1, seq + 0x2c, 1);
    Class_1FA8* obj = (Class_1FA8*)((char*)self + 0xd0);
    self->unk158 = 0;
    *(void**)seq = lbl_51_data_BE8;
    self->unk15c = 1;
    self->unk160 = lbl_51_rodata_48;
    if (obj == 0) {
        return self;
    }
    obj->unk8 = 1;
    obj->fn_51_6220(0, 0xf);
    unsigned int* flags = (unsigned int*)((char*)obj->unk4 + 4);
    *flags |= 1;
    self->unk1a0 = 0x1eee;
    self->unk1a4 = 0x1eee;
    self->unk1a8 = lbl_51_rodata_48;
    self->unk1ac = lbl_51_rodata_48;
    self->unk1b0 = lbl_51_rodata_48;
    registId__Q28StSeUtil5SeSeqFP5SndIDUl(seq, &self->unk1a0, 1);
    registSeq__Q28StSeUtil5SeSeqFiPQ28StSeUtil9UnkStructUlQ25Heaps8HeapType(seq, 0, &self->unk1a4, 1, 0xf);
    return self;
}
