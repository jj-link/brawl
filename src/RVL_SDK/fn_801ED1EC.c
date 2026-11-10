#pragma force_active on

typedef struct 
{
  int v[3];
} Table;
typedef struct 
{
  float m[3][4];
} Input;
typedef struct 
{
  float x;
  float y;
  float z;
  float w;
} Output;
extern Table lbl_8040D410;
extern float lbl_805A37A0;
extern float lbl_805A37A4;
extern float lbl_805A37A8;
extern double fn_80400D94(double);
inline float inline_fn(float (*arg0)[4], Input *arg1, int arg2)
{
  return arg0[0][2] - arg1->m[2][arg2];
}

void fn_801ED1EC(Output *out, Input *in)
{
  Table table;
  float loc[3];
  int i;
  int k;
  int j;
  float f;
  float r;
  float inv;
  float c;
  float a;
  float b;
  float w;
  table = lbl_8040D410;
  f = (in->m[0][0] + in->m[1][1]) + in->m[2][2];
  if (f > lbl_805A37A4)
  {
    f = lbl_805A37A0 + f;
    r = (float) fn_80400D94(f);
    inv = lbl_805A37A8 / r;
    w = lbl_805A37A8 * r;
    a = in->m[2][1] - in->m[1][2];
    b = inline_fn(in->m, in, 0);
    c = in->m[1][0] - in->m[0][1];
    a = inv * a;
    out->w = w;
    out->x = a;
    out->y = inv * b;
    out->z = inv * c;
    return;
  }
  i = 0;
  if (in->m[1][1] > in->m[0][0])
  {
    i = 1;
  }
  if (in->m[2][2] > in->m[i][i])
  {
    i = 2;
  }
  j = table.v[i];
  k = table.v[j];
  f = lbl_805A37A0 + (in->m[i][i] - (in->m[j][j] + in->m[k][k]));
  r = (float) fn_80400D94(f);
  loc[i] = lbl_805A37A8 * r;
  if (lbl_805A37A4 != r)
  {
    r = lbl_805A37A8 / r;
  }
  w = r * (in->m[k][j] - in->m[j][k]);
  loc[j] = r * (in->m[i][j] + in->m[j][i]);
  loc[k] = r * (in->m[i][k] + in->m[k][i]);
  out->w = w;
  out->x = loc[0];
  out->y = loc[1];
  out->z = loc[2];
}
