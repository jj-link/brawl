#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(int, int);
    unsigned short size;
    short refs;
};
extern Object_vptr_0* lbl_805A0EB8;
extern char lbl_80486098[];
extern "C" Object_vptr_0* fn_8028138C(Object_vptr_0*, Object_vptr_0*, int);
inline Object_vptr_0* makeSecond(Object_vptr_0* first) {
    Object_vptr_0* second = (Object_vptr_0*)lbl_805A0EB8->slot4(0x1c, 0x18);
    second->size = 0x1c;
    if (second != 0)
        return fn_8028138C(second, first, 0x1000);
    return second;
}
inline Object_vptr_0* makeFirst() {
    Object_vptr_0* first = (Object_vptr_0*)lbl_805A0EB8->slot4(8, 0x18);
    first->size = 8;
    if (first != 0) {
        first->refs = 1;
        *(void**)first = lbl_80486098;
    }
    return first;
}
extern "C" Object_vptr_0* fn_8027BEB4() {
    Object_vptr_0* first = makeFirst();
    Object_vptr_0* second = makeSecond(first);
    if (first->size != 0) {
        if (--first->refs == 0 && first != 0)
            first->slot0(1);
    }
    return second;
}
