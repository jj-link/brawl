#pragma force_active on
typedef unsigned int u32;
typedef float f32;
extern "C" { extern const f32 lbl_27_rodata_8F8[]; void fn_8003E3BC(void*, f32*, f32*, f32); }
class A { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual u32 v9(int);
};
class C { public:
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual f32 v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
};
struct Pad { char p[8]; };
class Model : public Pad { public:
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(u32, void*, int);
};
struct Q { char p0[4]; Model* m_4; char p1[4]; C* m_c; char p2[0x54-0x10]; A* m_54; };
struct P { char p0[0xd8]; Q* m_d8; };
struct Self { char p0[0x10]; P* m_10; char p1[4]; u32 m_18; };
extern "C" void fn_27_65528(Self* self) {
 const f32* k=lbl_27_rodata_8F8;
 f32 b[3]; f32 a[3]; f32 mtx[12]; f32 t[4]; f32 f31;
 if (self->m_10->m_d8->m_54->v9(0)==1) {
  self->m_10->m_d8->m_4->s40(self->m_18,mtx,0);
  b[0]=k[1]; b[1]=k[1]; b[2]=k[1]; a[0]=k[1]; a[1]=k[1]; a[2]=k[2];
  fn_8003E3BC(mtx,a,b,k[1]);
  f32 y=b[1]; t[2]=b[0]; t[3]=y;
  t[0]=k[2]; t[1]=k[1];
  f31=k[3];
  if (t[0]*b[0]+t[1]*b[1]>=k[4]) f31=t[0];
  if (f31 != self->m_10->m_d8->m_c->v9()) {
   self->m_10->m_d8->m_c->v11(); self->m_10->m_d8->m_c->v19();
  }
 }
}