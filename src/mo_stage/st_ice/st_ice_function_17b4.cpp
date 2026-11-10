#pragma force_active on
#pragma fp_contract off

extern "C" const float lbl_62_rodata_0[];
class SceneLayer { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual float getValue(); };
struct SceneRoot { char pad[0x54]; SceneLayer* layer; }; extern "C" SceneRoot* g_gfSceneRoot;
struct MeleeBase { char pad[0x3c]; };
class MeleeVT : public MeleeBase { public:
virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); };
struct stMelee : MeleeVT { char p40[0x50]; void* unk90; char p94[8]; float* unk9C; char pa0[0x100]; void* unk1A0; char p1a4[0x34]; unsigned char unk1D8; char p1d9[0x25f]; signed char unk438; char p439[3]; float unk43C; char p440[0x44]; signed char unk484; char p485[0x67]; float unk4EC; char unk4F0; };
extern "C" void* getData__9gfArchiveF11ARCNodeTypeiUs(void*,int,int,unsigned short);
extern "C" void loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(void*,void*);
extern "C" void zoomOutCamera__7stMeleeFff(void*,float,float); extern "C" void zoomInCamera__7stMeleeFv(void*);
extern "C" void fn_62_17B4(stMelee* self,float delta) { const float* c=lbl_62_rodata_0; float* pos=self->unk9C; if(pos) { float f=c[0]; SceneLayer* layer=g_gfSceneRoot->layer; if(layer)f=layer->getValue();
switch(self->unk1D8) { case 0:self->unk438=1;self->unk1D8=4;break;
case 4:if(f>=c[11]){self->unk438=2;self->unk484=0xC;void*res=getData__9gfArchiveF11ARCNodeTypeiUs(self->unk1A0,2,0x6E,0xFFFE);if(res){void*spC=res;loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->unk90,&spC);}self->m40();zoomOutCamera__7stMeleeFff(self,c[12],c[13]);self->unk1D8=5;}break;
case 5:if(f>=c[14]){self->unk438=3;self->unk484=5;void*res=getData__9gfArchiveF11ARCNodeTypeiUs(self->unk1A0,2,0x64,0xFFFE);if(res){void*sp8=res;loadPositionData__11stPositionsFPQ34nw4r3g3d7ResFile(self->unk90,&sp8);}self->m40();zoomInCamera__7stMeleeFv(self);self->unk1D8=6;}break;
case 6:if(f>=c[15]){self->unk438=4;self->unk484=0;self->unk1D8=7;}else if(f>=c[15]-pos[0]&&(unsigned char)self->unk4F0==0xE){self->unk4EC=pos[1];self->unk4F0=5;}break;
case 7:if(f<self->unk43C){self->unk438=1;self->unk1D8=4;}break; }
switch(self->unk4F0) { case 5: self->unk4EC=self->unk4EC-delta; if(self->unk4EC<c[0])self->unk4EC=c[0]; if(c[0]==self->unk4EC)self->unk4F0=0xE; break; default: break; }
float g=c[0];SceneLayer*layer2=g_gfSceneRoot->layer;if(layer2)g=layer2->getValue();self->unk43C=g; } }