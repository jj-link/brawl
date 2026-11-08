#pragma force_active on
extern "C" void fn_802A3A4C(void* p, int arg1);

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_804867F8[];

struct Obj {
    void* vtable;
    unsigned short unk4;
};

extern "C" void* fn_802A3C28(int a, int b, int c, int arg3) {
    Obj* temp_r3 = (Obj*)lbl_805A0EB8->alloc(0x40, 0x1D);
    temp_r3->unk4 = 0x40;
    if (temp_r3 != 0) {
        fn_802A3A4C(temp_r3, arg3);
        temp_r3->vtable = &lbl_804867F8;
    }
    return temp_r3;
}
