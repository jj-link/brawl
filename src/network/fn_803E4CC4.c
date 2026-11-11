
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
typedef enum 
{
  PFCODE_FN_INVALID = 0,
  PFCODE_FN_VALID_LONG = 1 << 0,
  PFCODE_FN_VALID_SHORT = 1 << 1
} PFCODE_FnValidity;
typedef s32 (*PF_OEM_2_UNICODE)(char *src, u16 *dst);
typedef s32 (*PF_UNICODE_2_OEM)(u16 *src, char *dst);
typedef s32 (*PF_OEM_CHAR_WIDTH)(char *ch);
typedef s32 (*PF_UNICODE_CHAR_WIDH)(wchar_t *ch);
typedef u32 (*PF_IS_OEM_MB_CHAR)(char ch, u32 target);
typedef u32 (*PF_IS_UNICODE_MB_CHAR)(wchar_t ch, u32 target);
typedef struct 
{
  PF_OEM_2_UNICODE oem2unicode;
  PF_UNICODE_2_OEM unicode2oem;
  PF_OEM_CHAR_WIDTH oem_char_width;
  PF_IS_OEM_MB_CHAR is_oem_mb_char;
  PF_UNICODE_CHAR_WIDH unicode_char_width;
  PF_IS_UNICODE_MB_CHAR is_unicode_mb_char;
} PF_CHARCODE;
extern const u8 VFipf_valid_fn_char[0x80 - 0x20];
int VFiPFCODE_Combine_Width(s16 oem_width, s16 uni_width);
void VFiPFCODE_Divide_Width(u32 width, s16 *oem_width, s16 *uni_width);
typedef struct PF_VOLUME
{
  char _0x0[0x1640];
  u32 _0x1640;
  u32 _0x1644;
  char _0x1648[0x948];
  u32 _0x1f90;
  char _0x1f94[0x34];
} PF_VOLUME;
typedef struct PF_CUR_VOLUME
{
  u32 stat;
  s32 context_id;
  PF_VOLUME *p_vol;
} PF_CUR_VOLUME;
typedef struct PF_CONTEXT
{
  u32 stat;
  s32 context_id;
} PF_CONTEXT;
typedef struct PF_VOLUME_SET
{
  PF_CUR_VOLUME current_vol[1];
  s32 num_attached_drives;
  s32 num_mounted_volumes;
  u32 config;
  void *param;
  s32 last_error;
  s32 last_driver_error;
  PF_CHARCODE codeset;
  u32 setting;
  PF_CONTEXT context[1];
  PF_VOLUME volumes[26];
} PF_VOLUME_SET;
extern PF_VOLUME_SET VFipf_vol_set;
int PFFILE_p_remove(PF_VOLUME *vol, PF_STR *str);
int PFENT_ITER_GetEntryOfPath(PF_ENT_ITER *iter, PF_DIR_ENT *entry, PF_VOLUME *vol, PF_STR *str, int unk);
int PFENT_RemoveEntry(PF_DIR_ENT *entry, PF_ENT_ITER *iter);
int PFENT_getcurrentDateTimeForEnt(u16 *date, u16 *time);
int PFFAT_FreeChain(void *, u32, u32, u32);
int fn_803E7224(PF_STR *, PF_STR *, PF_STR *);
typedef struct 
{
  u32 a;
  u32 b;
  u32 c;
} Triple;
int PFFILE_p_remove(PF_VOLUME *vol, PF_STR *str)
{
  u8 *lp;
  PF_STR str1;
  PF_STR str2;
  PF_ENT_ITER iter;
  u16 new_var2;
  PF_DIR_ENT entry;
  Triple data;
  void *cache;
  u32 flags;
  u8 **new_var;
  u32 chain;
  int ret;
  int found;
  u32 i;
  ret = fn_803E7224(str, &str1, &str2);
  if (ret)
  {
    return ret;
  }
  ret = PFENT_ITER_GetEntryOfPath(&iter, &entry, vol, str, 0);
  if (ret)
  {
    return ret;
  }
  data = *((Triple *) iter.unk);
  if (((u8 *) (&entry))[0x21c] & 0x19)
  {
    return 0xb;
  }
  cache = entry.cache;
  new_var = &lp;
  lp = ((u8 *) cache) + 0x40;
  for (i = 0; i < 5; i++)
  {
    flags = *((u32 *) lp);
    new_var2 = *((u16 *) (((u8 *) (&entry)) + 0x23c));
    if (((((flags & 1) && (flags & 2)) && (cache == ((void *) (*((u32 *) ((*new_var) + 0x268)))))) && (((u32) entry.sector) == (*((u32 *) (lp + 0x274))))) && (new_var2 == (*((u16 *) (lp + 0x278)))))
    {
      found = 1;
      goto done;
    }
    lp += 0x29c;
  }

  found = 0;
  done:
  if (found)
  {
    return 0x13;
  }

  chain = *((u32 *) (((u8 *) (&entry)) + 0x234));
  iter.unk = &data;
  ret = PFENT_RemoveEntry(&entry, &iter);
  if (ret)
  {
    return ret;
  }
  return PFFAT_FreeChain(&iter._0x8, chain, -1, *((u32 *) (((u8 *) (&entry)) + 0x228)));
}
