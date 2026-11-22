#include <mt/mt_vector.h>
#pragma force_active on
extern "C" {
extern char lbl_27_data_A3028[], lbl_27_data_A2EB0[], lbl_27_data_C938[], lbl_27_data_2C0C0[], lbl_27_data_CBA0[];
extern const float lbl_27_rodata_80C8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_192278(void*, unsigned long);
void fn_27_3C97E8(void*, void*, unsigned int, unsigned int, unsigned int, unsigned int, void*);
void fn_27_3CADD8(void*, void*, unsigned int, void*, void*, int, unsigned int, float, float, float);
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Object_vptr_0* slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual unsigned int slot21(int);
};

struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void* fn_27_7B2EC();
};

class Model : public Class_90D8_base {
public:
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36();
    virtual Vec3f getNodeGlobalPosition(unsigned int, const Vec3f*, bool, bool);
};

struct Pd8 {
    Class_90D8* r;
    Model* model;
    void* p8;
    Object_vptr_0* posture;
    void* p10;
    Object_vptr_0* situation;
    Object_vptr_0* q;
};
struct Inner8 { char pad[0x28]; void* s; };
struct Ctx { char pad0[8]; Inner8* p8; char pad1[0xcc]; Pd8* pd8; };

static inline unsigned int getKind(Ctx* ctx) {
    Object_vptr_0* y = (Object_vptr_0*)__dynamic_cast(ctx->pd8->r->fn_27_7B2EC(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1);
    return y->slot21(0x2c);
}

static inline bool fn_3C8114(void*, void* p1, Ctx* self, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6) {
    Pd8* obj = self->pd8;
    void* r31 = self->p8->s;
    Object_vptr_0* t = obj->q->slot2();
    void* r9 = t->slot2();
    fn_27_3C97E8(p1, r31, p3, p4, p5, p6, r9);
    return true;
}

static inline int fn_3C81A8(void*, Object_vptr_0* obj, Ctx* a, unsigned int node, unsigned int arg5) {
    void* object = __dynamic_cast(obj, 0, lbl_27_data_A2EB0, lbl_27_data_C938, 0);
    obj = (Object_vptr_0*)getKind(a);
    if (a->pd8->situation->slot3() == 2) {
        float z = fn_27_192278(a, 0xfa2);
        Vec3f offset;
        offset.m_y = fn_27_192278(a, 0xfa3);
        offset.m_z = z;
        offset.m_x = lbl_27_rodata_80C8;
        Vec3f pos = a->pd8->model->getNodeGlobalPosition(node, &offset, false, false);
        pos.m_z = lbl_27_rodata_80C8;
        Pd8* p = a->pd8;
        Object_vptr_0* posture = p->posture;
        Object_vptr_0* q = p->q;
        void* s = a->p8->s;
        fn_27_3CADD8(object, s, (unsigned int)obj, q->slot2()->slot2(), &pos, 0, arg5, posture->slot9(), fn_27_192278(a, 0xfa5), fn_27_192278(a, 0xfa4));
    } else {
        float z = fn_27_192278(a, 0xfa0);
        Vec3f offset;
        offset.m_y = fn_27_192278(a, 0xfa1);
        offset.m_z = z;
        offset.m_x = lbl_27_rodata_80C8;
        Vec3f pos = a->pd8->model->getNodeGlobalPosition(node, &offset, false, false);
        pos.m_z = lbl_27_rodata_80C8;
        Pd8* p = a->pd8;
        Object_vptr_0* posture = p->posture;
        Object_vptr_0* q = p->q;
        void* s = a->p8->s;
        fn_27_3CADD8(object, s, (unsigned int)obj, q->slot2()->slot2(), &pos, 0, arg5, posture->slot9(), fn_27_192278(a, 0xfa5), fn_27_192278(a, 0xfa4));
    }
    return 0;
}

extern "C" int fn_27_3C7D14(void* self, Object_vptr_0* obj, Ctx* ctx) {
    switch (obj->slot6()) {
    case 13: {
        void* castObj = __dynamic_cast(obj, 0, lbl_27_data_A3028, lbl_27_data_C938, 0);
        int v = getKind(ctx);
        Pd8* acc = ctx->pd8;
        void* s = ctx->p8->s;
        fn_27_3C97E8(castObj, s, v, v, 1, 1, acc->q->slot2()->slot2());
        return 1;
    }
    case 14: {
        return fn_3C81A8(self, obj, ctx, 0x1b8, 0x01280001);
    }
    default:
        return 0;
    }
}
