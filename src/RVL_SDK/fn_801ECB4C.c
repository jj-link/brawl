
#pragma force_active on
extern const float lbl_805A3758;
extern const float lbl_805A375C;
extern const float lbl_805A3768;
extern const float lbl_805A376C;
inline float inline_fn(float arg0)
{
  return arg0;
}

void fn_801ECB4C(float m[3][4], float t, float b, float l, float r, float n, float scaleS, float scaleT, float transS, float transT)
{
  float tmp;
  float new_var;
  tmp = lbl_805A3758 / (r - l);
  m[0][0] = scaleS * ((lbl_805A3768 * n) * inline_fn(tmp));
  m[0][1] = lbl_805A375C;
  m[0][2] = (scaleS * (tmp * (r + l))) - transS;
  do
  {
  }
  while (0);
  m[0][3] = lbl_805A375C;
  tmp = lbl_805A3758 / (t - b);
  new_var = lbl_805A3768 * n;
  m[1][0] = lbl_805A375C;
  m[1][1] = scaleT * (new_var * tmp);
  m[1][2] = (scaleT * (tmp * (t + b))) - transT;
  m[1][3] = lbl_805A375C;
  m[2][0] = lbl_805A375C;
  m[2][1] = lbl_805A375C;
  m[2][2] = lbl_805A376C;
  m[2][3] = lbl_805A375C;
}
