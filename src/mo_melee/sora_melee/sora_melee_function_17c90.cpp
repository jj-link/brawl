#pragma force_active on
extern "C" float lbl_27_rodata_344;

struct Entry {
    unsigned char pad0[0x14];
    float value;
    unsigned char pad18[0xC];
    unsigned char unused : 2;
    bool disabled : 1;
    unsigned char rest : 5;
};

struct Array {
    virtual void v0();
    virtual Entry& at(int index);
};

struct Object {
    unsigned char pad[0x90];
    Array* entries;
};

extern "C" float fn_27_17C90(Object* self, int index) {
    float result;
    if (self->entries->at(index).disabled == 0)
        result = self->entries->at(index).value;
    else
        result = lbl_27_rodata_344;
    return result;
}
