#pragma force_active on
#pragma fp_contract on
#include <types.h>
struct V {
 float x,y,z,w;
 V() {}
 V(const V& o) { x=o.x; y=o.y; z=o.z; w=o.w; }
} __attribute__((aligned(16)));
struct M {
 V a,b,c,d;
 M() {}
 M(V dd,V cc,V bb,V aa) {
 a.x=aa.x; a.y=aa.y; a.z=aa.z; a.w=aa.w;
 b.x=bb.x; b.y=bb.y; b.z=bb.z; b.w=bb.w;
 c.x=cc.x; c.y=cc.y; c.z=cc.z; c.w=cc.w;
 d.x=dd.x; d.y=dd.y; d.z=dd.z; d.w=dd.w;
 }
 M(const M& o) { *this=o; }
 M& operator=(const M& o) {
 a.x=o.a.x; a.y=o.a.y; a.z=o.a.z; a.w=o.a.w;
 b.x=o.b.x; b.y=o.b.y; b.z=o.b.z; b.w=o.b.w;
 c.x=o.c.x; c.y=o.c.y; c.z=o.c.z; c.w=o.c.w;
 d.x=o.d.x; d.y=o.d.y; d.z=o.d.z; d.w=o.d.w;
 return *this;
 }
};
struct Shape { char pad[12]; int count; V points[1]; };
struct Body { Shape* shape; void* pad; M* matrix; };
struct Context { char pad[12]; float data[4]; };
struct Sphere { char pad[8]; float radius; };
struct Entry { const char* name; u32 tick; u32 pad; };
struct Prof { u32 pad; Entry* current; u32 pad2; Entry* end; };
struct Contact { V position; V normal; Body* body; Body* triangle; };
extern Prof lbl_80532448;
extern char lbl_8040FF18[];
extern float lbl_805A3F98;
extern "C" void fn_8032561C(V*,V*,void*,float*);
extern "C" int __cntlzw(unsigned int);
class Class_80486E6C {
public:
 virtual void fn_802BD8D8();
 virtual void fn_80080A64(Contact*);
};
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
};
inline void record(int offset) {
 Prof* timer=&lbl_80532448;
 signed char active=(signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31);
 if ((unsigned int)(-active | active) >> 31) {
 Entry* e=timer->current;
 e->name=lbl_8040FF18+offset;
 register u32 tick;
 asm { mftb tick }
 e->tick=tick;
 timer->current=e+1;
 }
}
inline void transform(const V* in,const M* mat,int count,V* out) {
 M n(mat->d,mat->c,mat->b,mat->a);
 for(int i=0;i<count;++i) {
 int j=i*4;
 const float* src=(const float*)in+j;
 float* dst=(float*)out+j;
 float z=src[2],y=src[1],x=src[0];
 dst[0]=n.d.x+(x*n.a.x+y*n.b.x+z*n.c.x);
 dst[1]=n.d.y+(x*n.a.y+y*n.b.y+z*n.c.y);
 dst[2]=n.d.z+(x*n.a.z+y*n.b.z+z*n.c.z);
 dst[3]=lbl_805A3F98;
 }
}
inline void transformTriangle(const V* in,const M* mat,V* out,const V*& vertex) {
 M n(mat->d,mat->c,mat->b,mat->a);
 for(int remaining=3,i=0;remaining>0;--remaining,++i) {
 int j=i*4;
 vertex=reinterpret_cast<const V*>(reinterpret_cast<const float*>(in)+j);
 float z=vertex->z;
 float y=vertex->y;
 float x=vertex->x;
 float* dst=(float*)out+j;
 dst[0]=n.d.x+(x*n.a.x+y*n.b.x+z*n.c.x);
 dst[1]=n.d.y+(x*n.a.y+y*n.b.y+z*n.c.y);
 dst[2]=n.d.z+(x*n.a.z+y*n.b.z+z*n.c.z);
 dst[3]=lbl_805A3F98;
 }
}
extern "C" void fn_802BDA88(Context* arg,Body* body,Body* triangle,Sphere* sphere,Class_80486E6C* callback) {
 record(0);
 Shape* tri=triangle->shape;
 V first[3];
 V second[8];
 Shape* shape=body->shape;
 V* vertices=tri->points;
 const V* vertex;
 transformTriangle(vertices,triangle->matrix,first,vertex);
 V* points=shape->points;
 int count=shape->count;
 transform(points,body->matrix,count,second);
 Contact pair;
 pair.body=body;
 pair.triangle=triangle;
 for(int i=0;i<count;++i) {
 u32 j=(u32)i*4;
 V* p=(V*)((float*)second+j);
 float triangleRadius;
 float sourceRadius;
 sourceRadius=((float*)points+j)[3];
 triangleRadius=*(float*)((char*)tri+12);
 float radius=sourceRadius+triangleRadius;
 float result[8];
 fn_8032561C(p,first,&arg->data,result);
 if(result[4]<radius+sphere->radius) {
 float triangleExtent=*(float*)((char*)tri+12);
 float scale=-result[4]+triangleExtent;
 float delta=result[4]-radius;
 pair.position.x=scale*result[0]+p->x;
 pair.position.y=scale*result[1]+p->y;
 pair.position.z=scale*result[2]+p->z;
 pair.position.w=scale*result[3]+p->w;
 pair.normal.x=result[0]; pair.normal.y=result[1]; pair.normal.z=result[2]; pair.normal.w=delta;
 callback->fn_80080A64(&pair);
 }
 }
 record(22);
}
