#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern "C" void fn_8019DA5C(void* self, unsigned int mask, int flag);

class Obj {
public:
    virtual void slot0();
    virtual void slot1(unsigned int a, int b, Obj* c);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual int slot14();
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u16* unk14;
    u32 unk18;
    void** unk1C;
};

extern "C" int fn_80199DF8(Obj* self, u32 index, Obj* other) {
    int ret = self->slot14();
    u32 off;
    int flag = 0;
    u32 i = 0;
    off = 0;
    for (; i < self->unk10; i++) {
        if (!(*(u16*)((u8*)other->unk14 + off) & 0x8000)) {
            flag = 1;
            *(u16*)((u8*)self->unk14 + off) = 0;
        }
        off += 2;
    }
    if (flag != 0) {
        fn_8019DA5C(self, 4, 1);
    }
    self->unk1C[index] = (void*)other;
    other->slot1(0x10002, 0, self);
    return ret;
}
