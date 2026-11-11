
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
int PFENT_ITER_GetEntryOfPath(PF_ENT_ITER *iter, PF_DIR_ENT *entry, PF_VOLUME *vol, PF_STR *str, int unk);
#pragma force_active on
s32 fn_803DBA3C(void *vol, PF_STR *str, void *out)
{
  PF_ENT_ITER iter;
  PF_DIR_ENT entry;
  u8 *p;
  unsigned short new_var2;
  s32 result;
  s32 i;
  u8 **new_var;
  u32 flags;
  u8 *elem;
  u8 *dst;
  i = 0;
  result = PFENT_ITER_GetEntryOfPath(&iter, &entry, vol, str, 0);
  if (result != 0)
  {
    return result;
  }
  if ((*((s32 *) (((u8 *) vol) + 0x161C))) != 0)
  {
    p = (u8 *) vol;
    for (i = 0; i != 5; i++)
    {
      new_var2 = *((u16 *) (((u8 *) (&entry)) + 0x23C));
      new_var = &p;
      flags = *((u32 *) ((*new_var) + 0x40));
      if (((((flags & 1) && (flags & 2)) && (((u32) entry.cache) == (*((u32 *) (p + 0x2A8))))) && (((u32) entry.sector) == (*((u32 *) ((*new_var) + 0x2B4))))) && (new_var2 == (*((u16 *) (p + 0x2B8)))))
      {
        elem = ((u8 *) vol) + (i * 0x29C);
        dst = (u8 *) out;
        *((u32 *) dst) = *((u32 *) (elem + 0x2A4));
        *((u8 *) (dst + 0x10)) = *((u8 *) (elem + 0x298));
        *((u16 *) (dst + 0x6)) = *((u16 *) (elem + 0x2A0));
        *((u16 *) (dst + 0x8)) = *((u16 *) (elem + 0x2A2));
        *((u16 *) (dst + 0x4)) = *((u16 *) (elem + 0x29E));
        *((u16 *) (dst + 0xA)) = *((u16 *) (elem + 0x29A));
        *((u16 *) (dst + 0xC)) = *((u16 *) (elem + 0x29C));
        *((u16 *) (dst + 0xE)) = *((u8 *) (elem + 0x299));
        break;
      }
      p += 0x29C;
    }

  }
  if (((*((s32 *) (((u8 *) vol) + 0x161C))) == 0) || (i == 5))
  {
    dst = (u8 *) out;
    if ((*((u8 *) (((u8 *) (&entry)) + 0x21C))) & 0x10)
    {
      *((u32 *) dst) = 0;
    }
    else
    {
      *((u32 *) dst) = entry._0x228;
    }
    *((u8 *) (dst + 0x10)) = *((u8 *) (((u8 *) (&entry)) + 0x21C));
    *((u16 *) (dst + 0x6)) = *((u16 *) (((u8 *) (&entry)) + 0x224));
    *((u16 *) (dst + 0x8)) = *((u16 *) (((u8 *) (&entry)) + 0x226));
    *((u16 *) (dst + 0x4)) = *((u16 *) (((u8 *) (&entry)) + 0x222));
    *((u16 *) (dst + 0xA)) = *((u16 *) (((u8 *) (&entry)) + 0x21E));
    *((u16 *) (dst + 0xC)) = *((u16 *) (((u8 *) (&entry)) + 0x220));
    *((u16 *) (dst + 0xE)) = *((u8 *) (((u8 *) (&entry)) + 0x21D));
  }
  return 0;
}
