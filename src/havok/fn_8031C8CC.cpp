#pragma force_active on
#pragma fp_contract on
extern const float lbl_805A46F0;
struct V { float x,y,z,w; } __attribute__((aligned(16)));
struct M {
 V a,b,c,d;
 M() {}
 M(const M& o) { *this=o; }
 M& operator=(const M& o) {
 a.x=o.a.x; a.y=o.a.y; a.z=o.a.z; a.w=o.a.w;
 b.x=o.b.x; b.y=o.b.y; b.z=o.b.z; b.w=o.b.w;
 c.x=o.c.x; c.y=o.c.y; c.z=o.c.z; c.w=o.c.w;
 d.x=o.d.x; d.y=o.d.y; d.z=o.d.z; d.w=o.d.w;
 return *this;
 }
};
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(); virtual void slot9(); virtual void slot10(V*, int*);
virtual void slot11(); virtual void slot12(V*); virtual int slot13();
};
struct Out { short a,b,c,d; unsigned char e,f,g,h; };
struct Points { char pad[16]; V v[3]; };
inline void copyMatrix(M* n,const M* mat) {
 V md,mc,mb,ma;
 ma.x=mat->a.x;
 ma.y=mat->a.y;
 ma.z=mat->a.z;
 ma.w=mat->a.w;
 mb.x=mat->b.x;
 mb.y=mat->b.y;
 mb.z=mat->b.z;
 mb.w=mat->b.w;
 mc.x=mat->c.x;
 mc.y=mat->c.y;
 mc.z=mat->c.z;
 mc.w=mat->c.w;
 md.x=mat->d.x;
 md.y=mat->d.y;
 md.z=mat->d.z;
 md.w=mat->d.w;
 n->a.x=ma.x;
 n->a.y=ma.y;
 n->a.z=ma.z;
 n->a.w=ma.w;
 n->b.x=mb.x;
 n->b.y=mb.y;
 n->b.z=mb.z;
 n->b.w=mb.w;
 n->c.x=mc.x;
 n->c.y=mc.y;
 n->c.z=mc.z;
 n->c.w=mc.w;
 n->d.x=md.x;
 n->d.y=md.y;
 n->d.z=md.z;
 n->d.w=md.w;
}
inline void cross(V& normal,const V& a,const V& b) {
 float x=a.y*b.z-a.z*b.y;
 float y=a.z*b.x-a.x*b.z;
 float z=a.x*b.y-a.y*b.x;
 normal.x=x; normal.y=y; normal.z=z; normal.w=lbl_805A46F0;
}
extern "C" void fn_8031C8CC(Out* out, Object_vptr_0* obj, Points* pts, const M* mat) {
 V result[3];
 V a,b,normal,center,diff;
 float* dst;
 const V* input=pts->v;
 out->b=0; out->c=16; out->d=32;
 M n;
 copyMatrix(&n,mat);
 for(int i=0;i<3;i++) {
 int j=i*4;
 dst=(float*)result+j;
 const float* src=(const float*)input+j;
 float x=src[0],z=src[2],y=src[1];
 dst[0]=n.d.x+(x*n.a.x+y*n.b.x+z*n.c.x);
 dst[1]=n.d.y+(x*n.a.y+y*n.b.y+z*n.c.y);
 dst[2]=n.d.z+(x*n.a.z+y*n.b.z+z*n.c.z);
 dst[3]=lbl_805A46F0;
 }
 a.x=result[1].x-result[0].x; a.y=result[1].y-result[0].y;
 a.z=result[1].z-result[0].z; a.w=result[1].w-result[0].w;
 b.x=result[2].x-result[1].x; b.y=result[2].y-result[1].y;
 b.z=result[2].z-result[1].z; b.w=result[2].w-result[1].w;
 cross(normal,a,b);
 obj->slot12(&center);
 diff.x=center.x-result[0].x; diff.y=center.y-result[0].y;
 diff.z=center.z-result[0].z; diff.w=center.w-result[0].w;
 float dot=diff.x*normal.x+diff.y*normal.y+diff.z*normal.z;
 int sign=(dot<lbl_805A46F0)?8:0;
 if(sign) { normal.x=-normal.x; normal.y=-normal.y; normal.z=-normal.z; normal.w=-normal.w; }
 int local[4];
 obj->slot10(&normal,local);
 out->a=(short)local[3]; out->e=1; out->f=3;
 out->g=obj->slot13(); out->h=3;
}
