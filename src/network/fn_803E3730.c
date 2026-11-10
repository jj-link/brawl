
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
int PFSEC_ReadData(void *cache, void *buffer, int sector, int offset, int len, int *success, int unk);
int PFSEC_WriteData(void *cache, void *buffer, int sector, int offset, int len, int *success, int unk);
#pragma force_active on
typedef struct Info
{
  u16 size;
  u8 pad[0x1E];
  u8 shift;
} Info;
typedef struct Cache
{
  u8 pad[0x264];
  u32 total;
  Info *info;
} Cache;
typedef struct File
{
  u8 pad0[8];
  Cache *cache;
  u8 pad1[0x10];
  u32 f1c;
  u32 f20;
  u32 f24;
  u16 f28;
} File;
extern s32 fn_803E1414(void *, u32, s32, void *);
extern void fn_803E3614(void *, s32, u32);
s32 fn_803E3730(File *arg0, void *arg1, u32 arg2, s32 *arg3)
{
  int sp8;
  Info *new_var[2];
  s32 r;
  u32 remain;
  *arg3 = 0;
  if (arg0->f28 == 0)
  {
    return 0;
  }
  if (arg0 == 0)
  {
    new_var[1] = 0;
  }
  else
  {
    new_var[1] = arg0->cache->info;
  }
  remain = new_var[1]->size - arg0->f28;
  if (arg2 > remain)
  {
    arg2 = remain;
  }
  if ((arg0->f1c + arg2) > arg0->cache->total)
  {
    arg2 = arg0->cache->total - arg0->f1c;
    if (arg2 < remain)
    {
      return 0;
    }
  }
  if (((u32) (arg0->f20 + 0x10000)) == 0xFFFF)
  {
    r = fn_803E1414(((u8 *) arg0->cache) + 4, arg0->f24, 0, &arg0->f20);
    if (r != 0)
    {
      return r;
    }
    if (((u32) (arg0->f20 + 0x10000)) == 0xFFFF)
    {
      arg0->f1c = arg0->cache->total;
      if (arg0 == 0)
      {
        new_var[0] = 0;
      }
      else
      {
        new_var[0] = arg0->cache->info;
      }
      arg0->f24 = arg0->f1c >> new_var[0]->shift;
      arg0->f28 = arg0->f1c & (new_var[0]->size - 1);
      return 0x1C;
    }
    if ((arg0->f1c + arg2) > arg0->cache->total)
    {
      arg0->f1c = arg0->cache->total;
      if (arg0 == 0)
      {
        new_var[0] = 0;
      }
      else
      {
        new_var[0] = arg0->cache->info;
      }
      arg0->f24 = arg0->f1c >> new_var[0]->shift;
      arg0->f28 = arg0->f1c & (new_var[0]->size - 1);
      return 0x1B;
    }
  }
  new_var[1] = (Info *) PFSEC_ReadData(new_var[1], arg1, arg0->f20, arg0->f28, arg2, &sp8, 1);
  if ((((s32) new_var[1]) != 0) && (sp8 == 0))
  {
    return (s32) new_var[1];
  }
  *arg3 = sp8;
  fn_803E3614(arg0, sp8, arg0->f20);
  if (((u32) sp8) != arg2)
  {
    return (s32) new_var[1];
  }
  return 0;
}
