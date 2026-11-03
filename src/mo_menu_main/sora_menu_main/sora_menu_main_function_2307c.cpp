#pragma force_active on
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
struct IVirt { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual float getFloat(); };
struct Node { char pad[0x0c]; IVirt* iface; };
struct Mu { char pad[0x14]; Node* node; };
struct Obj64C { char pad[0x210]; Mu* m210; char pad2[4]; Mu* m218; };
struct Menu { char pad[0x634]; s32 s634; char pad1[0x14]; Obj64C* o64c; char pad2[0x14]; s32 s664; char pad3[4]; u8 s66c; char pad4[3]; s32 s670; s32 s674; char pad5[1]; u8 s679; u8 s67a; };
extern "C" {
extern const float lbl_2_rodata_A98;
extern char lbl_2_data_2C10[]; extern char lbl_2_data_19A0[]; extern char lbl_2_data_19D0[]; extern char lbl_2_data_2BC0[]; extern char lbl_2_data_1AB8[]; extern void* g_sndSystem;
u32 fn_18_12E0(Menu*); s32 fn_2_235F4(Menu*, u32); void fn_800B330C(void*, void*, int); void* getInstance__14gfSceneManagerFv(); void* __dynamic_cast(void*, long, const void*, const void*, short); void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
}
extern "C" s32 fn_2_2307C(Menu* self) {
    s32 r = 0;
    if ((self->s66c >> 7) & 1) { } else if (self->o64c->m210->node->iface->getFloat() == lbl_2_rodata_A98) self->s66c |= 0x80;
    switch (self->s664) {
    case 0: case 1:
        if (self->s670 == 2) { r=4; self->s664=2; break; }
        { u32 flags=fn_18_12E0(self); if(fn_2_235F4(self,flags)!=0){r=4;self->s664=2;} if(flags&0x10){r=4;self->s664=2;} else if(flags&0x20){fn_800B330C(self->o64c->m218,lbl_2_data_2C10+0x3C,0);self->s670=3;r=1;self->s634=0xE;self->s664=3;} }
        break;
    case 2: {
        u32 flags=fn_18_12E0(self); fn_2_235F4(self,flags);
        if(flags&0x10) {
            r=*(s32*)(self->s674+self->s679*4+self->s67a*4);
            char* sm=(char*)getInstance__14gfSceneManagerFv();
            void* p1=__dynamic_cast(*(void**)(sm+4),4,lbl_2_data_19A0,lbl_2_data_19D0,0);
            void* p2=__dynamic_cast(*(void**)((char*)p1+0x3AC),0x668,lbl_2_data_2BC0,lbl_2_data_1AB8,0);
            *(s32*)((char*)p2+0x66C)=r;
            self->s634=0x14; playSE__9sndSystemF5SndIDiiii(g_sndSystem,0x13,-1,0,0,-1); r=2; self->s664=3;
        } else if(flags&0x20){fn_800B330C(self->o64c->m218,lbl_2_data_2C10+0x3C,0);self->s670=3;r=1;self->s634=0xE;self->s664=3;}
        break;
    }
    case 3: if(self->s670==0) r=3; break;
    }
    switch(self->s670) {
    case 0: case 2: break;
    case 1: if(self->o64c->m218->node->iface->getFloat()==lbl_2_rodata_A98){fn_800B330C(self->o64c->m218,lbl_2_data_2C10+0x28,0);self->s670=2;} break;
    case 3: if(self->o64c->m218->node->iface->getFloat()==lbl_2_rodata_A98){fn_800B330C(self->o64c->m218,lbl_2_data_2C10,0);self->s670=0;} break;
    }
    return r;
}