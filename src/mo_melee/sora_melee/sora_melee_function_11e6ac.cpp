#include <types.h>
#pragma force_active on
extern "C" u32 fn_27_1444C4(u32,u32,u32,u32,u32,u32,u32,u32,u32);
extern "C" u32 lbl_27_bss_31F8;
struct Class90D8Entry { u32 f00,f04,f08,f0c; };
class Class_90D8 {
public:
virtual void fn_27_7B274();
virtual Class90D8Entry* fn_27_7AC18(int);
virtual void fn_27_7AC28();
virtual int fn_27_7AB50();
};
struct Manager { u8* slots; s32 slotCount; Class_90D8 arr; };
extern "C" Manager* g_ftSlotManager;
struct Class2Entry { u8 id; u8 pad[3]; u32 state; };
struct M12Arg { u8 id; u8 pad[3]; u32 state; };
class Class2 {
public:
virtual void m0();
virtual Class2Entry* m3(int);
virtual void m2();
virtual int m5();
virtual void m4();
virtual void m6();
virtual void m7();
virtual void m8();
virtual void m9();
virtual void m10();
virtual void m12(M12Arg*);
};
struct Slot { u32 value, flags; u8 padding[0x48]; u16 status; u16 pad52; };
struct Entry {
u32 f00,f04;
Slot slots[4];
u8 f158,f159,f15a,f15b,f15c,f15d,f15e,f15f;
s32 f160;
u32 f164,f168,f16c,f170,f174;
Class2 f178;
};
static inline u32 find90D8_f04(s32 target) {
Manager* manager=g_ftSlotManager;
s32 count=manager->arr.fn_27_7AB50();
for(s32 i=0;i<count;++i) {
Class90D8Entry* entry=manager->arr.fn_27_7AC18(i);
if((s32)entry->f0c==target) return entry->f04;
}
return 0xff;
}
static inline u32 find90D8_f00(s32 target) {
Manager* manager=g_ftSlotManager;
s32 count=manager->arr.fn_27_7AB50();
for(s32 i=0;i<count;++i) {
Class90D8Entry* entry=manager->arr.fn_27_7AC18(i);
if((s32)entry->f0c==target) return entry->f00;
}
return 0xff;
}
static inline s32 findMatchingSlot(Entry* self,u32 arg1) {
u32 slotOffset;
u32 offset;
s32 index=4;
slotOffset=arg1*0x54;
offset=0x1350;
Manager* manager=g_ftSlotManager;
for(;index<manager->slotCount;++index) {
u8* base=manager->slots;
if((base+offset)[0x15d]==0 && self->f160==*(s32*)(base+offset+0x160) &&
(*(u32*)(base+slotOffset+offset+0x0c)&0x140)==0x140) return index;
offset+=0x4d4;
}
return -1;
}
static inline u32 getSlotValue(Entry* self,u32 idx) { return *(u32*)((u8*)self+(s32)(idx*0x54)+8); }
static inline u32 getSlotFlags(Entry* self,u32 idx) { return *(u32*)((u8*)self+idx*0x54+12); }
static inline void setSlotFlags(Entry* self,u32 idx,u32 value) { *(u32*)((u8*)self+12+(s32)(idx*0x54))=value; }
static inline void updateMask(Entry* self,u32 arg1,u32 mask) {
if(self->f15f!=1) {
u32 acc;
acc=getSlotFlags(self,arg1);
mask &= ~acc;
if(mask!=0) {
if((u8)mask&1) {
u32 found=find90D8_f04(self->f170);
acc|=fn_27_1444C4(lbl_27_bss_31F8,getSlotValue(self,arg1),self->f174,self->f174,mask&1,self->f15b,found,self->f16c,0);
}
if((s32)mask&0x12) {
u32 found=find90D8_f00(self->f170);
acc|=fn_27_1444C4(lbl_27_bss_31F8,getSlotValue(self,arg1),self->f174,self->f174,mask&0x12,self->f15b,found,self->f168,0);
}
u32 inRange=0;
if(self->f160>=0x2e && self->f160<=0x31) inRange=1;
u32 flag=((1-inRange)|(inRange-1))>>31;
acc|=fn_27_1444C4(lbl_27_bss_31F8,getSlotValue(self,arg1),self->f174,self->f174,mask&~0x13u,self->f15b,self->f168,self->f168,flag);
self->f04=1;
}
setSlotFlags(self,arg1,acc);
}
}
static inline void addState(Entry* self,u32 arg1,u32 value) {
int count=self->f178.m5();
for(int i=0;i<count;++i) {
if((u32)self->f178.m3(i)->id==arg1 && self->f178.m3(i)->state==value) return;
}
M12Arg item;
*(u32*)&item=0;
item.id=(u8)arg1;
item.state=value;
self->f178.m12(&item);
}
extern "C" void fn_27_11E6AC(Entry* self,u32 arg1) {
u32 inRange=0;
if(self->f160>=0x2e && self->f160<=0x31) inRange=1;
if(inRange==1) {
if(findMatchingSlot(self,arg1)!=-1) return;
}
switch(self->f160) {
case 0x10: case 0x1d: case 0x1f: case 0x21:
updateMask(self,arg1,0xe0u);
addState(self,arg1,0x100u);
return;
default:
Slot* slot=&self->slots[arg1];
if((slot->status&0x20)==0) {
if((slot->status&1)==0) {
updateMask(self,arg1,0xa0u);
}
updateMask(self,arg1,0x40u);
}
if((slot->status&2)==0) { addState(self,arg1,0x100u); }
if((slot->status&1)==0) { addState(self,arg1,0xa0u); }
break;
}
}
