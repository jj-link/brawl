#pragma force_active on

class Class_8C9C {
public:
    virtual void fn_121_22F8();  // offset 0x8
    virtual void fn_121_12B00();  // offset 0xc
    virtual void fn_121_14684();  // offset 0x10
    virtual void fn_121_14680();  // offset 0x14
    virtual void fn_121_1467C();  // offset 0x18
    virtual void fn_121_14678();  // offset 0x1c
    virtual int fn_121_14670();  // offset 0x20
    virtual void fn_121_146B8();  // offset 0x24
    virtual void fn_121_146B0();  // offset 0x28
    virtual void fn_121_146A8(int, bool);  // offset 0x2c
    virtual void fn_121_146A0();  // offset 0x30
    virtual void fn_121_14698();  // offset 0x34
    virtual void fn_121_14630();  // offset 0x38
    virtual void fn_121_14664();  // offset 0x3c
    virtual void fn_121_14658(int);  // offset 0x40
    virtual void fn_121_14650();  // offset 0x44
    virtual int fn_121_14644();  // offset 0x48
};

extern "C" void fn_121_10D64(void* arg0, int arg1) {
    char* base = reinterpret_cast<char*>(arg0);
    Class_8C9C* obj = *reinterpret_cast<Class_8C9C**>(*reinterpret_cast<char**>(base + 0xd8) + 0x3c);
    if (obj->fn_121_14670() != 0) {
        Class_8C9C* st = *reinterpret_cast<Class_8C9C**>(*reinterpret_cast<char**>(base + 0xd8) + 0x70);
        int s = st->fn_121_14644();
        if ((s != 0x116 || arg1 != 0x11a) && (s != 0x116 || arg1 != 0x11b) && (s != 0x11a || arg1 != 0x11b)) {
            obj->fn_121_14658(1);
            obj->fn_121_146A8(0, false);
        }
    }
}
