#pragma force_active on
extern "C" {
extern char lbl_27_data_69C0[];
extern char lbl_27_data_248[];
extern const float lbl_27_rodata_2578;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_137EA4(void*, bool, int, int, int, float);
}

class Mod {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual int getInt(unsigned long);
    virtual void slot5(); virtual void slot6();
    virtual void setF(float);
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual float getFloat(unsigned long);
};
struct D { char pad[8]; Mod* m8; char pad2[0x58]; Mod* m64; };
struct Obj { char pad[8]; void* owner; char pad2[0xcc]; D* d; };

extern "C" void fn_27_18C048(void*, Obj* obj, int kind) {
    void* o;
    float f;
    int v = obj->d->m64->getInt(0x10000023);
    int w = obj->d->m64->getInt(0x10000024);
    if (kind != 0xf2 && kind != 0xf3) {
        if (v == 4) v = 3;
        else if (v == 6) v = 5;
        else v = 0;
    }
    switch (v) {
    case 3:
        o = obj->owner;
        f = obj->d->m64->getFloat(0x1100000a);
        fn_27_137EA4(__dynamic_cast(o, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1), true, w, 3, -1, f);
        break;
    case 5:
        o = obj->owner;
        f = obj->d->m64->getFloat(0x1100000a);
        fn_27_137EA4(__dynamic_cast(o, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1), true, w, 5, -1, f);
        break;
    default:
        o = obj->owner;
        f = obj->d->m64->getFloat(0x1100000a);
        fn_27_137EA4(__dynamic_cast(o, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1), false, 0, v, -1, f);
        break;
    }
    obj->d->m8->setF(lbl_27_rodata_2578);
}
