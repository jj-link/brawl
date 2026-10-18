#include <types.h>
#pragma force_active on

class gfArchive;
class gfModelAnimation;
struct Vec3f {
    float x, y, z;
};
namespace nw4 { namespace r3g { namespace d { class ScnMdl; } } }

extern "C" void startup__9grGimmickFP9gfArchiveUlUl(void*, gfArchive*, unsigned long, unsigned long);
extern "C" void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(gfModelAnimation*, nw4::r3g::d::ScnMdl*);
extern "C" void makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(void*, unsigned long, int);
extern "C" void setCalcuCallbackRoot__9grGimmickFUl(void*, unsigned long);
extern "C" void setPos__9grGimmickFP5Vec3f(void*, Vec3f*);
extern "C" void setRot__9grGimmickFP5Vec3f(void*, Vec3f*);

struct Base {
    char pad[0x3c];
};

struct Gimmick : Base {
    virtual void f0(unsigned long) = 0;
    virtual void f1(unsigned long) = 0;
    virtual void f2(unsigned long) = 0;
    virtual void f3(unsigned long) = 0;
    virtual void f4(unsigned long) = 0;
    virtual void f5(unsigned long) = 0;
    virtual void f6(unsigned long) = 0;
    virtual void f7(unsigned long) = 0;
    virtual void f8(unsigned long) = 0;
    virtual void f9(unsigned long) = 0;
    virtual void f10(unsigned long) = 0;
    virtual void f11(unsigned long) = 0;
    virtual void f12(unsigned long) = 0;
    virtual void f13(unsigned long) = 0;
    virtual void f14(unsigned long) = 0;
    virtual void f15(unsigned long) = 0;
    virtual void f16(unsigned long) = 0;
    virtual void f17(unsigned long) = 0;
    virtual void f18(unsigned long) = 0;
    virtual void f19(unsigned long) = 0;
    virtual void f20(unsigned long) = 0;
    virtual void f21(unsigned long) = 0;
    virtual void f22(unsigned long) = 0;
    virtual void f23(unsigned long) = 0;
    virtual void f24(unsigned long) = 0;
    virtual void f25(unsigned long) = 0;
    virtual void f26(unsigned long) = 0;
    virtual void f27(unsigned long) = 0;
    virtual void f28(unsigned long) = 0;
    virtual void f29(unsigned long) = 0;
    virtual void f30(unsigned long) = 0;
    virtual void f31(unsigned long) = 0;
    virtual void f32(unsigned long) = 0;
    virtual void f33(unsigned long) = 0;
    virtual void f34(unsigned long) = 0;
    virtual void f35(unsigned long) = 0;
    virtual void f36(unsigned long) = 0;
    virtual void f37(unsigned long) = 0;
    virtual void f38(unsigned long) = 0;
    virtual void f39(unsigned long) = 0;
    virtual void f40(unsigned long) = 0;
    virtual void f41(unsigned long) = 0;
    virtual void f42(unsigned long) = 0;
    virtual void f43(unsigned long) = 0;
    virtual void f44(unsigned long) = 0;
    virtual void f45(unsigned long) = 0;
    virtual void f46(unsigned long) = 0;
    virtual void f47(unsigned long) = 0;
    virtual void f48(unsigned long) = 0;
    virtual void f49(unsigned long) = 0;
    virtual void f50(unsigned long) = 0;
    virtual void f51(unsigned long) = 0;
    virtual void f52(unsigned long) = 0;
    virtual void f53(unsigned long) = 0;
    virtual void f54(unsigned long) = 0;
    virtual void f55(unsigned long) = 0;
    virtual void f56(unsigned long) = 0;
    virtual void f57(unsigned long) = 0;
    virtual void f58(unsigned long) = 0;
    virtual void f59(unsigned long) = 0;
    virtual void f60(unsigned long) = 0;
    virtual void f61(unsigned long) = 0;
    virtual void f62(unsigned long) = 0;
    virtual void f63(unsigned long) = 0;
    virtual void f64(unsigned long) = 0;
    virtual void f65(unsigned long) = 0;
    virtual void f66(unsigned long) = 0;
    virtual void f67(unsigned long) = 0;
    virtual void f68(unsigned long) = 0;
    virtual void f69(unsigned long) = 0;
    virtual void f70(unsigned long) = 0;
    virtual void f71(unsigned long) = 0;
    virtual void f72(unsigned long) = 0;
    virtual void f73(unsigned long) = 0;
    virtual void f74(unsigned long) = 0;
    virtual void f75(unsigned long) = 0;
    virtual void calcu(unsigned long) = 0;
};

struct X {
    char pad0_3c[0x3c];
    void* m_vtable;
    char pad0_40[4];
    void** m_scnMdl;
    void** m_modelAnim;
    char pad0_4c[0x70];
    Vec3f* m_vec;
    char pad0xc0[0x8c];
    Vec3f* m_pos;
};

extern "C" void fn_40_2DF10(X* self, gfArchive* archive, unsigned long a, unsigned long b) {
    startup__9grGimmickFP9gfArchiveUlUl(self, archive, a, b);
    
    self->m_pos = self->m_vec;
    
    if (self->m_modelAnim) {
        gfModelAnimation* anim = (gfModelAnimation*)*self->m_modelAnim;
        nw4::r3g::d::ScnMdl* mdl = (nw4::r3g::d::ScnMdl*)*self->m_scnMdl;
        unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
    }
    
    makeCalcuCallback__9grGimmickFUlQ25Heaps8HeapType(self, 1, 0xf);
    setCalcuCallbackRoot__9grGimmickFUl(self, 3);
    setPos__9grGimmickFP5Vec3f(self, self->m_pos);
    setRot__9grGimmickFP5Vec3f(self, self->m_pos + 1);
    
    Gimmick* g = (Gimmick*)self;
    g->calcu(0);
}
