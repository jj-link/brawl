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
typedef struct OSContext OSContext;
void DCEnable(void);
void DCInvalidateRange(const void *buf, u32 len);
void DCFlushRange(const void *buf, u32 len);
void DCStoreRange(const void *buf, u32 len);
void DCFlushRangeNoSync(const void *buf, u32 len);
void DCStoreRangeNoSync(const void *buf, u32 len);
void DCZeroRange(const void *buf, u32 len);
void ICInvalidateRange(const void *buf, u32 len);
void ICFlashInvalidate(void);
void ICEnable(void);
void LCEnable(void);
void LCDisable(void);
void LCLoadBlocks(void *dst, const void *src, u32 blocks);
void LCStoreBlocks(void *dst, const void *src, u32 blocks);
u32 LCStoreData(void *dst, const void *src, u32 len);
u32 LCQueueLength(void);
void LCQueueWait(u32 n);
void L2Enable(void);
void L2Disable(void);
void L2GlobalInvalidate(void);
void DMAErrorHandler(u8 error, OSContext *ctx, u32 dsisr, u32 dar, ...);
void __OSCacheInit(void);
extern void fn_801FF41C(unsigned int *);
extern u8 *lbl_805A0B28;
extern u8 *lbl_805A0B2C;
extern u8 *lbl_805A0B30;
extern u32 lbl_805A0B34;
extern u32 lbl_805A0B3C;
extern u32 lbl_805A0B40;
void fn_80201F7C(void)
{
  u32 n;
  u32 *dst;
  u32 one;
  u32 value;
  u32 off27;
  u32 off26;
  u32 off25;
  u32 i;
  lbl_805A0B40 = (*((u32 *) 0x800000F8)) / 667;
  lbl_805A0B3C = 0;
  for (dst = (u32 *) lbl_805A0B28, n = lbl_805A0B34 * 0x50; n > 0; n--)
  {
    *(dst++) = 0;
  }

  for (dst = (u32 *) lbl_805A0B2C, n = lbl_805A0B34 * 0x10; n > 0; n--)
  {
    *(dst++) = 0;
  }

  for (n = lbl_805A0B34 * 0x5A, off25 = 0, dst = (u32 *) lbl_805A0B30; n > 0; n--)
  {
    *(dst++) = off25;
  }

  i = off25;
  one = 1;
  off27 = 0;
  off26 = 0;
  off25 = 0;
  value = 0x18A80024;
  for (; i < lbl_805A0B34; i++)
  {
    u8 *pb = lbl_805A0B28 + off27;
    u8 *itd = lbl_805A0B2C + off26;
    u8 *vpb = lbl_805A0B30 + off25;
    *((u32 *) (vpb + 0x18)) = i;
    *((u32 *) (vpb + 0x24)) = (u32) itd;
    *((u16 *) (vpb + 0x38)) = 0;
    *((u16 *) (vpb + 0x6C)) = 0;
    *((u32 *) (vpb + 0x1C)) = value;
    *((u16 *) (vpb + 0xE2)) = 0;
    *((u16 *) (vpb + 0xEA)) = 0;
    *((u16 *) (vpb + 0xFE)) = 0;
    *((u16 *) (vpb + 0x13C)) = 0;
    *((u16 *) (vpb + 0x132)) = 0;
    *((u16 *) (vpb + 0x134)) = 0;
    *((u16 *) (vpb + 0x136)) = 0;
    *((u16 *) (vpb + 0x138)) = 0;
    *((u16 *) (vpb + 0x13A)) = 0;
    if (i == (lbl_805A0B34 - 1))
    {
      *((u16 *) (pb + 2)) = 0;
      *((u16 *) (pb + 0)) = 0;
      *((u16 *) (vpb + 0x2A)) = 0;
      *((u16 *) (vpb + 0x28)) = 0;
    }
    else
    {
      *((u16 *) (vpb + 0x28)) = (((u32) pb) + 0x140) >> 16;
      *((u16 *) (vpb + 0x2A)) = ((u32) pb) + 0x140;
      *((u16 *) (pb + 0)) = (((u32) pb) + 0x140) >> 16;
      *((u16 *) (pb + 2)) = ((u32) pb) + 0x140;
    }
    *((u16 *) (vpb + 0x2C)) = ((u32) pb) >> 16;
    *((u16 *) (vpb + 0x2E)) = (u32) pb;
    *((u16 *) (pb + 4)) = ((u32) pb) >> 16;
    *((u16 *) (pb + 6)) = (u32) pb;
    *((u16 *) (vpb + 0x6E)) = ((u32) itd) >> 16;
    *((u16 *) (vpb + 0x70)) = (u32) itd;
    *((u16 *) (pb + 0x46)) = ((u32) itd) >> 16;
    *((u16 *) (pb + 0x48)) = (u32) itd;
    *((u32 *) (vpb + 0x0C)) = one;
    fn_801FF41C((unsigned int *) vpb);
    off27 += 0x140;
    off26 += 0x40;
    off25 += 0x168;
  }

  DCFlushRange(lbl_805A0B28, lbl_805A0B34 * 0x140);
}
