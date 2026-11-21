#pragma force_active on
extern void fn_8035E00C(void *);
extern int closesocket(int);
extern int fn_8035A590(int);
extern void *fn_8035A598(int, int);
extern int fn_80388590(void *);
extern void *fn_8035B1C4(int, int *);
extern void fn_8035B120(int, int *);
extern void fn_8035A4FC(int);
extern void fn_8035ADB0(int);
extern int fn_803889C0(int);
extern void fn_8038862C(int *);
extern void fn_803889B8(int, int);
extern void fn_803885E8(void *);
void fn_8038AF70(void *self) {
 int locals[5], sp8;
 int i,j,val,count,temp2,k,chain,next;
 char *ptr;
 void *temp;
 if (*(int *)((char *)self + 0x7C)) fn_8035E00C(*(void **)((char *)self + 0x7C));
 *(int *)((char *)self + 0x7C)=0;
 *(int *)((char *)self + 0x80)=0;
 if (*(int *)((char *)self + 0x6B4)!=-1) closesocket(*(int *)((char *)self + 0x6B4));
 *(int *)((char *)self + 0x6B4)=-1;
 *(int *)self=1;
 if (*(int *)((char *)self + 8)) {
  i=0;
  while (i<fn_8035A590(*(int *)((char *)self+8))) {
   locals[1]=*(int *)fn_8035A598(*(int *)((char *)self+8),i);
   temp=fn_8035B1C4(fn_80388590(self),&locals[1]);
   if (temp) {
    temp2=*(int *)((char *)temp+4)-1;
    *(int *)((char *)temp+4)=temp2;
    if (!temp2) fn_8035B120(fn_80388590(self),&locals[1]);
   }
   i++;
  }
  fn_8035A4FC(*(int *)((char *)self+8));
  *(int *)((char *)self+8)=0;
 }
 ptr=(char *)self;
 *(int *)((char *)self+0x484)=-1;
 j=0;
 while (j<*(int *)((char *)self+0x480)) {
  locals[3]=*(int *)(ptr+0x84);
  temp=fn_8035B1C4(fn_80388590(self),&locals[3]);
  if (temp) {
   temp2=*(int *)((char *)temp+4)-1;
   *(int *)((char *)temp+4)=temp2;
   if (!temp2) fn_8035B120(fn_80388590(self),&locals[3]);
  }
  ptr+=4;
  j++;
 }
 *(int *)((char *)self+0x480)=0;
 count=fn_8035A590(*(int *)((char *)self+4));
 k=0;
 while (k<count) {
  val=*(int *)fn_8035A598(*(int *)((char *)self+4),k);
  if (!*(int *)((char *)self+0x7D8)) fn_803889B8(val,0);
  else fn_803889B8(val,*(int *)((char *)self+0x7D8));
  *(int *)((char *)self+0x7D8)=val;
  k++;
 }
 fn_8035ADB0(*(int *)((char *)self+4));
 chain=*(int *)((char *)self+0x7D8);
 if (chain!=0) {
  sp8=chain;
  while (sp8 != 0) {
   chain=fn_803889C0(sp8);
   fn_8038862C(&sp8);
   sp8=chain;
  }
  *(int *)((char *)self+0x7D8)=0;
 }
 fn_803885E8(self);
 if (*(int *)((char *)self+4)) fn_8035A4FC(*(int *)((char *)self+4));
 *(int *)((char *)self+4)=0;
}