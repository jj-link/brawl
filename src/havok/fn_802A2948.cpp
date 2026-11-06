#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void* p, unsigned int size, int heap);
};

extern Object_vptr_0* lbl_805A0EB8;

extern "C" void* __dt__14Class_802A2948Fv(void* p, int flag) {
    if (p && flag > 0) {
        lbl_805A0EB8->slot5(p, 0x30, 0x1d);
    }
    return p;
}
