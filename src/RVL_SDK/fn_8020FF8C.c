
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
#pragma force_active on
extern s32 fn_8020EF2C(s32 *, s32, s32);
extern s32 lbl_804F5520[4];
s32 fn_8020FF8C(void)
{
  u32 value;
  u32 new_var[2];
  s32 temp_r29;
  if (fn_8020EF2C(&lbl_804F5520[0], 0x1008, 0x10) == 0)
  {
    goto fail;
  }
  value = lbl_804F5520[0];
  if ((value + 0x10000) == 0xffff)
  {
    goto fail;
  }
  if ((value & 0xFF000000) == 0)
  {
    goto fail;
  }
  if ((value & 0xFF000000) == 0xFF000000)
  {
    goto fail;
  }
  if ((value & 0xFF0000) == 0xFF0000)
  {
    goto fail;
  }
  new_var[1] = OSDisableInterrupts();
  temp_r29 = lbl_804F5520[0];
  if ((temp_r29 & 0xFF0000) == 0)
  {
    memset(&lbl_804F5520[0], 0, 0x1008);
    lbl_804F5520[0] = temp_r29;
  }
  OSRestoreInterrupts(new_var[1]);
  new_var[0] = 1;
  goto done;
  fail:
  new_var[0] = 0;

  done:
  if (new_var[0] != 0)
  {
    return lbl_804F5520[0];
  }

  return -1;
}
