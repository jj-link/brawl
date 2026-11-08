#pragma force_active on

class Class_3138 {
public:
    virtual void fn_63_D57C();
    virtual void fn_63_CA44();
    virtual void fn_63_CA54();
    virtual void fn_63_AF3C();
    virtual void fn_63_AB04();
    virtual void fn_63_9B4C();
    virtual float fn_63_CD48();
};

class Class_34E0 {
public:
    virtual void fn_63_EF70();
    virtual void fn_63_E390();
    virtual void fn_63_E3A0();
    virtual void fn_63_B09C();
    virtual void fn_63_AA10();
    virtual void fn_63_9CD8();
    virtual void fn_63_E6CC();
};

class Class_47D8 {
public:
    virtual void fn_63_EF70();
    virtual void fn_63_E390();
    virtual void fn_63_E3A0();
    virtual void fn_63_10B3C();
    virtual void fn_63_AA10();
    virtual void fn_63_10A54();
    virtual void fn_63_E6CC();
};

class Class_4D30 {
public:
    virtual void fn_63_D57C();
    virtual void fn_63_CA44();
    virtual void fn_63_CA54();
    virtual void fn_63_11FB4();
    virtual void fn_63_AB04();
    virtual void fn_63_11ECC();
    virtual void fn_63_CD48();
};

extern const float lbl_63_rodata_80;

struct Inner {
    char pad[0x18];
    Class_3138* obj;
};

struct Owner {
    char pad[0x48];
    Inner** ptr;
};

extern "C" float fn_63_5D78(Owner* owner) {
    Inner* inner = *owner->ptr;
    if (inner == 0) {
        return lbl_63_rodata_80;
    }
    return inner->obj->fn_63_CD48();
}
