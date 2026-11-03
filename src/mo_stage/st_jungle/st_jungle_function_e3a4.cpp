#pragma force_active on
#pragma push
#pragma opt_propagation off

struct Vec3f {
    float x;
    float y;
    float z;
};

struct DataBlock {
    char name0[12];
    char name1[12];
    char name2[12];
    char padding[8];
};

struct Base {
    char pad[0x3C];
};

class Obj : public Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49(Vec3f*, unsigned long, char (*)[12]);

    char pad40[0x15C - 0x40];
    Vec3f* a;
    Vec3f* b;
};

extern "C" void fn_51_3C88(void*);
extern "C" DataBlock lbl_51_data_4D78;

extern "C" void fn_51_E3A4(Obj* self) {
    DataBlock* base = &lbl_51_data_4D78;
    char (DataBlock::*ptr)[12] = &DataBlock::name0;
    char (*data_ptr)[12] = &(base->*ptr);
    fn_51_3C88(self);
    if (self->a) {
        self->m49(self->a, 0, (char (*)[12])"L5tatakuN");
    }
    if (self->b) {
        self->m49(self->b, 0, (char (*)[12])"L5Hashigo1");
        self->m49(self->b + 1, 0, (char (*)[12])"L5Hashigo2");
    }
}

#pragma pop