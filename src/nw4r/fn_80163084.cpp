#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;
extern "C" void fn_801EC41C(const MTX34*, MTX34*);
extern "C" void fn_801EC184(const MTX34*, void*);
extern "C" void fn_801ECD70(const MTX34*, const VEC3*, VEC3*);
extern "C" void fn_80162D3C(void*, const VEC3*, int);
extern "C" void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
extern "C" void fn_801ED008(const VEC3*, VEC3*);
extern "C" const float lbl_805A2C5C;
struct Plane { VEC3 n; f32 d; };
struct Frustum { char pad0[0x30]; Plane side[4]; f32 nearZ; f32 farZ; char bounds[0x18]; Plane cap[6]; };
inline void MakePlane(Plane* p, const VEC3& p0, const VEC3& p1, const VEC3& p2) {
    VEC3 a,b,n;
    VEC3Sub(&a,&p1,&p0); VEC3Sub(&b,&p2,&p0);
    fn_801ED0B0(&a,&b,&n); fn_801ED008(&n,&p->n); p->d=-VEC3Dot(&p->n,&p0);
}
extern "C" void fn_80163084(Frustum* self, const MTX34* arg1, f32 x0, f32 x1, f32 x2, f32 x3, f32 zn, f32 zf) {
    VEC3 pts[8]; MTX34 m; VEC3 cam; f32 r;
    fn_801EC41C(arg1, &m); fn_801EC184(arg1, self); r = zf / zn;
    cam.x = lbl_805A2C5C; cam.y = lbl_805A2C5C; cam.z = lbl_805A2C5C;
    pts[0].x=x2; pts[0].y=x0; pts[0].z=-zn;
    pts[1].x=x3; pts[1].y=x0; pts[1].z=-zn;
    pts[2].x=x3; pts[2].y=x1; pts[2].z=-zn;
    pts[3].x=x2; pts[3].y=x1; pts[3].z=-zn;
    pts[4].x=r*x2; pts[4].y=r*x0; pts[4].z=-zf;
    pts[5].x=r*x3; pts[5].y=r*x0; pts[5].z=-zf;
    pts[6].x=r*x3; pts[6].y=r*x1; pts[6].z=-zf;
    pts[7].x=r*x2; pts[7].y=r*x1; pts[7].z=-zf;
    self->nearZ=-zn; self->farZ=-zf;
    MakePlane(&self->side[0],cam,pts[0],pts[3]);
    MakePlane(&self->side[1],cam,pts[2],pts[1]);
    MakePlane(&self->side[2],cam,pts[1],pts[0]);
    MakePlane(&self->side[3],cam,pts[3],pts[2]);
    {
        VEC3* out=pts; VEC3* in=pts; int i;
        for(i=0;i<8;i++){ fn_801ECD70(&m,in,out); out++; in++; }
    }
    fn_801ECD70(&m,&cam,&cam); fn_80162D3C(self->bounds,pts,8);
    MakePlane(&self->cap[0],cam,pts[0],pts[3]);
    MakePlane(&self->cap[1],cam,pts[2],pts[1]);
    MakePlane(&self->cap[2],pts[0],pts[2],pts[1]);
    MakePlane(&self->cap[3],pts[4],pts[6],pts[7]);
    MakePlane(&self->cap[4],cam,pts[1],pts[0]);
    MakePlane(&self->cap[5],cam,pts[3],pts[2]);
}