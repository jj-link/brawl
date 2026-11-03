#pragma force_active on

extern float lbl_805A3D18;
extern float lbl_805A3D1C;
void fn_80283E28(float *dst, float *src)
{
  float one;
  float z;
  float l;
  float n;
  float m;
  float k;
  float j;
  float i;
  float h;
  float g;
  float f;
  float e;
  float d;
  float c;
  float a;
  float b;
  b = src[3];
  a = *(src + 7);
  c = src[0];
  d = src[1];
  e = src[2];
  f = src[4];
  g = src[5];
  h = src[6];
  i = src[8];
  j = src[9];
  k = src[10];
  m = src[12];
  n = src[13];
  l = src[14];
  dst[3] = b;
  z = lbl_805A3D18;
  dst[7] = a;
  one = lbl_805A3D1C;
  dst[0] = c;
  dst[1] = d;
  dst[2] = e;
  dst[4] = f;
  dst[5] = g;
  dst[6] = h;
  dst[8] = i;
  dst[9] = j;
  dst[10] = k;
  dst[12] = m;
  dst[13] = n;
  dst[14] = l;
  dst[11] = (dst[7] = (dst[3] = z));
  dst[15] = one;
}
