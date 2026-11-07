#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(void*);
};
extern "C" void fn_802F3670(void*);
extern "C" void fn_802F377C(char* self) {
    char* p = *(char**)(self + 0x14);
    Object_vptr_0* obj = *(Object_vptr_0**)(*(char**)((*(char**)(p + *(int*)(p + 0x10) + 0x58)) + 0x18) + 8);
    obj->slot9(self);
    fn_802F3670(self);
}