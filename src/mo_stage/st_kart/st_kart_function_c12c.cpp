#pragma force_active on
#include <mt/mt_vector.h>
#include <st/se_util.h>

struct Flags {
    u32 pad;
    u32 flags;
};

struct AnimBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void set(int, int);
};

struct Anim : AnimBase {
    Flags* data;
    u32 state;
};

struct Obj {
    char pad0[0x3c];
    void* vtable;
    char pad40[0x90];
    Anim anim;
    char padDC[0x7c];
    float a158;
    float a15c;
    float a160;
    u32 a164;
    unsigned char a168;
    char pad169[3];
    float a16c;
    void* seqVtable;
    char seqRest[0x1c];
    char pad190[0x1c];
    u32 sndId;
    StSeUtil::UnkStruct us;
};

extern "C" void fn_49_13B0(void*);
extern "C" void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(void*, void*, unsigned long, void*, unsigned long);
extern "C" char lbl_49_data_2580[];
extern "C" char lbl_49_data_27A0[];
extern "C" const float lbl_49_rodata_130[];

extern "C" void* fn_49_C12C(void* self) {
    Obj* p = (Obj*)self;
    const float* const d = lbl_49_rodata_130;
    fn_49_13B0(self);
    void* seq = (char*)p + 0x170;
    p->vtable = lbl_49_data_2580;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(seq, (char*)seq + 0x20, 1, (char*)seq + 0x2c, 1);
    *(void**)seq = lbl_49_data_27A0;
    p->a158 = d[0];
    p->a15c = d[1];
    p->a160 = d[2];
    p->a164 = 0;
    p->a168 = 0;
    p->a16c = d[2];
    Anim* a = &p->anim;
    if (!a) {
        return self;
    }
    a->state = 1;
    a->set(0, 15);
    a->data->flags |= 1;
    p->sndId = 0x1B84;
    p->us.id = (SndID)0x1B84;
    p->us.unk4 = d[2];
    p->us.unk8 = d[2];
    p->us.unkC = d[2];
    StSeUtil::SeSeq* sq = (StSeUtil::SeSeq*)seq;
    sq->registId((SndID*)&p->sndId, 1);
    sq->registSeq(0, &p->us, 1, (Heaps::HeapType)0xF);
    return self;
}
