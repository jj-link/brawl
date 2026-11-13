#pragma force_active on
extern "C" { void fn_27_2C0FBC(void*,int,int); int fn_8005136C(int); void fn_803F86E4(void*,const char*,...); void fn_803FC984(void); extern char __files[]; extern void* g_GameGlobal; extern int lbl_27_data_7419C; extern char lbl_27_data_79068[]; }
class Class_90D8 { public: virtual void fn_27_7B274(); virtual void fn_27_7AC18(); virtual void fn_27_7AC28(); virtual void fn_27_7AB50(); virtual void fn_27_7B2EC(); virtual void fn_27_7AB10(); virtual void fn_27_7AD2C(); virtual void fn_27_7AEDC(); virtual void fn_27_7B22C(); virtual void fn_27_7AC38(); virtual void fn_27_7ADE8(); virtual void fn_27_7AF98(); virtual void fn_27_7B0B0(); virtual int fn_27_7ABD8(); };
struct Fig { char pad0[8]; Class_90D8 sub; char pad1[0x304]; int f310; };
struct Self { char data[0x14c0]; };
#define I(o) (*(int*)(self->data+(o)))
#define B(o) (*(unsigned char*)(self->data+(o)))
#define P(o) (*(void**)(self->data+(o)))
extern "C" void fn_27_2A22D4(Self* self,int mode) {
int i,lim; Fig* fig;
I(0x4c)=5; I(0x50)=mode; B(0xbc)=0;
{ unsigned short v; void* gg=*(void**)((char*)g_GameGlobal+8); if(gg) v=*(unsigned short*)((char*)gg+0x1a); else v=0xff; I(0x54)=v; }
i=0; I(0x119c)=lbl_27_data_7419C; I(0x11a0)=lbl_27_data_7419C; I(0x11a4)=lbl_27_data_7419C; I(0x11a8)=lbl_27_data_7419C; I(0x11ac)=lbl_27_data_7419C; I(0x11b0)=lbl_27_data_7419C;
do { int r25=fn_8005136C(i); unsigned w,m; if((unsigned)i>=0xb2){fn_803F86E4(__files+0xa0,lbl_27_data_79068);fn_803FC984();} w=(unsigned)i>>5; m=1u<<(i&31); if(r25) *(unsigned*)(self->data+0x119c+w*4)|=m; else *(unsigned*)(self->data+0x119c+w*4)&=~m; ++i; } while(i<0xb2);
i=0; I(0x147c)=i; B(0x1008)=i;
switch(mode) {
case 3: I(0xff0)=0x2d; fig=(Fig*)P(0x14b8); fig->f310=6; lim=fig->f310; if(lim>fig->sub.fn_27_7ABD8()) fig->f310=fig->sub.fn_27_7ABD8(); else if(lim<0) fig->f310=i; I(0x14b0)=2; fn_27_2C0FBC(P(0x14b8),-0x10,1); break;
case 2: B(0x1008)=1; I(0xff0)=0x28; fig=(Fig*)P(0x14b8); fig->f310=6; lim=fig->f310; if(lim>fig->sub.fn_27_7ABD8()) fig->f310=fig->sub.fn_27_7ABD8(); else if(lim<0) fig->f310=i; break;
case 4: I(0xff0)=0xa; fig=(Fig*)P(0x14b8); fig->f310=i; lim=fig->f310; if(lim>fig->sub.fn_27_7ABD8()) fig->f310=fig->sub.fn_27_7ABD8(); else if(lim<0) fig->f310=i; break;
default: case 1: I(0xff0)=0x28; fig=(Fig*)P(0x14b8); fig->f310=6; lim=fig->f310; if(lim>fig->sub.fn_27_7ABD8()) fig->f310=fig->sub.fn_27_7ABD8(); else if(lim<0) fig->f310=i; I(0x14b0)=2; break;
}
}