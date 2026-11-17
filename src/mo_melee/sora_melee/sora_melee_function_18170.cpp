#include <types.h>
#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on
#pragma optimize_for_size off
#pragma optimization_level 4
#pragma opt_prolog on

using namespace nw4r::math;

struct Pair {
    int x, y;
};

struct Result {
    int a;
    Pair b;
    int c;
    Pair d;
    int e;
    Pair f, g, h, i, j, k;
};

class Model {
public:
    char pad[8];

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual unsigned int index(unsigned int);
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual unsigned int current();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual float scale();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual Result& slot12(Result&, unsigned int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual float slot22();
};

struct Entry {
    char pad[4];
    Model* model;
    char pad8[4];
    Object_vptr_0* scale;
};

struct Modules {
    char pad[0xd8];
    Entry* entry;
};

struct Object {
    char pad[0x3c];
    Object_vptr_0* lookup;
    char pad40[0x128];
    Modules* modules;

    Object_vptr_0* getP() const {
        return lookup;
    }
};

extern "C" void fn_8019589C(const void*, VEC3*);
extern const float lbl_27_rodata_344;

static inline VEC3 scaled(const VEC3& input, float scale) {
    VEC3 output;
    LocalScale((const Vec*)&input, (Vec*)&output, scale);
    return output;
}

extern "C" VEC3 fn_27_18170(Object value) {
    Object* self = &value;
    if (self->getP()) {
        Model* model = self->modules->entry->model;
        unsigned int index = model->index(model->current());

        if (index != 0xffffffff) {
            Result result;
            Result* src = &self->lookup->slot12(result, index);

            if (src != &result) {
                result = *src;
                src = &result;
            }

            VEC3 pos;
            fn_8019589C(src, &pos);

            float a = self->modules->entry->model->scale();
            float b = self->modules->entry->scale->slot22();

            pos = scaled(scaled(pos, a), b);
            return pos;
        }
    }

    return VEC3(lbl_27_rodata_344,
                lbl_27_rodata_344,
                lbl_27_rodata_344);
}
