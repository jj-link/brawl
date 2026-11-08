#include <mt/mt_vector.h>
#include <revolution/MTX/mtx.h>
#pragma force_active on
extern const float lbl_805A1744;
extern "C" void fn_8003F9A8(const Quaternion*,const Quaternion*,Quaternion*);
inline void conjugate(const Quaternion* a, Quaternion* q) {
 float x,y,z,w;
 x=-a->x; y=-a->y; z=-a->z; w=a->w;
 q->x=x; q->y=y; q->z=z; q->w=w;
}
inline void set(Quaternion* q,float x,float y,float z,float w) { q->x=x;q->y=y;q->z=z;q->w=w; }
inline void copy(Vec3f* q,float x,float y,float z) { q->m_x=x;q->m_y=y;q->m_z=z; }
extern "C" void fn_8003FA14(const Quaternion* a,const Vec3f* b,Vec3f* c) {
 Quaternion neg,v,result;
 conjugate(a,&neg);
 set(&v,b->m_x,b->m_y,b->m_z,lbl_805A1744);
 fn_8003F9A8(a,&v,&result);
 fn_8003F9A8(&result,&neg,&result);
 copy(c,result.x,result.y,result.z);
}