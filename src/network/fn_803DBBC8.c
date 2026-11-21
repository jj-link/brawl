#pragma force_active on

typedef enum _va_arg_type
{
  arg_ARGPOINTER,
  arg_WORD,
  arg_DOUBLEWORD,
  arg_ARGREAL
} _va_arg_type;
typedef struct __va_list_struct
{
  char gpr;
  char fpr;
  char *input_arg_area;
  char *reg_save_area;
} va_list[1];
void *__va_arg(va_list argp, int type);
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef double f64;
typedef int UNKWORD;
typedef void UNKTYPE;
enum 
{
  FALSE,
  TRUE
};
typedef int BOOL;
typedef void (*funcptr_t)(void);
typedef enum 
{
  PF_RESULT_OK = 0,
  PF_RESULT_INVALID = 10
} PFResult;
typedef struct PF_ENT_ITER
{
  char _0x0[0x8];
  u32 _0x8;
  char _0xC[0x2c];
  void *unk;
  char _0x3c[0x31];
} PF_ENT_ITER;
typedef struct PF_DIR_ENT
{
  char _0x0[0x228];
  u32 _0x228;
  void *cache;
  char _0x230[4];
  u32 _0x234;
  int sector;
  short offset;
} PF_DIR_ENT;
typedef enum 
{
  PFSTR_CODEMODE_NONE,
  PFSTR_CODEMODE_OEM,
  PFSTR_CODEMODE_UNICODE,
  PFSTR_CODEMODE_LOCAL
} PFSTR_CodeMode;
typedef struct PF_STR
{
  const char *head;
  const char *tail;
  const char *local;
  u32 mode;
} PF_STR;
void VFiPFSTR_SetCodeMode(PF_STR *str, u32 mode);
u32 VFiPFSTR_GetCodeMode(PF_STR *str);
void VFiPFSTR_SetLocalStr(PF_STR *str, char *local);
char *VFiPFSTR_GetStrPos(PF_STR *str, u32 target);
void VFiPFSTR_MoveStrPos(PF_STR *str, s16 n);
s32 VFiPFSTR_InitStr(PF_STR *str, const char *s, u32 mode);
u16 VFiPFSTR_StrLen(PF_STR *str);
u16 VFiPFSTR_StrNumChar(PF_STR *str, u32 target);
s32 VFiPFSTR_StrCmp(const PF_STR *str, const char *cmp);
int VFiPFSTR_StrNCmp(PF_STR *str, const char *cmp, u32 target, s16 offset, u16 n);
void VFiPFSTR_ToUpperNStr(PF_STR *str, u16 n, char *out);
s32 PFSTR_InitStr(PF_STR *str, const char *s, u32 mode);
typedef struct Rec
{
  u16 s0;
  u8 pad0[0x208];
  u8 b20a;
  u8 b20b;
  u8 b20c;
  u8 pad1[0x21c - 0x20d];
  u8 b21c;
  u8 pad2[0x224 - 0x21d];
  u16 h224;
  u16 h226;
  u32 w228;
  u32 w22c;
  u32 w230;
  u32 w234;
  u32 w238;
  u16 h23c;
  u8 pad3[2];
} Rec;
typedef struct Obj
{
  u8 pad0[8];
  u8 *p8;
  u32 pC;
  u32 n10;
  u32 f14;
  u8 b18;
  u8 b19;
  u8 b1a;
  u8 b1b;
  char buf1c[0x208];
  u16 h224;
  u16 h226;
  u32 w228;
  u8 b22c;
  char b22d[0xd];
  char b23a;
  u8 pad[0x444 - 0x23b];
  char b444[0x208];
  char b64c[0x1a];
  u16 h666;
} Obj;
typedef struct Global
{
  u8 pad[0x60];
  u32 flags;
} Global;
extern Global lbl_805644C0;
extern void fn_803D66FC(PF_STR *, void *);
extern char *fn_803D645C(char *, char *);
extern u16 *fn_803D6528(u16 *, const u16 *);
extern void fn_803E2414(void *, void *, void *, void *);
extern s32 fn_803DD390(void *, void *, u32, void *, u32, s32, s32 *, u32 *);
extern void fn_803E7C50(void *, void *);
extern void fn_803E7D7C(void *, void *);
s32 fn_803DBBC8(Obj *o)
{
  Rec r;
  u8 sp30[56];
  u8 sp20[16];
  PF_STR str;
  s32 spC;
  u32 sp8;
  s32 ret;
  s32 i;
  s32 offset;
  u32 a;
  u32 b;
  u16 c;
  u8 *p;
  u8 *e;
  u32 fl;
  spC = 0;
  sp8 = 0;
  i = 0;
  if ((o->f14 & 1) == 1)
  {
    ret = PFSTR_InitStr(&str, o->buf1c, 1);
  }
  else
  {
    ret = PFSTR_InitStr(&str, o->b444, 2);
  }
  if (ret != 0)
  {
    return ret;
  }
  fn_803D66FC(&str, o->buf1c);
  goto cond;
  body:
  if (o->n10 >= 0xF423F)
  {
    return 10;
  }

  r.w234 = o->pC;
  fn_803E2414(sp30, sp20, o->p8, &r.w234);
  ret = fn_803DD390(sp30, &r, o->n10, &str, o->b1b, 0, &spC, &sp8);
  if (ret != 0)
  {
    return ret;
  }
  o->n10 = sp8 + 1;
  if ((sp8 + 0xFFF10000) == 0x423F)
  {
    return 3;
  }
  goto after;
  cond:
  if (sp8 < 0xF423F)
  {
    goto body;
  }

  after:
  fn_803D645C(o->b22d, ((char *) (&r)) + 0x20e);

  if ((o->f14 & 2) == 2)
  {
    fn_803E7D7C(o->b64c, o->b22d);
  }
  if (r.s0 != 0)
  {
    if ((lbl_805644C0.flags & 2) == 2)
    {
      lbl_805644C0.flags = (lbl_805644C0.flags & (~3)) | 1;
      fn_803E7C50(&o->b23a, &r);
      lbl_805644C0.flags = (lbl_805644C0.flags & (~3)) | 2;
    }
    else
    {
      fn_803E7C50(&o->b23a, &r);
    }
    if ((o->f14 & 2) == 2)
    {
      fn_803D6528(&o->h666, &r.s0);
    }
  }
  else
  {
    o->b23a = 0;
    if ((o->f14 & 2) == 2)
    {
      o->h666 = 0;
    }
  }
  p = o->p8;
  if ((*((u32 *) (p + 0x161c))) != 0)
  {
    a = r.w22c;
    b = r.w238;
    i = 0;
    c = r.h23c;
    offset = 0;
    for (; i < 5; offset += 0x29c, i++)
    {
      e = p + offset;
      fl = *((u32 *) (e + 0x40));
      if (((((fl & 1) && (fl & 2)) && (a == (*((u32 *) (e + 0x2a8))))) && (b == (*((u32 *) (e + 0x2b4))))) && (c == (*((u16 *) (e + 0x2b8)))))
      {
        o->w228 = *((u32 *) ((p + (i * 0x29c)) + 0x2a4));
        e = o->p8 + (i * 0x29c);
        o->h224 = *((u16 *) (e + 0x2a0));
        o->h226 = *((u16 *) ((o->p8 + (i * 0x29c)) + 0x2a2));
        o->b22c = *((u8 *) ((o->p8 + (i * 0x29c)) + 0x298));
        o->b18 = *((u8 *) ((o->p8 + (i * 0x29c)) + 0x286));
        o->b19 = *((u8 *) ((o->p8 + (i * 0x29c)) + 0x287));
        o->b1a = *((u8 *) ((o->p8 + (i * 0x29c)) + 0x288));
        break;
      }
    }

  }
  if (((*((u32 *) (o->p8 + 0x161c))) == 0) || (i == 5))
  {
    o->w228 = r.w228;
    o->h224 = r.h224;
    o->h226 = r.h226;
    o->b22c = r.b21c;
    o->b18 = r.b20a;
    o->b19 = r.b20b;
    o->b1a = r.b20c;
  }
  return 0;
}
