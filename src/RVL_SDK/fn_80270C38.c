#pragma force_active on
typedef unsigned char u8;
struct Item { char pad[0x14]; int value; };
struct Obj {
 char pad0[0x80]; int count; char pad1[0x25C-0x84];
 void *handles[4]; char pad2[0x2A0-0x26C]; struct Item *items[0x4A];
};
extern u8 fn_8021C4E0(void);
extern void fn_8021C514(int);
extern void fn_80278C34(void *);
extern void fn_8027A83C(void *);
extern void fn_8027A850(void *, float);
extern const float lbl_805A3B18, lbl_805A3B1C, lbl_805A3B20;
extern const int lbl_8040E798[0x25][4];
static inline int findSlot(int id, int flag) {
 const int *e = &lbl_8040E798[0][0];
 int j;
 for (j=0; j<0x4A; j++) {
  if (id == e[0] && e[1] == flag) return j;
  e += 2;
 }
 return -1;
}
void fn_80270C38(struct Obj *obj) {
 struct Obj *p; int k; struct Item *item; int i;
 obj->count=(int)(lbl_805A3B18+lbl_805A3B1C*(float)fn_8021C4E0());
 fn_8021C514(0x7F);
 p=obj;
 for(k=0;k<4;k++) {
  fn_8027A850(*(void **)((char *)p+0x25C),(float)obj->count/lbl_805A3B20);
  fn_8027A83C(*(void **)((char *)p+0x25C));
  p=(struct Obj *)((char *)p+4);
 }
 for(i=0;i<10;i++) {
  if(i<obj->count) {
   item=obj->items[findSlot(i+0x15,10)];
   fn_80278C34(item);
   item->value=1;
  } else {
   item=obj->items[findSlot(i+0x15,9)];
   fn_80278C34(item);
   item->value=1;
  }
 }
}