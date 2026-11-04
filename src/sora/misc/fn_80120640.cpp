
#pragma force_active on
struct Vec2 { float x,y; };
struct Rect { float a,b,c,d; };
struct Segment { Vec2 a,b; int extra; };
struct Node { char pad[10]; short left,right; unsigned char pad2; unsigned char f0:4, blockLeft:1, blockRight:1, f1:1, active:1; unsigned char m0:1, useLeft:1, useRight:1, m1:5; };
struct Meta { char pad[0x52]; unsigned short flags; };
struct Entry { Node* node; Meta* meta; void* owner; int rest; };
struct Group { char pad[0x1a]; unsigned short count; Entry* entries; };
struct Descriptor { int a,b,c; unsigned char d,e; };
struct Owner {
 char pad[8]; unsigned int skip1 : 24; signed int side : 8; unsigned int skip2 : 8; signed int other : 8; unsigned int skip3 : 16; char pad10[0x24]; Vec2 position; char pad3c[0x18]; signed int flags54 : 8; unsigned int rest54 : 24; int mode; char pad5c[0xf8]; Descriptor desc;
};
struct Candidate { unsigned char active : 8; signed int kind : 8; unsigned int pad : 16; Entry* entry; Vec2 pos; };
class Class_8042B6D0 {
public:
 virtual void fn_8004805C();
 virtual void fn_8004781C();
 virtual void fn_80046A28(Rect*);
 virtual void fn_8004810C();
 virtual void fn_800480DC();
 virtual void fn_801AB1C4();
 virtual void fn_801B269C();
 virtual void fn_801B26E4();
 virtual unsigned long long fn_801AAFDC();
};
struct Context { char pad[0x18]; Owner* owner; Group* group; char pad20[0x29c]; Class_8042B6D0* object; };
struct Rec { Node* node; int b,c; unsigned char d; unsigned char e : 1; unsigned char extra : 7; };
extern "C" {
void fn_80135BA0(Owner*,Rect*);
void fn_80135B94(Owner*,Rect*);
void fn_80041F44(Rect*,Rect*,Rect*);
void fn_80118294(Context*,Rect*);
void fn_80111968(void*,Segment*,Node*,int);
int fn_80113EC0(Entry*,Rec*);
int fn_80113DF8(Entry*,Rec*);
int fn_800418D0(Rect*,Vec2*);
void fn_80120500(Context*,Candidate*,Entry*,int,Vec2*);
int fn_80120BB0(Context*,unsigned long long*,Candidate*);
int fn_80114AAC(Entry*);
int fn_80112DBC(void*,Owner*,int*);
void fn_80133F50(Owner*);
extern void* lbl_805A0360;
}
extern "C" int fn_80120640(Context* self) {
 Candidate second, first;
 Rect r60, r50, r40, r30;
 Segment seg;
 int side; unsigned int count; Entry* entry; int mask; int right; int offset; int result; Group* group; int other; int mode; unsigned int i;
 result = 0;
 fn_80135BA0(self->owner,&r60);
 fn_80135B94(self->owner,&r50);
 fn_80041F44(&r60,&r50,&r40);
 self->object->fn_80046A28(&r60);
 fn_80041F44(&r60,&r40,&r30);
 group = self->group;
 fn_80118294(self,&r30);
 first.active = 0;
 second.active = 0;
 Owner* owner = self->owner;
 count = group->count;
 side = owner->side;
 other = owner->other;
 mode = owner->mode;
 if (count) {
  Rec rec;
  rec.node = 0; rec.b = 0; rec.c = 0; rec.d = 0; rec.e = 0;
  for (i=0, offset=0;i<count;offset += 16, i++) {
   entry = (Entry*)((char*)group->entries + offset);
   Node* node = entry->node;
   if (!(node->active)) continue;
   unsigned short flags = ~entry->meta->flags;
   if (!(flags & 0x6000)) continue;
   mask = 0;
   if (node->useLeft) mask |= 1;
   if (node->useRight) mask |= 2;
   if (!mask) continue;
   if (!(flags & 0x4000)) mask &= ~1;
   if (!(flags & 0x2000)) mask &= ~2;
   if (!mask) continue;
   fn_80111968(entry->owner,&seg,node,0);
   right = (mask >> 1) & 1;
   mask &= 1;
   if (right && fn_80113EC0(entry,&rec)) {
    if ((rec.node->blockRight) || (entry->node->left >= 0 && (rec.node->active))) continue;
   }
   if (mask && fn_80113DF8(entry,&rec)) {
    if ((rec.node->blockLeft) || (entry->node->right >= 0 && (rec.node->active))) continue;
   }
   if (side == 1) {
    if (mode == 0) {
     if (right && fn_800418D0(&r40,&seg.a)) fn_80120500(self,&first,entry,1,&seg.a);
    } else if (mode == 1) {
     if (mask && fn_800418D0(&r40,&seg.b)) fn_80120500(self,&second,entry,0,&seg.b);
    } else if (mode == 2) {
     if (right && fn_800418D0(&r40,&seg.a)) fn_80120500(self,&first,entry,1,&seg.a);
     else if (other != 1 && mask && fn_800418D0(&r40,&seg.b)) fn_80120500(self,&second,entry,0,&seg.b);
    }
   } else if (side == 0) {
    if (mode == 0) {
     if (mask && fn_800418D0(&r40,&seg.b)) fn_80120500(self,&first,entry,0,&seg.b);
    } else if (mode == 1) {
     if (right && fn_800418D0(&r40,&seg.a)) fn_80120500(self,&second,entry,1,&seg.a);
    } else if (mode == 2) {
     if (mask && fn_800418D0(&r40,&seg.b)) fn_80120500(self,&first,entry,0,&seg.b);
     else if (other != 0 && right && fn_800418D0(&r40,&seg.a)) fn_80120500(self,&second,entry,1,&seg.a);
    }
   }
  }
  Candidate* chosen = 0;
  if (first.active) {
   chosen = &first;
   unsigned long long value = self->object->fn_801AAFDC();
   if (!fn_80120BB0(self,&value,chosen)) chosen = 0;
  }
  if (!chosen && second.active) {
   chosen = &second;
   unsigned long long value = self->object->fn_801AAFDC();
   if (!fn_80120BB0(self,&value,chosen)) chosen = 0;
  }
  if (chosen) {
   int value = fn_80114AAC(chosen->entry);
   Owner* target = self->owner;
   target->position.x = chosen->pos.x;
   target->position.y = chosen->pos.y;
   int id = value;
   if (!fn_80112DBC(lbl_805A0360,self->owner,&id)) {
    self->owner->flags54 = chosen->kind;
    self->owner->desc = *(Descriptor*)chosen->entry;
    fn_80133F50(self->owner);
   }
   result = 1;
  }
 }
 return result;
}
