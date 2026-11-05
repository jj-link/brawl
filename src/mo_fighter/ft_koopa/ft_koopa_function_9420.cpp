#include <so/so_array.h>
#pragma force_active on

class Class_1178 {
public:
    virtual void fn_102_5380();
    virtual void fn_102_8FD0();
    virtual void fn_102_8F7C();
    virtual void fn_102_8F6C();
};

class Class_11C4 {
public:
    virtual void fn_102_61A8();
    virtual void fn_102_1D70();
    virtual void fn_102_903C();
    virtual void fn_102_9034();
};

class Class_1244 {
public:
    virtual void fn_102_61A8();
    virtual void fn_102_1990();
    virtual void fn_102_9074();
    virtual void fn_102_906C();
};

class Class_198C {
public:
    virtual void fn_102_9310();
    virtual void fn_102_93CC();
    virtual void fn_102_954C();
    virtual void fn_102_9318();
};

class Class_5ECC {
public:
    virtual void fn_102_D588();
    virtual void fn_102_CEB4();
    virtual void fn_102_D3B4();
    virtual void fn_102_D21C();
};

class Class_5F44 {
public:
    virtual void fn_102_D5CC();
    virtual void fn_102_C5C8();
    virtual void fn_102_D5C8();
    virtual void fn_102_CBB0();
};

class Class_6024 {
public:
    virtual void fn_102_E020();
    virtual void fn_102_D99C();
    virtual void fn_102_D5C8();
    virtual void fn_102_DCC0();
};

class Class_609C {
public:
    virtual void fn_102_E060();
    virtual void fn_102_D87C();
    virtual void fn_102_D5C8();
    virtual void fn_102_D8F8();
};

class Class_6118 {
public:
    virtual void fn_102_F27C();
    virtual void fn_102_ED20();
    virtual void fn_102_F128();
    virtual void fn_102_EE54();
};

class Class_6194 {
public:
    virtual void fn_102_F2BC();
    virtual void fn_102_EA98();
    virtual void fn_102_EBA4();
    virtual void fn_102_D60C();
};

class Class_6210 {
public:
    virtual void fn_102_F2FC();
    virtual void fn_102_E424();
    virtual void fn_102_E920();
    virtual void fn_102_E674();
};

class Class_628C {
public:
    virtual void fn_102_F33C();
    virtual void fn_102_E290();
    virtual void fn_102_E294();
    virtual void fn_102_D60C();
};

class Class_6308 {
public:
    virtual void fn_102_F37C();
    virtual void fn_102_E1EC();
    virtual void fn_102_D5C8();
    virtual void fn_102_D60C();
};

class Class_7800 {
public:
    virtual void fn_102_15628();
    virtual void fn_102_1500C();
    virtual void fn_102_15624();
    virtual void fn_102_150D8();
};

class Class_7878 {
public:
    virtual void fn_102_168B0();
    virtual void fn_102_16294();
    virtual void fn_102_16710();
    virtual void fn_102_165DC();
};

class Class_78F0 {
public:
    virtual void fn_102_168F0();
    virtual void fn_102_15A90();
    virtual void fn_102_D5C8();
    virtual void fn_102_15FF4();
};

class Class_7968 {
public:
    virtual void fn_102_17340();
    virtual void fn_102_16CBC();
    virtual void fn_102_D5C8();
    virtual void fn_102_16FE0();
};

class Class_79E0 {
public:
    virtual void fn_102_17380();
    virtual void fn_102_16B9C();
    virtual void fn_102_D5C8();
    virtual void fn_102_16C18();
};

class Class_7A58 {
public:
    virtual void fn_102_18568();
    virtual void fn_102_1800C();
    virtual void fn_102_18414();
    virtual void fn_102_18140();
};

class Class_7AD8 {
public:
    virtual void fn_102_185A8();
    virtual void fn_102_17D84();
    virtual void fn_102_17E90();
    virtual void fn_102_D60C();
};

class Class_7B54 {
public:
    virtual void fn_102_185E8();
    virtual void fn_102_17710();
    virtual void fn_102_17C0C();
    virtual void fn_102_17960();
};

class Class_7BD0 {
public:
    virtual void fn_102_18628();
    virtual void fn_102_175B0();
    virtual void fn_102_175B4();
    virtual void fn_102_D60C();
};

class Class_7C4C {
public:
    virtual void fn_102_18668();
    virtual void fn_102_1750C();
    virtual void fn_102_D5C8();
    virtual void fn_102_D60C();
};

class Class_81B8 {
public:
    virtual void fn_102_61A8();
    virtual void fn_102_1B234();
    virtual void fn_102_1BE5C();
    virtual void fn_102_1BE58();
};

class Class_833C {
public:
    virtual void fn_102_61A8();
    virtual void fn_102_1AF60();
    virtual void fn_102_1BF88();
    virtual void fn_102_1BF80();
};

struct KoopaArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct KoopaArrayAggregate {
    void* vtable;
    KoopaArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" KoopaArrayTriple fn_102_9420(KoopaArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        KoopaArrayTriple result = { 0, 0, 0 };
        return result;
    }
    u32 c = 0;
    if (index < arrays->c->size()) {
        c = arrays->c->at(index);
    }
    u32 a = 0;
    if (index < arrays->a->size()) {
        a = arrays->a->at(index);
    }
    u32 b = 0;
    if (index < arrays->b->size()) {
        b = arrays->b->at(index);
    }
    KoopaArrayTriple result = { c, a, b };
    return result;
}
