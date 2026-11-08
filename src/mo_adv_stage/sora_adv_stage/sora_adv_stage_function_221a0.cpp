#include <gf/gf_archive.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_data.h>
#include <gr/ground.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <st/stage.h>
#include <types.h>
#pragma force_active on
struct GroundListNode { GroundListNode* prev; GroundListNode* next; void* ground; };
struct GroundList { GroundListNode* first; GroundListNode* last; GroundListNode* current; u32 count; };
struct GimmickPrefix { char pad[0x3c]; };
class GimmickDispatch : public GimmickPrefix {
public:
#define SLOT(n) virtual void slot##n()
 SLOT(0); SLOT(1); SLOT(2); SLOT(3); SLOT(4); SLOT(5); SLOT(6); SLOT(7);
 SLOT(8); SLOT(9); SLOT(10); SLOT(11); SLOT(12); SLOT(13); SLOT(14); SLOT(15);
 SLOT(16); SLOT(17); SLOT(18); SLOT(19); SLOT(20); SLOT(21); SLOT(22); SLOT(23);
 SLOT(24); SLOT(25); SLOT(26); SLOT(27); SLOT(28); SLOT(29); SLOT(30); SLOT(31);
 SLOT(32); SLOT(33); SLOT(34); SLOT(35); SLOT(36);
 virtual void startup(gfArchive*, u32, u32);
 SLOT(38); SLOT(39); SLOT(40); SLOT(41); SLOT(42); SLOT(43); SLOT(44); SLOT(45);
 SLOT(46); SLOT(47); SLOT(48); SLOT(49); SLOT(50); SLOT(51); SLOT(52); SLOT(53);
 SLOT(54); SLOT(55); SLOT(56); SLOT(57); SLOT(58); SLOT(59); SLOT(60); SLOT(61);
 SLOT(62); SLOT(63); SLOT(64); SLOT(65); SLOT(66); SLOT(67); SLOT(68); SLOT(69);
 SLOT(70); SLOT(71); SLOT(72); SLOT(73); SLOT(74); SLOT(75); SLOT(76); SLOT(77);
 SLOT(78); SLOT(79);
 virtual void setGimmickData(void*);
#undef SLOT
};
#define STAGE_FIELD(type, offset) (*(type*)((u8*)stage + (offset)))
extern "C" {
extern char lbl_40_data_5CD0[];
extern Stage* lbl_27_bss_5668;
void* fn_40_23690(s16, const char*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __dl__FPv(void*);
}
inline void run(Stage* stage, gfArchive* archive) {
 nw4r::g3d::ResMdl model(*(void**)((u8*)*(void**)STAGE_FIELD(void*,0x44)+0xe8));
 GimmickDispatch* ground;
 u32 index;
 u32 end = model.GetResNodeNumEntries()-1;
 index = 0;
 while (index < end) {
  ground=(GimmickDispatch*)fn_40_23690((s16)((u8*)STAGE_FIELD(void*,0x164))[0x29],lbl_40_data_5CD0);
  *(void**)((u8*)ground+0x1c)=stage;
  GimmickDispatch* current=(GimmickDispatch*)STAGE_FIELD(void*,0x20);
  if (!current) STAGE_FIELD(void*,0x20)=ground;
  else { while (*(GimmickDispatch**)((u8*)current+0x24)) current=*(GimmickDispatch**)((u8*)current+0x24); *(GimmickDispatch**)((u8*)current+0x24)=ground; }
  ground->setGimmickData(STAGE_FIELD(void*,0x164));
  *(u8*)((u8*)ground+0x150)=(u8)(index+1);
  ground->startup(archive,0,0);
  if (((u8*)STAGE_FIELD(void*,0x164))[0x2d]!=0xff) {
   void* collData=__nw__FUlQ25Heaps8HeapType(0x28,15);
   lbl_27_bss_5668->testCollDataInit(archive,(grCollData*)collData,(u32)((u8*)STAGE_FIELD(void*,0x164))[0x2d]);
   grCollision::create(lbl_27_bss_5668,collData,(Ground*)ground,1);
   __dl__FPv(collData);
  }
  if (STAGE_FIELD(GroundListNode*,0x154)==0) {
   GroundListNode* node=(GroundListNode*)__nw__FUlQ25Heaps8HeapType(12,15);
   if (node) { node->prev=0; node->next=0; }
   STAGE_FIELD(GroundListNode*,0x15c)=node;
   STAGE_FIELD(GroundListNode*,0x158)=node;
   STAGE_FIELD(GroundListNode*,0x154)=node;
   node->ground=ground;
  } else {
   GroundListNode* node=(GroundListNode*)__nw__FUlQ25Heaps8HeapType(12,15);
   if (node) { node->prev=0; node->next=0; }
   STAGE_FIELD(GroundListNode*,0x158)->next=node;
   STAGE_FIELD(GroundListNode*,0x158)->next->ground=ground;
   STAGE_FIELD(GroundListNode*,0x158)->next->prev=STAGE_FIELD(GroundListNode*,0x158);
   STAGE_FIELD(GroundListNode*,0x158)=STAGE_FIELD(GroundListNode*,0x158)->next;
  }
  ++STAGE_FIELD(u32,0x160);
  ++index;
 }
}
extern "C" void fn_40_221A0(Stage* stage, gfArchive* archive) { run(stage, archive); }
