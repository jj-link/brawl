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
typedef enum 
{
  OS_ERR_SYSTEM_RESET,
  OS_ERR_MACHINE_CHECK,
  OS_ERR_DSI,
  OS_ERR_ISI,
  OS_ERR_EXT_INTERRUPT,
  OS_ERR_ALIGNMENT,
  OS_ERR_PROGRAM,
  OS_ERR_FP_UNAVAIL,
  OS_ERR_DECREMENTER,
  OS_ERR_SYSTEM_CALL,
  OS_ERR_TRACE,
  OS_ERR_PERF_MONITOR,
  OS_ERR_IABR,
  OS_ERR_SMI,
  OS_ERR_THERMAL_INT,
  OS_ERR_PROTECTION,
  OS_ERR_FP_EXCEPTION,
  OS_ERR_MAX
} OSErrorType;
typedef void (*OSErrorHandler)(u8 error, OSContext *ctx, u32 dsisr, u32 dar, ...);
extern OSErrorHandler __OSErrorTable[OS_ERR_MAX];
extern u32 __OSFpscrEnableBits;
void OSReport(const char *msg, ...) __attribute__((weak));
void OSPanic(const char *file, int line, const char *msg, ...) __attribute__((weak));
OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler);
void __OSUnhandledException(u8 error, OSContext *ctx, u32 dsisr, u32 dar);
extern s32 fn_803CC360(s32, s32, void *, s32);
extern void *fn_803D634C(void *, s32, u32);
extern char lbl_80493778[];
extern int lbl_80599680[];
inline static u16 max16(u16 a, u16 b)
{
  return (a >= b) ? (a) : (b);
}

inline static u16 min16(u16 a, u16 b)
{
  return (a <= b) ? (a) : (b);
}

inline int inline_fn(u32 arg0, int arg1)
{
  return arg0 * arg1;
}

s32 fn_803EED98(u32 *arg0, u16 *arg1)
{
  u32 buf[4];
  u32 pow2;
  u16 n;
  u16 v;
  u16 c;
  u16 pow1;
  u32 a;
  u32 product;
  if (lbl_80599680[4] == 0)
  {
    return 6;
  }
  fn_803D634C(buf, 0 & 0xFFFFFFFF, 0x10);
  if (fn_803CC360(lbl_80599680[2], 9, buf, 0x10) != 0)
  {
    OSReport(lbl_80493778);
    return 0x15;
  }
  a = ((buf[2] << 10) & 0xC00u) | (buf[1] >> 22);
  pow1 = (u16) (1 << (((buf[1] >> 7) & 7) + 2));
  product = inline_fn(a + 1, pow1);
  n = 8;
  n = (buf[2] >> n) & 0xF;
  v = max16(n, 9);
  c = min16(v, 0xB);
  c = c - 9;
  pow1 = 1;
  c = (pow1 <<= (u16) c);
  *arg0 = inline_fn(product, c);
  *arg1 = 0x200;
  return 0;
}
