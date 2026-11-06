#pragma force_active on
class Alloc {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* alloc(int size, int align);
};
class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    unsigned short size;
    short refs;
    void* unk8;
    short pad12;
    short unkE;
};
extern Alloc* lbl_805A0EB8;
extern char lbl_80488330[];
extern char lbl_80488348[];
extern "C" void fn_802CC8DC(void*, void*, int);
extern "C" void* fn_802D92B0(void*, int);
extern "C" void* fn_802D7F20(void*, int);
extern "C" void fn_802EB1A0(int arg0, void* arg1) {
    Object_vptr_0* t1 = (Object_vptr_0*)lbl_805A0EB8->alloc(0xC, 0x20);
    t1->size = 0xC;
    Object_vptr_0* p1 = t1;
    if (t1 != 0) {
        p1 = (Object_vptr_0*)fn_802D92B0(t1, arg0);
    }
    Object_vptr_0* t2 = (Object_vptr_0*)lbl_805A0EB8->alloc(0xC, 0x20);
    t2->size = 0xC;
    Object_vptr_0* p2 = t2;
    if (t2 != 0) {
        p2 = (Object_vptr_0*)fn_802D7F20(t2, arg0);
    }
    Object_vptr_0* p3 = (Object_vptr_0*)lbl_805A0EB8->alloc(0x10, 4);
    p3->size = 0x10;
    if (p3 != 0) {
        p3->refs = 1;
        *(void**)p3 = lbl_80488330;
        p3->unkE = 1;
        p3->unk8 = lbl_80488348;
    }
    fn_802CC8DC(arg1, p1, 1);
    fn_802CC8DC(arg1, p2, 2);
    fn_802CC8DC(arg1, p3, 3);
    if (p1->size != 0) {
        if (--p1->refs == 0 && p1 != 0) {
            p1->slot0(1);
        }
    }
    if (p2->size != 0) {
        if (--p2->refs == 0 && p2 != 0) {
            p2->slot0(1);
        }
    }
    if (p3->size != 0) {
        if (--p3->refs == 0 && p3 != 0) {
            p3->slot0(1);
        }
    }
}
