#include <so/model/so_model_module_simple.h>
#include <so/ground/so_ground_module_impl.h>
#include <gf/gf_application.h>
#pragma force_active on

class Stop {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual unsigned isStop();
};
struct Modules { char pad[4]; soModelModule* model; char pad2[8]; soGroundModule* ground; char pad3[0x44]; Stop* stop; };
struct Access { char pad[0xd8]; Modules* modules; };
class Object {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual int mode();
 char pad[0x24]; Access* access;
 float a,b,c,d,e; unsigned node; unsigned char enabled:1, active:1, dynamic:1, flag:1, old:2, triggered:1, other:1;
};
struct Manager { char pad[0xc4]; void* p; };
extern "C" {
 extern const float lbl_27_rodata_E00[];
 extern Manager* lbl_27_bss_5668;
 void fn_8003E6DC(const Matrix*, Vec3f*);
 void fn_27_228AD0(void*, void*, Vec3f*, grCollision*, bool, float, float);
}
extern "C" void fn_27_B6678(Object* self) {
 const float* k = lbl_27_rodata_E00;
 self->triggered = 0;
 if (self->active == 1 && self->enabled == 1 &&
     self->access->modules->stop->isStop() == 1) {
   int mode = self->mode();
   int old = self->old;
   if ((old == -1 || old != mode) &&
       (mode != 0 || (unsigned)(((unsigned char*)g_gfApplication)[0xee] & 1) != 1U)) {
     Matrix mat(true);
     Vec3f pos;
     Vec3f scale;
     self->access->modules->model->getNodeGlobalMtx(self->node, &mat, false);
     float z = mat.m[2][3];
     float y = mat.m[1][3];
     float x = mat.m[0][3];
     pos.m_y = y; pos.m_x = x; pos.m_z = z;
     fn_8003E6DC(&mat, &scale);
     void* mdl = 0;
     float factor = k[4] * (scale.m_x + scale.m_z);
     float radius = k[5];
     switch (mode) {
     case 0:
       mdl = self->access->modules->model->getScnMdl(true);
       self->triggered = 1;
       break;
     case 1:
       if (self->dynamic == 1) {
         radius = self->e * self->access->modules->ground->getWidth(0);
         float min = self->b * factor;
         if (radius < min) radius = min;
         float max = self->c * factor;
         if (radius > max) radius = max;
       } else {
         radius = self->a;
         if (radius < self->b) radius = self->b;
         if (radius > self->c) radius = self->c;
         radius *= factor;
       }
       break;
     }
     float height = self->d * factor;
     if (radius > k[2]) {
       soGroundModule* ground = self->access->modules->ground;
       bool flag = self->flag == 1;
       Vec3f p = pos;
       void* mgr = lbl_27_bss_5668->p;
       grCollision* coll = ground->getGrCollision();
       fn_27_228AD0(mgr, mdl, &p, coll, flag, radius, height);
     }
   }
 }
}