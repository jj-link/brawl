#include "gf/gf_camera.h"
#pragma force_active on
extern const float lbl_805A17A8;
struct S { float f[10]; };
extern "C" void fn_800437DC(const S* s) {
 const float* a=s->f;
 float p9,p8,p5,p4,p7,p6,k,p3,p2;
 p2=a[2]; p3=a[3]; p6=a[6]; p7=a[7]; p4=a[4]; p5=a[5]; p8=a[8]; p9=a[9]; k=lbl_805A17A8;
 { float buf[0xF2];
*(float*)((char*)buf+0x30)=p2;
*(float*)((char*)buf+0x34)=p3;
*(float*)((char*)buf+0x38)=k;
*(float*)((char*)buf+0x384)=p2;
*(float*)((char*)buf+0x40)=p3;
*(float*)((char*)buf+0x80)=k;
*(float*)((char*)buf+0x24)=p6;
*(float*)((char*)buf+0x28)=p7;
*(float*)((char*)buf+0x2C)=k;
*(float*)((char*)buf+0xC0)=p6;
*(float*)((char*)buf+0x100)=p7;
*(float*)((char*)buf+0x140)=k;
*(float*)((char*)buf+0x18)=p4;
*(float*)((char*)buf+0x1C)=p5;
*(float*)((char*)buf+0x20)=k;
*(float*)((char*)buf+0x180)=p4;
*(float*)((char*)buf+0x1C0)=p5;
*(float*)((char*)buf+0x200)=k;
*(float*)((char*)buf+0x0C)=p8;
*(float*)((char*)buf+0x10)=p9;
*(float*)((char*)buf+0x14)=k;
*(float*)((char*)buf+0x240)=p8;
*(float*)((char*)buf+0x280)=p9;
*(float*)((char*)buf+0x2C0)=k;
*(float*)((char*)buf+0x00)=p2;
*(float*)((char*)buf+0x04)=p3;
*(float*)((char*)buf+0x08)=k;
*(float*)((char*)buf+0x300)=p2;
*(float*)((char*)buf+0x340)=p3;
*(float*)((char*)buf+0x380)=k;
} gfCameraManager::getManager();
}
