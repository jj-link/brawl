#pragma force_active on

typedef unsigned char u8;
typedef signed int s32;
struct Rc4State
{
  u8 s[256];
  u8 i;
  u8 j;
  u8 k;
  u8 l;
  u8 m;
};
inline u8 inline_fn(struct Rc4State *arg0, u8 arg1)
{
  return arg0->s[arg1];
}

void fn_8038795C(struct Rc4State *a, u8 *p, s32 n)
{
  u8 in;
  u8 ii;
  u8 jj;
  u8 tmp;
  u8 idx;
  u8 t1;
  u8 out;
  u8 jv;
  u8 lv;
  u8 mv;
  for (; n > 0; n--)
  {
    in = *p;
    ii = a->i;
    jj = a->j;
    jj = jj + a->s[ii];
    a->j = jj;
    a->i = ii + 1;
    tmp = a->s[a->m];
    a->s[a->m] = a->s[a->j];
    a->s[a->j] = a->s[a->l];
    a->s[a->l] = a->s[a->i];
    a->s[a->i] = tmp;
    a->k = a->k + a->s[tmp];
    jv = a->j;
    lv = a->l;
    mv = a->m;
    idx = (u8) (inline_fn(a, mv) + (a->s[jv] + a->s[lv]));
    t1 = a->s[(u8) (a->s[a->k] + a->s[a->i])];
    out = (in ^ t1) ^ a->s[a->s[idx]];
    a->m = in;
    a->l = out;
    *p = out;
    p++;
  }

}
