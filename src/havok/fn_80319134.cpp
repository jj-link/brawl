#pragma force_active on
#pragma fp_contract on
#include <nw4r/ut/ut_algorithm.h>
extern float lbl_805A46B8;
extern float lbl_805A46CC;
struct V4 { float x,y,z,w; } __attribute__((aligned(16)));
struct Arr { V4 v[8]; };
struct Obj { char pad0[0x120]; float nx,ny,nz; char pad12c[0x34]; float p0,p1,p2,p3; int value; };
extern "C" {
int fn_8031866C(Obj*,V4*,Arr*,int);
void fn_80324DD8(V4*,V4*,V4*,V4*,V4*);
}
inline void sub(V4& o,const V4& a,const V4& b) {
 o.x=a.x-b.x;o.y=a.y-b.y;o.z=a.z-b.z;o.w=a.w-b.w;
}
inline void cross(float* o,const V4& a,const V4& b) {
 float x=a.y*b.z-a.z*b.y;
 float y=a.z*b.x-a.x*b.z;
 float z=a.x*b.y-a.y*b.x;
 o[0]=x;o[1]=y;o[2]=z;o[3]=lbl_805A46B8;
}
inline float dotOne(const Obj* o, const V4& d) { return o->nz*d.z+(o->nx*d.x+o->ny*d.y); }
inline float dotTwo(const Obj* o, const V4& d) { const float y=o->ny*d.y; const float xy=o->nx*d.x+y; return o->nz*d.z+xy; }
inline float dotThree(const Obj* o, const V4& d) { return o->nx*d.x+o->ny*d.y+o->nz*d.z; }
inline float dotFour(const Obj* o, const V4& d) { return (d.x*o->nx+d.y*o->ny)+d.z*o->nz; }
inline float diffDot(V4& d, const V4& u, const V4& v, const Obj* o) {
 sub(d,u,v); return dotOne(o,d);
}
inline float diffDotSeparate(V4& d, const V4& u, const V4& v, const Obj* o) {
 const float dx=u.x-v.x,dy=u.y-v.y,dz=u.z-v.z,dw=u.w-v.w;
 d.x=dx;d.y=dy;d.z=dz;d.w=dw;
 return o->nz*dz+(o->nx*dx+o->ny*dy);
}
inline void pairDot(const Obj* o, const V4& d1, const V4& d0, float& s1, float& s0) {
 float y1=o->ny*d1.y, y0=o->ny*d0.y;
 float xy1=o->nx*d1.x+y1, xy0=o->nx*d0.x+y0;
 s1=o->nz*d1.z+xy1; s0=o->nz*d0.z+xy0;
}
inline void pairDotStage(const Obj* o, const V4& d1, const V4& d0, float& s1, float& s0) {
 float y1=o->ny*d1.y, y0=o->ny*d0.y;
 s1=o->nz*d1.z+(o->nx*d1.x+y1);
 s0=o->nz*d0.z+(o->nx*d0.x+y0);
}
extern "C" int fn_80319134(Obj* argObj,Arr* argA,Arr* b,int* countA,int* countB,signed char* mode,int value) {
 Arr* a=argA;
 Obj* obj=argObj;
 V4 out1[3],out2[3];
 V4 e0,e1;
 float nrm[4] __attribute__((aligned(16)));
 float d0[4] __attribute__((aligned(16)));
 float d1[4] __attribute__((aligned(16)));
 V4 pt,seg;
 float plane[4] __attribute__((aligned(16)));
 V4 d1b,d0b;
 V4 pt2;
 V4 t0,t1;
 int r;
 if (((unsigned int)(-(int)*mode | (int)*mode)>>31)!=0) {
 sub(e0,b->v[1],b->v[2]);
 sub(e1,b->v[0],b->v[2]);
 cross(nrm,e0,e1);
 d0[0]=a->v[0].x-b->v[0].x;
 d0[1]=a->v[0].y-b->v[0].y;
 d0[2]=a->v[0].z-b->v[0].z;
 d0[3]=a->v[0].w-b->v[0].w;
 d1[0]=a->v[1].x-b->v[0].x;
 d1[1]=a->v[1].y-b->v[0].y;
 d1[2]=a->v[1].z-b->v[0].z;
 d1[3]=a->v[1].w-b->v[0].w;
 float s0=nrm[2]*d0[2]+(nrm[0]*d0[0]+nrm[1]*d0[1]);
 float s1=nrm[2]*d1[2]+(nrm[0]*d1[0]+nrm[1]*d1[1]);
 int f0=(s0<lbl_805A46B8)?8:0;
 int f1=(s1<lbl_805A46B8)?8:0;
 if(f0==f1) goto same;
 {
 V4* output=&pt;
 float t=s0/(s0-s1),u=lbl_805A46CC-t;
 output->x=u*a->v[0].x+t*a->v[1].x;
 output->y=u*a->v[0].y+t*a->v[1].y;
 output->z=u*a->v[0].z+t*a->v[1].z;
 output->w=u*a->v[0].w+t*a->v[1].w;
 if(fn_8031866C(obj,output,b,0)==14) return 1;
 }
 finish:
 seg.x=a->v[1].x-a->v[0].x;seg.y=a->v[1].y-a->v[0].y;
 seg.z=a->v[1].z-a->v[0].z;seg.w=a->v[1].w-a->v[0].w;
 fn_80324DD8(&a->v[0],&seg,&b->v[2],&e0,out1);
 fn_80324DD8(&a->v[0],&seg,&b->v[2],&e1,out2);
 int idx=out1[2].x>out2[2].x;
 b->v[idx]=b->v[2];b->v[idx+4]=b->v[6];
 --*countB;return 2;
 same:
 float abs1=(float)(double)nw4r::ut::Abs(s1);
 float abs0=(float)(double)nw4r::ut::Abs(s0);
 if(abs0>abs1) {
 t0.x=a->v[0].x;t0.y=a->v[0].y;t0.z=a->v[0].z;t0.w=a->v[0].w;
 a->v[0]=a->v[1];a->v[1]=t0;
 t1=a->v[4];
 a->v[4]=a->v[5];a->v[5]=t1;
 }
 if(fn_8031866C(obj,&a->v[0],b,8)!=14) goto finish;
 --*countA;return 0;
 }
 *(V4*)plane=*(V4*)&obj->p0;
 float s1=diffDot(d1b,a->v[1],b->v[0],obj);
 float s0=diffDot(d0b,a->v[0],b->v[0],obj);
 int side=(s0*s1<lbl_805A46B8)?8:0;
 if(side!=0) {
 V4* output=&pt2;
 float t=s0/(s0-s1),u=lbl_805A46CC-t;
 output->x=u*a->v[0].x+t*a->v[1].x;
 output->y=u*a->v[0].y+t*a->v[1].y;
 output->z=u*a->v[0].z+t*a->v[1].z;
 output->w=u*a->v[0].w+t*a->v[1].w;
 if(fn_8031866C(obj,output,b,0)==14)return 1;
 }
 r=fn_8031866C(obj,&a->v[1],b,0);
 if(r==14) {
 --*countA;a->v[0]=a->v[1];a->v[4]=a->v[5];obj->value=value;return 0;
 }
 if(r==6)goto c6;
 if(r==10)goto c10;
 if(r==12)goto c12;
 if(r==8) {
 float dx=obj->p1-plane[1];
 float dy=obj->p2-plane[2];
 if(!(dx*plane[2] > dy*plane[1]))goto c10;
 goto c12;
 }
 if(r==4) {
 float dx=obj->p2-plane[2];
 float dy=obj->p0-plane[0];
 if(!(dx*plane[0] > dy*plane[2]))goto c12;
 goto c6;
 }
 if(r==2) {
 float dx=obj->p0-plane[0];
 float dy=obj->p1-plane[1];
 if((dx*plane[1] > dy*plane[0]))goto c10;
 }
 c6: --*countB;b->v[0]=b->v[2];b->v[4]=b->v[6];return 2;
 c10: --*countB;b->v[1]=b->v[2];b->v[5]=b->v[6];return 2;
 c12: --*countB;return 2;
}
