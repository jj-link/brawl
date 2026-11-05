#pragma force_active on
typedef struct { unsigned short unk0; char pad0[0x1E]; unsigned char unk20; char pad20[0x15E3]; int unk1604; char pad1604[0x270]; unsigned short unk1878; } UnkStruct;
typedef struct { int unk0; int unk4; int unk8; } UnkSp8;
extern int fn_803AA4E8(void*); extern int fn_803AA540(void*);
extern int fn_803AFF64(void*, int, void**, int); extern void fn_803A9644(void*, void*, int);
extern int fn_803B0048(void*, void*, int); extern int fn_803B00D4(void*, void*, int, unsigned int, unsigned int*);
int fn_803C0440(void* arg0, void* arg1, int arg2, int arg3, unsigned int arg4, unsigned int* arg5, int arg6) {
 void* spC; unsigned int sp8, remaining, rem, diff; UnkStruct* self; int result;
 self=(UnkStruct*)arg0; *arg5=0;
 if(arg0==0)return 0xA; if(arg1==0)return 0xA;
 if((self->unk1878&1)==0||fn_803AA4E8(arg0)==0||fn_803AA540(arg0)!=0)return 9;
 if(arg3!=0||arg4<self->unk0) {
  result=fn_803AFF64(arg0,arg2,&spC,arg6); if(result!=0)return result;
  fn_803A9644((void*)(((UnkSp8*)spC)->unk8+arg3),arg1,arg4);
  result=fn_803B0048(arg0,spC,arg6); if(result!=0)return result;
  *arg5=arg4; goto success;
 }
 if(arg3==0 && (arg4&(self->unk0-1))==0) {
  result=fn_803B00D4(arg0,arg1,arg2,arg4>>self->unk20,&sp8); if(result!=0)return result;
  *arg5=sp8<<self->unk20; if(sp8!=(arg4>>self->unk20))return 0x11; goto success;
 }
 if(arg3==0) {
  remaining=arg4>>self->unk20;
  rem=(arg2+remaining)%self->unk1604;
  if(remaining>rem) {
   diff=remaining-rem; result=fn_803B00D4(arg0,arg1,arg2,diff,&sp8); if(result!=0)return result;
   *arg5=sp8<<self->unk20; if(sp8!=diff)return 0x11;
   arg2+=diff; remaining-=diff;
  }
  if(remaining==0)goto success;
  result=fn_803AFF64(arg0,arg2,&spC,arg6); if(result!=0)return result;
  fn_803A9644((void*)((UnkSp8*)spC)->unk8,(void*)((char*)arg1+*arg5),remaining<<self->unk20);
  result=fn_803B0048(arg0,spC,arg6); if(result!=0)return result;
  *arg5+=remaining<<self->unk20; goto success;
 }
 return 0xA;
success: return 0;
}