#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
extern "C" {
extern void* g_IfMngr;
void fn_800DB944(void*, int, u8, int, u32);
int fn_800DBAA0(void*);
void fn_800DBD3C(void*);
}
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
 virtual void processDefault();
 virtual void fn_27_2408A0();
 virtual void processAnim();
 virtual void processUpdate();
 virtual void processPreMapCorrection();
 virtual void processMapCorrection();
 virtual void processFixPosition();
 virtual void processPreCollision();
 virtual void processCollision();
 virtual void processCatch();
 virtual void processHit();
 virtual void processCamera();
 virtual void processFixCamera();
 virtual void processEffect();
 virtual void processGameProc();
 virtual void processEnd();
 virtual void renderPre();
 virtual void renderOpa();
 virtual void renderXlu();
 virtual void processDebug();
 virtual void renderDebug();
 virtual void init();
 virtual void fn_27_240848();
 virtual void fn_27_2409E8();
 virtual void fn_27_240AA8();
 u32 pad40;
 u8 state;
 u8 pad45;
 u8 enabled;
 u8 flag;
 int oldValue;
 u8 oldByte;
 u8 pad4d[3];
 u32 oldWord;
 int value;
 u8 byte;
 u8 pad59[3];
 u32 word;
};
extern "C" void fn_27_2408A0(gfTask* self) {
 if (self->enabled != 0) {
  switch ((int)self->state) {
  case 0:
   self->state = 1;
   break;
  case 1:
   {
   int value = self->value;
   u8 byte = self->byte;
   u32 word = self->word;
   self->oldValue = value;
   self->oldByte = byte;
   self->oldWord = word;
   fn_800DB944(g_IfMngr, value, byte, 1, word);
   self->state = 2;
   }
   break;
  case 2:
   if (fn_800DBAA0(g_IfMngr) == 0) break;
   self->state = 3;
  case 3:
   if (self->oldValue != self->value || self->oldByte != self->byte || self->oldWord != self->word || self->flag == 1)
    self->state = 5;
   break;
  case 5:
   self->fn_27_240AA8();
   fn_800DBD3C(g_IfMngr);
   if (self->flag == 1) self->state = 6;
   else self->state = 0;
   break;
  }
 }
}