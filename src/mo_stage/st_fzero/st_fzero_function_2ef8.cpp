#pragma force_active on
#include <gr/gr_yakumono.h>
#include <st/se_util.h>

extern "C" void __ct__10grYakumonoFPCc(grYakumono*, const char*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(StSeUtil::SeSeq*, StSeUtil::UnkStruct2*, unsigned long, StSeUtil::UnkStruct3*, unsigned long);
extern const float lbl_61_rodata_30;
extern unsigned char lbl_61_data_1020[];
extern unsigned char lbl_61_data_B90[];
extern unsigned char lbl_61_data_DB8[];

class Object_vptr_0 {
public:
    virtual void fn_61_BFE0();
    virtual void fn_61_B400();
    virtual void fn_61_B410();
    virtual void slot3();
    virtual void fn_61_A438(int, int);
    void* unk4;
    int unk8;
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void processDefault();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void processPreMapCorrection();
    virtual void slot5();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void slot12();
    virtual void processEffect();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
};
struct Self {
    char pad0[0x3c];
    void* vptr;
    char pad40[0x110];
    unsigned char a150;
    float a154;
    int a158, a15c, a160, a164;
    unsigned char a168, a169;
    float a16c, a170;
    char seq[0x3c];
    SndID id;
    StSeUtil::UnkStruct sound;
};
extern "C" Self* fn_61_2EF8(Self* self, const char* name) {
    __ct__10grYakumonoFPCc((grYakumono*)self, name);
    self->vptr = lbl_61_data_1020;
    self->a150 = 0;
    self->a154 = lbl_61_rodata_30;
    ((Object_vptr_3c*)self)->slot26();
    StSeUtil::SeSeq* seq = (StSeUtil::SeSeq*)self->seq;
    self->vptr = lbl_61_data_B90;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq,
        (StSeUtil::UnkStruct2*)((char*)seq + 0x20), 1,
        (StSeUtil::UnkStruct3*)((char*)seq + 0x2c), 1);
    Object_vptr_0* obj = (Object_vptr_0*)((char*)self + 0xd0);
    self->a158 = 0;
    *(void**)seq = lbl_61_data_DB8;
    self->a15c = 0;
    self->a160 = 0;
    self->a164 = 0;
    self->a168 = 0;
    self->a169 = 3;
    self->a16c = lbl_61_rodata_30;
    self->a170 = lbl_61_rodata_30;
    if (!obj) return self;
    obj->unk8 = 1;
    obj->fn_61_A438(0, 15);
    unsigned int* flags = (unsigned int*)((char*)obj->unk4 + 4);
    *flags |= 1;
    self->id = (SndID)0x1c71;
    self->sound.id = (SndID)0x1c71;
    self->sound.unk4 = lbl_61_rodata_30;
    self->sound.unk8 = lbl_61_rodata_30;
    self->sound.unkC = lbl_61_rodata_30;
    seq->registId(&self->id, 1);
    seq->registSeq(0, &self->sound, 1, (Heaps::HeapType)15);
    return self;
}
