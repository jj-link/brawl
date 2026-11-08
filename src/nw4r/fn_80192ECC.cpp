#pragma force_active on
extern float lbl_805A31A0;
struct Inner { char pad[0x14]; unsigned int flags; char pad2[8]; float x,y,z; };
extern "C" void fn_80192ECC(Inner** pp, float x, float y, float z) {
 Inner* p = *pp;
 if (!p) return;
 if (x == y && y == z) {
  p->flags |= 0x10;
  if (1.0f == x) p->flags |= 8;
  else p->flags &= ~8u;
 } else p->flags &= ~0x18u;
 unsigned int flags = p->flags;
 if ((flags & 2) && (flags & 4) && (flags & 8))
  p->flags = flags | 1;
 else p->flags &= ~1u;
 p->x = x;
 p->y = y;
 p->z = z;
}
