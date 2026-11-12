#include <so/model/so_model_module_impl.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern const float lbl_27_rodata_6534;
extern const float lbl_27_rodata_653C;
extern "C" void fn_27_1DA868(void*);
#define DUM(n) virtual void dummy_##n();
class ObjA { public: DUM(a0) DUM(a1) DUM(a2) DUM(a3) virtual int m4(int,void*); };
class ObjT { public: char pad[8]; DUM(t0) DUM(t1) DUM(t2) DUM(t3) DUM(t4) DUM(t5) DUM(t6) DUM(t7) DUM(t8) DUM(t9) DUM(t10) DUM(t11) DUM(t12) DUM(t13) DUM(t14) DUM(t15) DUM(t16) DUM(t17) DUM(t18) DUM(t19) DUM(t20) DUM(t21) DUM(t22) DUM(t23) DUM(t24) DUM(t25) DUM(t26) DUM(t27) DUM(t28) DUM(t29) DUM(t30) DUM(t31) DUM(t32) DUM(t33) DUM(t34) DUM(t35) DUM(t36) DUM(t37) DUM(t38) DUM(t39) DUM(t40) DUM(t41) DUM(t42) DUM(t43) DUM(t44) DUM(t45) DUM(t46) DUM(t47) DUM(t48) DUM(t49) DUM(t50) DUM(t51) DUM(t52) DUM(t53) DUM(t54) DUM(t55) DUM(t56) DUM(t57) DUM(t58) DUM(t59) DUM(t60) DUM(t61) DUM(t62) DUM(t63) DUM(t64) DUM(t65) DUM(t66) DUM(t67) DUM(t68) DUM(t69) DUM(t70) DUM(t71) DUM(t72) DUM(t73) DUM(t74) DUM(t75) DUM(t76) DUM(t77) DUM(t78) DUM(t79) DUM(t80) DUM(t81) DUM(t82) DUM(t83) DUM(t84) DUM(t85) DUM(t86) DUM(t87) DUM(t88) DUM(t89) DUM(t90) DUM(t91) DUM(t92) DUM(t93) DUM(t94) DUM(t95) DUM(t96) DUM(t97) DUM(t98) DUM(t99) DUM(t100) DUM(t101) DUM(t102) DUM(t103) DUM(t104) DUM(t105) DUM(t106) DUM(t107) DUM(t108) DUM(t109) DUM(t110) virtual float m112(); };
class ObjU { public: DUM(u0) DUM(u1) DUM(u2) virtual void m3(int,void*); };
class ObjV { public: DUM(v0) DUM(v1) virtual void m2(void*,float); };
class ObjRBase { public: char pad[0x3c]; };
class ObjR : public ObjRBase { public: DUM(r0) DUM(r1) DUM(r2) DUM(r3) DUM(r4) DUM(r5) DUM(r6) DUM(r7) DUM(r8) DUM(r9) DUM(r10) DUM(r11) DUM(r12) DUM(r13) DUM(r14) DUM(r15) DUM(r16) DUM(r17) DUM(r18) DUM(r19) DUM(r20) DUM(r21) DUM(r22) DUM(r23) DUM(r24) DUM(r25) DUM(r26) DUM(r27) DUM(r28) DUM(r29) DUM(r30) DUM(r31) DUM(r32) DUM(r33) DUM(r34) DUM(r35) DUM(r36) DUM(r37) DUM(r38) DUM(r39) DUM(r40) DUM(r41) DUM(r42) virtual void m43(); };
struct Modules { char pad0[4]; soModelModule* q; char pad1[4]; ObjV* v; ObjT* t; char pad2[0x50]; ObjA* a; char pad3[8]; ObjU* u; };
struct P0 { char pad[0xd8]; Modules* p1; };
struct Self : public ObjR { char pad1[0x20]; P0* p0; };
extern "C" void fn_27_2FFA38(void* self_v,unsigned int arg1,float farg) {
 Self* self=(Self*)self_v;
 Vec3f offset;
 int r=self->p0->p1->a->m4(0x10000007,self->p0->p1);
 offset.m_x=r==3?lbl_27_rodata_653C:lbl_27_rodata_6534;
 offset.m_y=lbl_27_rodata_6534;
 offset.m_z=lbl_27_rodata_6534;
 Vec3f pos=self->p0->p1->q->getNodeGlobalPosition(0,&offset,false,false);
 pos.m_z=self->p0->p1->t->m112();
 self->p0->p1->v->m2(&pos,farg); fn_27_1DA868(self);
 switch(arg1) { case 0:self->p0->p1->u->m3(1,self->p0);break; case 1:self->p0->p1->u->m3(2,self->p0);break; case 2:self->p0->p1->u->m3(3,self->p0);break; case 3:self->p0->p1->u->m3(4,self->p0);break; case 4:self->p0->p1->u->m3(5,self->p0);break; case 5:self->p0->p1->u->m3(6,self->p0);break; case 6:self->p0->p1->u->m3(7,self->p0);break; default:self->p0->p1->u->m3(8,self->p0);break; }
 self->m43();
}
#undef DUM