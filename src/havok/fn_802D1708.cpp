#pragma force_active on
struct Obj { char pad0[0xC]; float w; char pad1[0x20]; float* src; char pad2[0x8]; int count; };
extern "C" void* fn_802D1708(void* self_, void* out_) {
 Obj* self = (Obj*)self_;
 int n = self->count - 1;
 float* out = (float*)out_;
 float* s = self->src;
 while (n >= 3) {
  float v[4] __attribute__((aligned(16)));
  n -= 4;
  { float x, y, z, w; w=self->w; z=s[8]; y=s[4]; x=s[0]; v[1]=y; v[0]=x; v[2]=z; v[3]=w; }
  out[0]=v[0]; out[1]=v[1]; out[2]=v[2]; out[3]=v[3];
  { float x, y, z, w; w=self->w; z=s[9]; y=s[5]; x=s[1]; v[1]=y; v[0]=x; v[2]=z; v[3]=w; }
  out[4]=v[0]; out[5]=v[1]; out[6]=v[2]; out[7]=v[3];
  { float x, y, z, w; w=self->w; z=s[10]; y=s[6]; x=s[2]; v[0]=x; v[1]=y; v[2]=z; v[3]=w; }
  out[8]=v[0]; out[9]=v[1]; out[10]=v[2]; out[11]=v[3];
  { float x, y, z, w; w=self->w; z=s[11]; y=s[7]; x=s[3]; v[0]=x; v[1]=y; v[2]=z; v[3]=w; }
  out[12]=v[0]; out[13]=v[1]; out[14]=v[2]; out[15]=v[3];
  s += 12; out += 16;
 }
 if (n >= 0) {
  float v[4] __attribute__((aligned(16)));
  { float x, y, z, w; w=self->w; z=s[8]; y=s[4]; x=s[0]; v[1]=y; v[0]=x; v[2]=z; v[3]=w; }
  out[0]=v[0]; out[1]=v[1]; out[2]=v[2]; out[3]=v[3]; out += 4;
 }
 if (n >= 1) {
  float v[4] __attribute__((aligned(16)));
  { float x, y, z, w; w=self->w; z=s[9]; y=s[5]; x=s[1]; v[1]=y; v[0]=x; v[2]=z; v[3]=w; }
  out[0]=v[0]; out[1]=v[1]; out[2]=v[2]; out[3]=v[3]; out += 4;
 }
 if (n >= 2) {
  float v[4] __attribute__((aligned(16)));
  { float x, y, z, w; w=self->w; z=s[10]; y=s[6]; x=s[2]; v[1]=y; v[0]=x; v[2]=z; v[3]=w; }
  out[0]=v[0]; out[1]=v[1]; out[2]=v[2]; out[3]=v[3];
 }
 return out_;
}