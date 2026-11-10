#include <types.h>
#include <revolution/GX.h>
#include <revolution/GX/GXVert.h>
#pragma force_active on
class Object_vptr_0 {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8(void*);
};
struct Inner { char pad[0x20]; int state; };
struct Owner {
char pad0[4]; Inner* inner; char pad1[0x1e0];
Object_vptr_0* objs[5];
char pad3[12];
char data[0x1fc];
int value; int total; char pad2[4]; u8 color[3];
};
extern Owner* lbl_805A0E80;
extern f32 lbl_805A3AE8;
extern f32 lbl_805A3AEC;
extern "C" void fn_8027869C();
extern "C" void fn_801F3D60(int, GXColor);
static inline void drawObjects(Owner* p) {
p->objs[0]->slot8(p->data);
if (p->inner->state == 0) {
for (int i=3;i>=0;--i) p->objs[i+1]->slot8(p->data);
}
}
static inline void drawOverlay(Owner* p, GXColor& color) {
u8 alpha;
alpha = p->value * 255 / p->total;
fn_8027869C();
color.r=p->color[0];
color.g=p->color[1];
color.b=p->color[2];
color.a=alpha;
fn_801F3D60(1,color);
GXBegin(GX_QUADS,GX_VTXFMT0,4);
WGPIPE.f=lbl_805A3AE8;
WGPIPE.f=lbl_805A3AE8;
WGPIPE.f=lbl_805A3AE8;
WGPIPE.f=lbl_805A3AEC;
WGPIPE.f=lbl_805A3AEC;
WGPIPE.f=lbl_805A3AEC;
WGPIPE.f=lbl_805A3AEC;
WGPIPE.f=lbl_805A3AE8;
}
extern "C" void fn_8026F708() {
Owner* p = lbl_805A0E80;
drawObjects(p);
GXColor color;
drawOverlay(p, color);
}
