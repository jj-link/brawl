
#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 lbl_8048E7B8[];
extern char lbl_8059F588[5];
typedef struct 
{
  u32 state[4];
  u32 count[2];
  u8 buffer[64];
} MD5_CTX;
void fn_8035B38C(MD5_CTX *ctx, u8 *data, u32 len);
void *memset(void *, int, unsigned long);
int sprintf(char *, const char *, ...);
inline static void Encode(u8 *out, u32 *in, u32 len)
{
  u32 i;
  u32 j;
  for (i = 0, j = 0; j < len; i++, j += 4)
  {
    out[j] = (u8) (in[i] & 0xff);
    out[j + 1] = (u8) ((in[i] >> 8) & 0xff);
    out[j + 2] = (u8) ((in[i] >> 16) & 0xff);
    out[j + 3] = (u8) ((in[i] >> 24) & 0xff);
  }

}

inline static void final(u8 *out, MD5_CTX *ctx)
{
  u8 bits[8];
  u32 n;
  u32 padLen;
  Encode(bits, ctx->count, 8);
  n = (ctx->count[0] >> 3) & 0x3f;
  padLen = (n < 56) ? (56 - n) : (120 - n);
  fn_8035B38C(ctx, lbl_8048E7B8, padLen);
  fn_8035B38C(ctx, bits, 8);
  Encode(out, ctx->state, 16);
  memset(ctx, 0, sizeof(*ctx));
}

void fn_8035C0B4(u8 *data, u32 len, char *outstr)
{
  u8 out[16];
  MD5_CTX ctx;
  u32 new_var3[2];
  char new_var;
  new_var = 2;
  ctx.count[0] = (ctx.count[1] = 0);
  ctx.state[0] = 0x67452301;
  ctx.state[1] = 0xEFCDAB89;
  ctx.state[new_var] = 0x98BADCFE;
  new_var3[0] = 0x10325476;
  ctx.state[3] = new_var3[0];
  fn_8035B38C(&ctx, data, len);
  final(out, &ctx);
  new_var3[1] = 0;
  do
  {
    sprintf(outstr + (new_var3[1] * 2), lbl_8059F588, out[new_var3[1]]);
    new_var3[1]++;
  }
  while (new_var3[1] < 16);
}
