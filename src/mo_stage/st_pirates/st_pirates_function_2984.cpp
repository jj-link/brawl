#pragma force_active on
#include <types.h>
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_vector.h>
struct grCollision;
struct Sub { char pad[0x6C]; float a; float b; };
struct Stage {
 char pad0[0x9C]; Sub* sub; char pad1[0x310-0xA0]; float f310;
 char pad2[0x320-0x314]; float f320; char pad3[0x330-0x324]; float f330;
 char pad4[0x544-0x334]; float f544; char pad5[0x550-0x548]; float f550;
 char pad6[0x560-0x554]; float f560; char pad7[0x56F-0x564]; unsigned char state; unsigned char f570;
 char pad8[0x5D4-0x571]; Vec3f position; float f5E0;
};
extern "C" {
extern const float lbl_52_rodata_0[];
float randf__Fv();
int stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(Vec3f*,Vec3f*,Vec3f*,Vec3f*,bool,grCollision*,bool,unsigned char);
void fn_52_2984(Stage* self,float delta) {
 const float* rodata=lbl_52_rodata_0;
 Sub* sub=self->sub;
 if(sub!=0) {
  float t=self->f5E0-delta;
  self->f5E0=t;
  if(t<rodata[0]) self->f5E0=rodata[0];
  switch(self->state) {
  case 0: {
   float scale=rodata[23];
   if(self->f5E0<rodata[30]*scale) self->f570=4;
   else if(self->f5E0<rodata[31]*scale) self->f570=3;
   else self->f570=2;
   Vec3f start,end,hit,normal;
   float diff=self->f550-self->f544;
   float posZ=self->f330;
   float posY=self->f320;
   float posX=self->f310;
   Vec3f pos(posX,posY,posZ);
   float x=-(rodata[32]*diff)+rodata[33]*diff*randf__Fv();
   start.m_x=x;
   if(x>rodata[34]&&x<rodata[35]) start.m_y=rodata[36]; else start.m_y=rodata[37];
   start.m_z=rodata[0];
   end.m_x=rodata[0]; end.m_y=rodata[38]; end.m_z=rodata[0];
   if(stRayCheck__FP5Vec3fP5Vec3fP5Vec3fP5Vec3fbP11grCollisionbUc(&start,&end,&hit,&normal,true,0,false,1)==0||normal.m_y<=rodata[0]) {
    self->position=start;
    self->position.m_y=pos.m_y;
    self->position.m_z=rodata[0];
   } else {
    self->position.m_x=hit.m_x; self->position.m_y=hit.m_y; self->position.m_z=rodata[0];
   }
   if(self->f5E0>=rodata[7]&&self->f5E0<=rodata[12]) self->state=1;
   break;
  }
  case 1: break;
  case 2: {
   float rnd=randf__Fv();
   float b=sub->b;
   float a=sub->a;
   float range=b-a;
   self->state=0;
   self->f560=a+range*rnd;
   break;
  }
  }
 }
}
}