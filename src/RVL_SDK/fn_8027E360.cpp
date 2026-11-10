#pragma force_active on

struct Obj {
    void* unk0;
    unsigned short unk4;
    unsigned short unk6;
    void* unk8;
    int unkC;
    unsigned char unk10;
};

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual Obj* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_80486348[];

extern "C" {
void fn_8027E360(void) {
    Obj* temp_r3 = lbl_805A0EB8->alloc(0x4020, 0x16);
    temp_r3->unk4 = 0x4020;
    if (temp_r3 != 0) {
        temp_r3->unk6 = 1;
        temp_r3->unk8 = (char*)temp_r3 + 0x20;
        temp_r3->unkC = 0x4000;
        temp_r3->unk10 = 0;
        temp_r3->unk0 = lbl_80486348;
    }
}
}
