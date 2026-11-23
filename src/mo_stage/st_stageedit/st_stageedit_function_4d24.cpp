#pragma force_active on
#include <gr/gr_gimmick.h>
#include <snd/snd_3d_generator.h>
extern "C" void fn_85_4D24(void* arg) {
int r31; int r30; int numPlayed; int n; char* entry; int i; char* self=(char*)arg; int off8; int off4;
if (*(int*)(self+0x208)>0) {
int i=0; char* idp=self; snd3DGenerator* gen=(snd3DGenerator*)(self+0x22C);
while(i<*(int*)(self+0x208)) {gen->stopSE(*(int*)(idp+0x20C),0); idp+=4; gen++; i++;}
*(int*)(self+0x208)=0;
}
r31=*(int*)(self+0x2D0); r30=*(int*)(self+0x2CC);
if(r31+r30>8) {if(r31<=4) r30=8-r31; else if(r30<=4) r31=8-r30; else {r31=4;r30=4;}}
n=*(int*)(self+0x2C0); entry=self+0x4F4; numPlayed=0; off8=0; off4=0;
for(i=0;i<n;entry+=0x18) {
unsigned int word=*(unsigned int*)entry;
if(((word>>10)&3)==3) {
switch((word>>6)&0xF) {
case 3: if(r30>0) {snd3DGenerator* gen;Vec3f copy;copy=(*(grGimmick**)(entry+8))->getPos();gen=(snd3DGenerator*)(self+0x22C+off8);gen->setPos(&copy);*(int*)(self+off4+0x20C)=gen->playSE((SndID)0x1D9D,-1,0,-1);numPlayed++;off8+=8;off4+=4;r30--;}break;
case 7: if(r31>0) {snd3DGenerator* gen;Vec3f copy;copy=(*(grGimmick**)(entry+8))->getPos();gen=(snd3DGenerator*)(self+0x22C+off8);gen->setPos(&copy);*(int*)(self+off4+0x20C)=gen->playSE((SndID)0x1D9B,-1,0,-1);numPlayed++;off8+=8;off4+=4;r31--;}break;
}}
i++;
}
*(int*)(self+0x208)=numPlayed;
}