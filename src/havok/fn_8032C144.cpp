#pragma force_active on

struct Obj {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual unsigned int slot54();
};

struct Holder {
    unsigned char pad[0x1C];
    Obj* obj;
};

extern "C" int fn_8032C144(Holder* self) {
    int r = 1;
    if (self->obj != 0) {
        if ((signed char)(self->obj->slot54() >> 24) == 0) {
            r = 0;
        }
    }
    return r << 24;
}
