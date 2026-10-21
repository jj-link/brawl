#pragma force_active on
extern "C" void fn_80334160(void);

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;

extern "C" {
void fn_80334B4C(void) {
    void* temp_r3 = lbl_805A0EB8->alloc(0x20, 0x16);
    *(short*)((char*)temp_r3 + 4) = 0x20;
    if (temp_r3 != 0) {
        fn_80334160();
    }
}
}
