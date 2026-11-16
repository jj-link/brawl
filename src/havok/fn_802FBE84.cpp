#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(unsigned short);
};

extern "C" void* fn_802FBE84(void* unused, unsigned short* arg1, Object_vptr_0* arg2) {
    unsigned short* p = arg1;
    int i = 0;
    do {
        if ((unsigned short)*p != 0xFFFF) {
            arg2->slot4(*p);
            *p = 0xFFFF;
        }
        i++;
        p++;
    } while (i < 3);
    return (char*)arg1 + 0x20;
}