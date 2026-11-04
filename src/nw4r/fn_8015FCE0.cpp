#pragma force_active on
struct Color { unsigned char r,g,b,a; };
struct Obj { char pad[8]; Color out[4]; Color base, alt; int mode; char pad2[0x1e]; unsigned char alpha; };
extern "C" void fn_8015FCE0(Obj* p) {
 p->out[0] = p->base;
 p->out[1] = p->mode != 1 ? p->base : p->alt;
 p->out[2] = p->mode != 2 ? p->base : p->alt;
 p->out[3] = p->mode == 0 ? p->base : p->alt;
 p->out[0].a = p->out[0].a * p->alpha / 255;
 p->out[1].a = p->out[1].a * p->alpha / 255;
 p->out[2].a = p->out[2].a * p->alpha / 255;
 p->out[3].a = p->out[3].a * p->alpha / 255;
}