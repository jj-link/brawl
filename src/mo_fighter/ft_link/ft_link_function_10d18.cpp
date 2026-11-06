#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_93_22F8();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int, bool);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14(int);
    virtual void slot15();
    virtual int slot16();
};

extern "C" void fn_93_10D18(void* arg0, int arg1) {
    char* base = reinterpret_cast<char*>(arg0);
    Object_vptr_0* obj = *reinterpret_cast<Object_vptr_0**>(
        *reinterpret_cast<char**>(base + 0xd8) + 0x3c);
    if (obj->slot6() != 0) {
        Object_vptr_0* st = *reinterpret_cast<Object_vptr_0**>(
            *reinterpret_cast<char**>(base + 0xd8) + 0x70);
        int s = st->slot16();
        if ((s != 0x116 || arg1 != 0x11a) &&
            (s != 0x116 || arg1 != 0x11b) &&
            (s != 0x11a || arg1 != 0x11b)) {
            obj->slot14(1);
            obj->slot9(0, false);
        }
    }
}
