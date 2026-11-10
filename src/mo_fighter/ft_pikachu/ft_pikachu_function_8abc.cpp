#pragma force_active on
#pragma optimization_level 1
extern "C" {
extern char lbl_98_data_B04[], lbl_98_data_1E64[], lbl_98_data_1F14[], lbl_98_data_1FA4[], lbl_98_data_2034[];
extern char lbl_98_data_1B34[], lbl_98_data_1C9C[], lbl_98_data_1D28[], lbl_98_data_16B4[], lbl_98_data_1880[], lbl_98_data_1908[];
extern char lbl_98_data_10C0[], lbl_98_data_12F8[], lbl_98_data_1388[], lbl_98_data_1418[], lbl_98_data_EA0[];
extern unsigned char g_ftCommonDataAccesser[];
void fn_27_1A558C(void*, int);
void fn_27_19F434(void*, int, int);
void* fn_27_148184(void*, int, unsigned char*);
void fn_98_192F8(void*, int, void*, void*);
void fn_98_8CD0(void*, void*);
void fn_98_8D64(void*, void*);
void fn_98_8DF8(void*, void*);
void fn_27_92F10(void*, void*, void*, void*, void*);
}
struct Fn98Args { unsigned char a,b; int c,d,e,f; int* g; void* h; };
extern "C" void* fn_98_8ABC(char* self, char* accesser) {
 Fn98Args args;
 int zero; char* base; char* p; char* q; char* r; char* t;
 fn_27_1A558C(self,0);
 fn_27_19F434(self+0x20,5,0);
 base=self+0x7c;
 void* vt=lbl_98_data_B04;
 *(void**)(self+0x7c)=vt;
 *(void**)(self+0x80)=(char*)vt+0x10;
 p=base+8;
 *(void**)(self+0x84)=lbl_98_data_1E64;
 *(void**)(self+0x88)=lbl_98_data_1F14;
 q=p+8;
 *(void**)(self+0x8c)=lbl_98_data_1FA4;
 *(void**)(self+0x90)=lbl_98_data_2034;
 fn_98_8CD0(q+0xc,accesser);
 fn_98_8CD0(q+0x1fd4,accesser);
 fn_98_8CD0(p+0x3fa4,accesser);
 *(void**)p=lbl_98_data_1B34;
 *(void**)(p+0x5f6c)=lbl_98_data_1C9C;
 r=p+0x5f74;
 *(void**)(p+0x5f74)=lbl_98_data_1D28;
 zero=0;
 args.a=zero; args.b=zero; args.c=zero;
 int seven=7;
 args.d=seven;
 void* value=*(void**)(*(char**)(accesser+0xd8)+0xc0);
 args.e=zero; args.f=seven; args.g=&args.e; args.h=value;
 fn_98_192F8(r+4,2,&args.g,fn_27_148184(g_ftCommonDataAccesser,seven,&args.b));
 *(void**)p=lbl_98_data_16B4;
 r=p+0x7f40;
 *(void**)(p+0x7f40)=lbl_98_data_1880;
 *(void**)(p+0x7f44)=lbl_98_data_1908;
 fn_98_8D64(r+0xc,accesser);
 fn_98_8D64(r+0xa60c,accesser);
 *(void**)p=lbl_98_data_10C0;
 r=p+0x20000;
 *(void**)(r-0x34b4)=lbl_98_data_12F8;
 t=r-0x34b0;
 *(void**)t=lbl_98_data_1388;
 *(void**)(r-0x34ac)=lbl_98_data_1418;
 fn_98_8DF8(t+0xc,accesser);
 fn_98_8DF8(t+0x1fa4,accesser);
 fn_98_8DF8(r+0xa8c,accesser);
 *(void**)p=lbl_98_data_EA0;
 *(unsigned char*)(base+0x22a2c)=zero;
 fn_27_92F10(self+0x22aac,accesser,self,base,self+0x20);
 return self;
}