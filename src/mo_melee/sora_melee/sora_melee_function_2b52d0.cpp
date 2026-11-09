#include <it/item.h>
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
extern "C" {
extern float lbl_27_rodata_5ED0;
extern float lbl_27_rodata_5ED4;
}
class Module { public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43(nw4r::math::VEC3*, void*);
    virtual void s44();
    virtual void s45(float*, void*, void*);
    virtual void s46(void*, void*);
};
struct Pad8 { int x,y; };
class SubObjA : public Pad8 { public:
virtual void a0();
virtual void a1();
virtual void a2();
virtual void a3();
virtual void a4();
virtual void a5();
virtual void a6();
virtual void a7();
virtual void a8();
virtual void a9();
virtual void a10();
virtual void a11();
virtual void a12();
virtual void a13();
virtual void a14();
virtual void a15();
virtual void a16();
virtual void a17();
virtual void a18();
virtual void a19(int, int);
};
class SubObjB { public:
virtual void b0();
virtual void b1();
virtual void b2();
virtual void b3();
virtual void b4();
virtual void b5();
virtual void b6(int, int);
};
struct SubContext { char pad[0x10]; SubObjA* a; SubObjB* b; };
struct Context { char pad[8]; BaseItem* item; char pad2[0xCC]; SubContext* sub; };
extern "C" void fn_27_2B52D0(Module* self, nw4r::math::VEC2* p1, Vec3f* vector, Context* context, void* p4) {
((unsigned char*)self)[0xDD] |= 0x80;
self->s46(p4, context);
self->s45((float*)p1, p4, context);
BaseItem* item = context->item;
unsigned int owner;
if ((*(unsigned int*)((char*)self + 0x3C) & 0x200) &&
((owner = *(unsigned int*)((char*)item + 0x8C8)), owner == (unsigned int)context->item->getTeamOwnerTaskId())) {
nw4r::math::VEC3 scaled;
LocalScale((const Vec*)vector, (Vec*)&scaled, lbl_27_rodata_5ED0);
self->s43(&scaled, context);
} else { self->s43((nw4r::math::VEC3*)vector, context); }
if (p1->y >= lbl_27_rodata_5ED4) {
context->sub->a->a19(5, 0);
context->sub->b->b6(2, 0);
if (*(unsigned int*)((char*)self + 0x3C) & 0x100) *(unsigned char*)((char*)self + 0x306) = 3;
}
}