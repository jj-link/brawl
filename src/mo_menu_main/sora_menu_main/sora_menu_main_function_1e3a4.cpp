#pragma force_active on
struct MenuMain { char pad0[0x688]; int f688,f68C,f690,f694,f698,f69C,f6A0,f6A4,f6A8,f6AC; };
struct Frame { int value; unsigned int key; char pad[272]; };
extern "C" int fn_2_1E620(void*, void*, void*);
extern "C" int fn_2_1E6E8(void*, void*, int, int);
extern "C" void* fn_2_1E808(void*);
extern "C" unsigned short fn_2_1E838(void*);
extern "C" unsigned short fn_2_1E868(void*);
extern "C" void* fn_2_1E898(void*);
extern "C" unsigned int fn_2_1E8C8(void*);
extern "C" unsigned int fn_2_1E8F8(void*);
extern "C" int fn_2_1E974(void*);
extern "C" int fn_2_1E9A4(void*);
extern "C" int isCharUsable__6muMenuFiii(int);
extern "C" void fn_2_1E3A4(MenuMain* self) {
 Frame frame;
 unsigned int count;
 int i;
 self->f688=35; self->f68C=35; self->f690=35; self->f694=35; self->f698=35;
 self->f69C=35; self->f6A0=35; self->f6A4=35; self->f6A8=35; self->f6AC=35;
 int result=fn_2_1E620(self,&frame,fn_2_1E808);
 if(result>0) {
  self->f688=fn_2_1E6E8(self,&frame,result,1);
  if(self->f688!=35) self->f68C=fn_2_1E6E8(self,&frame,result,2); else self->f68C=35;
  count=0; i=0;
  do { if(isCharUsable__6muMenuFiii(i)) ++count; ++i; } while(i<35);
  if(count>=3) self->f690=fn_2_1E6E8(self,&frame,result,-1);
 }
 int r2=fn_2_1E620(self,&frame,fn_2_1E838); if(r2>0) self->f694=fn_2_1E6E8(self,&frame,r2,1);
 int r3=fn_2_1E620(self,&frame,fn_2_1E868); if(r3>0) self->f698=fn_2_1E6E8(self,&frame,r3,1);
 int r4=fn_2_1E620(self,&frame,fn_2_1E898); if(r4>0) self->f69C=fn_2_1E6E8(self,&frame,r4,1);
 int r5=fn_2_1E620(self,&frame,fn_2_1E8C8); if(r5>0) self->f6A0=fn_2_1E6E8(self,&frame,r5,1);
 int r6=fn_2_1E620(self,&frame,fn_2_1E8F8); if(r6>0) self->f6A4=fn_2_1E6E8(self,&frame,r6,1);
 int r7=fn_2_1E620(self,&frame,fn_2_1E974); if(r7>0) self->f6A8=fn_2_1E6E8(self,&frame,r7,1);
 int r8=fn_2_1E620(self,&frame,fn_2_1E9A4); if(r8>0) self->f6AC=fn_2_1E6E8(self,&frame,r8,1);
}