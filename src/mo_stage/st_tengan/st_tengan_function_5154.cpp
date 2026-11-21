#include <gr/gr_tengan_event.h>
#include <gr/gr_madein.h>
#include <st/stage.h>
#include <ec/ec_mgr.h>
#include <mt/mt_prng.h>
#pragma force_active on
struct Params { char pad[0xcc]; float a,b,c,d,e,f,g; };
struct Tengan {
 char pad0[0x9c]; Params* params; char padA0[0x178]; int previous; char pad21c[0xac];
 grTenganEvent event2c8; char pad374[0xac]; grTenganEvent event420, event4cc, event578;
 char pad624[0xac]; grTenganEvent event6d0, event77c; char pad828[0xac];
 grTenganEvent event8d4, event980, eventa2c; char padad8[0x37c]; unsigned char flag;
 char pade55[0x13]; unsigned char flags[3]; unsigned char count; char pade6c[0x3c]; unsigned char flag2;
 char padea9[0x3f]; int sound; float time;
};
extern "C" float lbl_60_rodata_38;
extern "C" const float lbl_60_rodata_40;
extern "C" char lbl_60_data_488[];
extern "C" void fn_60_5154(Tengan* self) {
 unsigned int started;
 Params* p = self->params;
 if(p) {
  float scale=lbl_60_rodata_38;
  unsigned int index=0;
  int random=randi((int)(p->a*scale+p->b*scale+p->c*scale+p->d*scale+p->e*scale+p->f*scale+p->g*scale)+1);
  int sum=0; unsigned int done=0;
  do {
   switch(index) {
    case 0: sum+=(int)(p->a*scale); break;
    case 1: sum+=(int)(p->b*scale); break;
    case 2: sum+=(int)(scale*(p->c+p->d)); break;
    case 3: sum+=(int)(p->e*scale); break;
    case 4: sum+=(int)(p->f*scale); break;
    case 5: sum+=(int)(p->g*scale); break;
    case 6: sum=random; break;
   }
   if(sum>=random) done=1;
   if(sum<random) index++;
  } while(done!=1);
  started=0;
  if(self->previous!=(int)index) {
   switch(index) {
    case 0: default: started=self->event578.start(); break;
    case 1:
     if(!self->event77c.isEvent()) {
      unsigned int active = self->event6d0.isEvent();
      if(!active) {
       self->count = 0;
       for (int k = 0; k < 3; k++) {
        if (self->flags[k] == 1) self->count++;
       }
       if((int)self->count!=3) {
        started=self->event4cc.start();
        if(started==1) self->event6d0.start();
        else self->event4cc.end();
       }
      }
     }
     break;
    case 2:
     started=self->event4cc.start();
     if(started==1) {
      started=self->event420.start();
      if(!started) self->event4cc.end();
      else self->flag2=1;
     }
     break;
    case 3: started=self->eventa2c.start(); break;
    case 4: started=self->event8d4.start(); break;
    case 5: started=self->event980.start(); break;
    case 6: started=0; break;
   }
  }
  if(started==1) {
   self->previous=index;
   self->flag=1;
   ((grMadein*)((Stage*)self)->getGround(0x12))->setMotion(1);
   ((grMadein*)((Stage*)self)->getGround(0x12))->startEntity();
   self->event2c8.end(); self->event2c8.start();
   self->sound=0x1c54; self->time=lbl_60_rodata_40;
   unsigned int effect=g_ecMgr->setEffect((EfID)0x0104004c);
   g_ecMgr->setParent(effect, ((Stage*)self)->getGround(0x12)->m_sceneModels[0], lbl_60_data_488, false);
  }
 }
}
