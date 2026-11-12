#pragma force_active on
class Child {
public:
 virtual void vf8();
 virtual void vf0c(int, void*, int, void*);
 virtual void vf10(int, void*, int, void*);
 virtual void vf14(int, void*, int, void*);
};
class Sub {
public:
 virtual void vf8();
 virtual void vf0c(int, int, void*);
};
class Class_80466418 {
public:
 virtual void fn_801B3BDC();
 virtual int fn_801B35D0(void*, int, int);
 virtual void fn_801B3C80();
 virtual void fn_801B3C74();
 virtual void fn_801B3C44();
 virtual void fn_801AB788();
 virtual void fn_801AAC9C();
 virtual void fn_801AAE34();
 virtual void fn_801AAFDC();
 virtual void fn_801AAFE8();
 virtual void fn_801AAA70(void*, int*);
 char pad04[0xCC - 4];
 unsigned int unkCC;
 char padD0[4];
 Child* unkD4;
 unsigned char unkD8;
 char padD9[1];
 unsigned short unkDA;
 unsigned int* unkDC;
 char padE0[4];
 int unkE4;
 Sub* unkE8;
};
inline Sub** findSub(Sub** p, Sub** end, Sub* const& target) {
 while (p != end && *p != target) ++p;
 return p;
}
extern "C" {
extern int lbl_805A0558;
void fn_801AAB18(void*, void*);
void fn_801ABA14(void*, int, int, void*);
void fn_801B35D0(Class_80466418* self, int arg1, int arg2, Class_80466418* arg3) {
 int sp8 = arg2;
 int var5;
 if ((unsigned int)arg1 < 9U && ((1 << (arg1 - 1)) & self->unkCC))
  var5 = 1;
 else
  var5 = 0;
 if (var5 == 0) {
  switch (arg1) {
  case 1:
   if (self->unkD4 && (self->unkDA & 1) && (self->unkD8 & 1))
    self->unkD4->vf0c(1, self, arg2, arg3);
   self->fn_801AAA70(arg3, &sp8);
   {
    int updated = sp8;
    if (self->unkD4 && (self->unkDA & 1) && (self->unkD8 & 2))
     self->unkD4->vf0c(2, self, updated, arg3);
   }
   if (self->unkE8) {
    Sub** p = (Sub**)self->unkDC;
    Sub** end = p + self->unkE4;
    p = findSub(p, end, self->unkE8);
    if (p == end)
     self->unkE8 = 0;
   }
   if (self->unkE8)
    self->unkE8->vf0c(1, sp8, (char*)self + 0x3c);
   {
    int updated = sp8;
    if (self->unkD4 && (self->unkDA & 1) && (self->unkD8 & 4))
     self->unkD4->vf0c(4, self, updated, arg3);
   }
   break;
  case 2:
   if (self->unkD4 && (self->unkDA & 2) && (self->unkD8 & 1))
    self->unkD4->vf10(1, self, arg2, arg3);
   if (self->unkE8) {
    Sub** p = (Sub**)self->unkDC;
    Sub** end = p + self->unkE4;
    p = findSub(p, end, self->unkE8);
    if (p == end)
     self->unkE8 = 0;
   }
   if (self->unkE8)
    self->unkE8->vf0c(2, sp8, arg3);
   {
    int updated = sp8;
    if (self->unkD4 && (self->unkDA & 2) && (self->unkD8 & 4))
     self->unkD4->vf10(4, self, updated, arg3);
   }
   break;
  case 4:
   if (self->unkD4 && (self->unkDA & 4) && (self->unkD8 & 1))
    self->unkD4->vf14(1, self, arg2, arg3);
   fn_801AAB18(self, arg3);
   {
    int updated = sp8;
    if (self->unkD4 && (self->unkDA & 4) && (self->unkD8 & 2))
     self->unkD4->vf14(2, self, updated, arg3);
   }
   if (self->unkE8) {
    Sub** p = (Sub**)self->unkDC;
    Sub** end = p + self->unkE4;
    p = findSub(p, end, self->unkE8);
    if (p == end)
     self->unkE8 = 0;
   }
   if (self->unkE8)
    self->unkE8->vf0c(4, sp8, arg3);
   {
    int updated = sp8;
    if (self->unkD4 && (self->unkDA & 4) && (self->unkD8 & 4))
     self->unkD4->vf14(4, self, updated, arg3);
   }
   break;
  case 6:
  case 7:
  case 0x10001:
  case 0x10002:
  case 0x10003:
   fn_801ABA14(self, arg1, arg2, arg3);
   break;
  case 5:
   if (self->unkE8) {
    Sub** p = (Sub**)self->unkDC;
    Sub** end = p + self->unkE4;
    p = findSub(p, end, self->unkE8);
    if (p == end)
     self->unkE8 = 0;
   }
   if (self->unkE8) {
    int r = arg3->fn_801B35D0(self, 0, 0);
    if (r == 0) {
     self->unkE8->vf0c(arg1, sp8, arg3);
    } else if (r == 1) {
     int saved = lbl_805A0558;
     lbl_805A0558 = 0;
     int updated = sp8;
     self->unkE8->vf0c(arg1, updated, arg3);
     lbl_805A0558 = saved;
    }
   }
   break;
  case 3:
  case 8:
  default:
   if (self->unkE8) {
    Sub** p = (Sub**)self->unkDC;
    Sub** end = p + self->unkE4;
    p = findSub(p, end, self->unkE8);
    if (p == end)
     self->unkE8 = 0;
   }
   if (self->unkE8)
    self->unkE8->vf0c(arg1, sp8, arg3);
   break;
  }
 }
}
}