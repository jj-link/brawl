#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(int, int);
};

extern Object_vptr_0* lbl_805A0EB8;
extern void* lbl_805A0EF0;

inline void* operator new(unsigned long) {
    return lbl_805A0EB8->slot4(1, 0x13);
}

class Empty {
public:
    Empty() {}
};

extern "C" void fn_80281E48() {
    lbl_805A0EF0 = new Empty;
}
