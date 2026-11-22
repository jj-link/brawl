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
  OS_INTR_MEM_0,
  OS_INTR_MEM_1,
  OS_INTR_MEM_2,
  OS_INTR_MEM_3,
  OS_INTR_MEM_ADDRESS,
  OS_INTR_DSP_AI,
  OS_INTR_DSP_ARAM,
  OS_INTR_DSP_DSP,
  OS_INTR_AI_AI,
  OS_INTR_EXI_0_EXI,
  OS_INTR_EXI_0_TC,
  OS_INTR_EXI_0_EXT,
  OS_INTR_EXI_1_EXI,
  OS_INTR_EXI_1_TC,
  OS_INTR_EXI_1_EXT,
  OS_INTR_EXI_2_EXI,
  OS_INTR_EXI_2_TC,
  OS_INTR_PI_CP,
  OS_INTR_PI_PE_TOKEN,
  OS_INTR_PI_PE_FINISH,
  OS_INTR_PI_SI,
  OS_INTR_PI_DI,
  OS_INTR_PI_RSW,
  OS_INTR_PI_ERROR,
  OS_INTR_PI_VI,
  OS_INTR_PI_DEBUG,
  OS_INTR_PI_HSP,
  OS_INTR_PI_ACR,
  OS_INTR_28,
  OS_INTR_29,
  OS_INTR_30,
  OS_INTR_31,
  OS_INTR_MAX
} OSInterruptType;
typedef void (*OSInterruptHandler)(s16 intr, OSContext *ctx);
extern u32 __OSLastInterruptSrr0;
extern s16 __OSLastInterrupt;
extern s64 __OSLastInterruptTime;
BOOL OSDisableInterrupts(void);
BOOL OSEnableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL status);
OSInterruptHandler __OSSetInterruptHandler(OSInterruptType type, OSInterruptHandler handler);
OSInterruptHandler __OSGetInterruptHandler(OSInterruptType type);
void __OSInterruptInit(void);
u32 __OSMaskInterrupts(u32 userMask);
u32 __OSUnmaskInterrupts(u32 userMask);
void __OSDispatchInterrupt(u8 intr, OSContext *ctx);
void __RAS_OSDisableInterrupts_begin(void);
void __RAS_OSDisableInterrupts_end(void);
int stricmp(const char *, const char *);
char *itoa(int value, char *str, int base);
void *memcpy(void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memfill(const void *, int, size_t);
void *__memfill(const void *, int, size_t);
void *memmove(void *, const void *, size_t);
void *memchr(const void *, int, size_t);
void *__memrchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
char *strcat(char *, const char *);
char *strncat(char *, const char *, size_t);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
char *strchr(const char *, int);
char *strstr(const char *, const char *);
size_t strlen(const char *);
#pragma opt_propagation off
s32 fn_8020E740(u8 *conf, u32 size);
extern u8 lbl_804ED380[];
extern u8 lbl_804ED520[];
extern char lbl_8059EC78[5];
extern char lbl_8059EC80[5];
extern u8 lbl_805A0BB8;
extern s8 lbl_805A0BCD;
u8 fn_8020E18C(void)
{
  u8 *p;
  u32 size;
  s32 new_var;
  s32 irq;
  u8 result;
  BOOL initial;
  size = 0x4000;
  initial = OSDisableInterrupts();
  result = lbl_805A0BB8;
  if (result == 3)
  {
    lbl_805A0BB8 = 1;
    OSRestoreInterrupts(initial);
    if (fn_8020E740(*((u8 **) (lbl_804ED380 + 0x16C)), *((u32 *) (lbl_804ED380 + 0x17C))) == 0)
    {
      irq = OSDisableInterrupts();
      p = *((u8 **) (lbl_804ED380 + 0x16C));
      if (lbl_804ED520 != p)
      {
        memcpy(lbl_804ED520, p, 0x4000);
      }
      lbl_805A0BCD = 0;
      OSRestoreInterrupts(irq);
    }
    else
    {
      irq = OSDisableInterrupts();
      new_var = irq;
      p = *((u8 **) (lbl_804ED380 + 0x16C));
      size = 0x4000;
      memset(p, 0, size);
      if (size > 0xC)
      {
        memcpy(p, lbl_8059EC78, 4);
        memcpy(p + 0x3FFC, lbl_8059EC80, 4);
        *((s16 *) (p + 6)) = 8;
      }
      lbl_805A0BCD = 0;
      OSRestoreInterrupts(new_var);
    }
    result = 0;
    lbl_805A0BB8 = 0;
  }
  else
  {
    OSRestoreInterrupts(initial);
  }
  return result;
}
