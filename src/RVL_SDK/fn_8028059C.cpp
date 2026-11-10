#pragma force_active on

struct Obj {
    void* unk0;
    unsigned short unk4;
    unsigned short unk6;
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
extern char lbl_80486400[];

extern "C" {
void fn_8028059C(void) {
    Obj* temp_r3 = lbl_805A0EB8->alloc2(8, 0x16);
    temp_r3->unk4 = 8;
    if (temp_r3 != 0) {
        temp_r3->unk6 = 1;
        temp_r3->unk0 = lbl_80486400;
    }
}
}
