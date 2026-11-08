#include <types.h>
#pragma force_active on
#pragma fp_contract on
extern "C" int __cntlzw(unsigned int);
struct TimerEntry { char* name; unsigned int time; unsigned int unused; };
struct Timer { unsigned int unused0; TimerEntry* current; unsigned int unused8; TimerEntry* end; unsigned int unused10[2]; };
extern Timer lbl_80532448;
extern char lbl_8040FF90[];
extern float lbl_805A3FE8;
inline void record(int offset) {
 Timer* timer = &lbl_80532448;
 TimerEntry* entry = timer->current;
 if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
 entry->name = lbl_8040FF90 + offset;
 register u32 t;
 asm { mftb t }
 entry->time = t;
 timer->current = entry + 1;
 }
}
struct Vec { float x,y,z,w; };
struct Transform { float m[3][4]; Vec pos; };
struct Shape { char pad[12]; float radius; Vec tri[3]; };
struct Body { Shape* shape; unsigned int key; Transform* transform; };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(Body*, Body*); };
extern "C" void fn_80325184(Vec*, Vec*);
extern "C" void fn_8032561C(Vec*, Vec*, Vec*, Vec*);
extern "C" void fn_802C7D04(Body* a, Body* b, void* unused, Object_vptr_0* callback) {
 record(0);
 Shape* sa = a->shape;
 Shape* sb = b->shape;
 __attribute__((aligned(16))) Vec temp;
 __attribute__((aligned(16))) Vec result[2];
 fn_80325184(sb->tri, &temp);
 Transform* ta = a->transform;
 Transform* tb = b->transform;
 float z;
 float y;
 float x = ta->pos.x - tb->pos.x;
 y = ta->pos.y - tb->pos.y;
 z = ta->pos.z - tb->pos.z;
 __attribute__((aligned(16))) Vec p;
 p.x = z * tb->m[0][2] + (x * tb->m[0][0] + y * tb->m[0][1]);
 p.y = z * tb->m[1][2] + (x * tb->m[1][0] + y * tb->m[1][1]);
 p.z = z * tb->m[2][2] + (x * tb->m[2][0] + y * tb->m[2][1]);
 p.w = lbl_805A3FE8;
 fn_8032561C(&p, sb->tri, &temp, result);
 float rb = sb->radius;
 float ra = sa->radius;
 float radius = ra + rb;
 if (result[1].x < radius) callback->slot1(a,b);
 record(12);
}
