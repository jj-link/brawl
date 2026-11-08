#pragma force_active on
extern "C" void fn_800A4154(void*);
extern "C" float lbl_805A1F90;
struct V { int x,y,z; };
struct F { float x,y,z; };
struct Flags { unsigned char a:5; unsigned char bit:1; unsigned char b:2; };
extern "C" void fn_800A5704(void* self) {
 char* s=(char*)self;
 V a,b,c;
 fn_800A4154(self);
 void* ptr=*(void**)(s+0xe4);
 if(ptr) a=*(V*)((char*)ptr+0x10);
 else {
  *(F*)(s+0x110)=*(F*)(s+0x11c);
  ((Flags*)(s+0xb))->bit=1;
  a=*(V*)(s+0x110);
 }
 *(F*)(s+0x5c)=*(F*)&a;
 ptr=*(void**)(s+0xe4);
 if(ptr) b=*(V*)((char*)ptr+0x10);
 else {
  *(F*)(s+0x110)=*(F*)(s+0x11c);
  ((Flags*)(s+0xb))->bit=1;
  b=*(V*)(s+0x110);
 }
 *(F*)(s+0x50)=*(F*)&b;
 ptr=*(void**)(s+0xe4);
 if(ptr) c=*(V*)((char*)ptr+0x10);
 else {
  *(F*)(s+0x110)=*(F*)(s+0x11c);
  ((Flags*)(s+0xb))->bit=1;
  c=*(V*)(s+0x110);
 }
 float z,y,x;
 x=((F*)&c)->x; y=((F*)&c)->y; z=((F*)&c)->z;
 F zero={lbl_805A1F90,lbl_805A1F90,lbl_805A1F90};
 *(float*)(s+0x2c)=x;
 *(float*)(s+0x30)=y;
 *(float*)(s+0x34)=z;
 *(F*)(s+0x80)=zero;
}