#include <sr/sr_common.h>
#pragma force_active on
struct Pair { int a, b; };
struct Vec { int x,y,z; };
struct Node {
 Pair links;
 int a,b;
 Vec pos;
 unsigned short c,d;
 unsigned char e,f,g,h,i,j,k,l,m,n,o;
};
struct Self {
 char pad[0x28];
 char list[12];
 void* current;
 char pad38[4];
 void* other;
 char pad40[0x32];
 unsigned char value;
};
extern "C" {
extern void* lbl_27_bss_B8;
void* fn_27_4FAB4(void*);
Node* fn_27_500B8(void*);
unsigned short fn_27_50110(void*, Node*);
void fn_8015BFB4(void*, void*);
void fn_27_381F0(Self* self, Node* node, unsigned int mode) {
 node->k = self->value;
 fn_8015BFB4(self->current, node);
 if (mode == 1) {
  if (!lbl_27_bss_B8) {
   void* p = operator new(0x1508, Heaps::System);
   if (p) p = fn_27_4FAB4(p);
   lbl_27_bss_B8 = p;
  }
  Node* n = fn_27_500B8(lbl_27_bss_B8);
  *n = *node;
  fn_8015BFB4(self->other, n);
 }
 if (self->current != self->list) {
  if (!lbl_27_bss_B8) {
   void* p = operator new(0x1508, Heaps::System);
   if (p) p = fn_27_4FAB4(p);
   lbl_27_bss_B8 = p;
  }
  Node* n = fn_27_500B8(lbl_27_bss_B8);
  *n = *node;
  if (!lbl_27_bss_B8) {
   void* p = operator new(0x1508, Heaps::System);
   if (p) p = fn_27_4FAB4(p);
   lbl_27_bss_B8 = p;
  }
  n->d = fn_27_50110(lbl_27_bss_B8, node);
  fn_8015BFB4(self->list, n);
  if (mode == 1) {
   if (!lbl_27_bss_B8) {
    void* p = operator new(0x1508, Heaps::System);
    if (p) p = fn_27_4FAB4(p);
    lbl_27_bss_B8 = p;
   }
   Node* n2 = fn_27_500B8(lbl_27_bss_B8);
   *n2 = *n;
   fn_8015BFB4((char*)self + 0xc, n2);
  }
 }
}
}