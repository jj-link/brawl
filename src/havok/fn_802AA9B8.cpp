#pragma force_active on

struct Obj {
    void* unk0;
    unsigned short unk4;
    unsigned short unk6;
    int unk8;
    unsigned short unkC;
    unsigned short unkE;
    unsigned short unk10;
};

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual Obj* alloc2(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_80486960[];

extern "C" {
void fn_802AA9B8(int a, int b, int c, int arg3) {
    Obj* temp_r3 = lbl_805A0EB8->alloc2(0x14, 0x1D);
    temp_r3->unk4 = 0x14;
    if (temp_r3 != 0) {
        temp_r3->unk6 = 1;
        temp_r3->unk8 = arg3;
        temp_r3->unk0 = lbl_80486960;
        temp_r3->unkC = 0xFFFF;
        temp_r3->unkE = 0xFFFF;
        temp_r3->unk10 = 0xFFFF;
    }
}
}
