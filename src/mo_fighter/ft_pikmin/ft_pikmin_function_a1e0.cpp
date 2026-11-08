#pragma force_active on

class Object_vptr_0 {
public:
    virtual int slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Object_vptr_0* slot3(int, int, bool);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(Object_vptr_0*);
};

extern "C" void fn_113_A1E0(void* arg0, int arg1) {
    if (arg1 < 4 && arg1 != 0) {
        if (arg1 < 0) {
            return;
        }
    } else {
        return;
    }

    for (int i = 0; i < 3; i++) {
        Object_vptr_0* obj = *(Object_vptr_0**)
            ((char*)*(void**)((char*)*(void**)((char*)arg0 + 0x60) + 0xD8) + 0x84);
        Object_vptr_0* result = obj->slot3(0, 0, false);
        if (result->slot0() == 0) {
            Object_vptr_0* obj2 = *(Object_vptr_0**)
                ((char*)*(void**)((char*)*(void**)((char*)arg0 + 0x60) + 0xD8) + 0x84);
            obj2->slot13(result);
        }
    }
}
