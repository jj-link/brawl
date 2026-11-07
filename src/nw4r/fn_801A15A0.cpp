#pragma force_active on
struct Block { unsigned int v[12]; };
struct Input { unsigned int pad; unsigned char a,b,c,pad2; Block x,y,z; };
struct Output { unsigned int flags; Block x,y,z; };
extern "C" void fn_801A15A0(Input* in, Output* out) {
    if (in->a) { out->x = in->x; out->flags |= 1; }
    if (in->b) { out->y = in->y; out->flags |= 2; }
    if (in->c) { out->z = in->z; out->flags |= 4; }
}