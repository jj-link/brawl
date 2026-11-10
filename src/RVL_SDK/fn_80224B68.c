
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
#pragma force_active on
typedef struct Entry
{
  unsigned int active;
  unsigned int address;
  unsigned short remaining;
  unsigned short pad;
  unsigned int offset;
  void (*callback)(int, int);
} Entry;
typedef struct State
{
  unsigned char pad[0x38];
  int f38;
  int f3C;
} State;
extern State *lbl_804F6810[];
extern Entry lbl_804F9F70[];
void fn_802249F8(int, int);
extern void fn_802252E8(int, unsigned int, unsigned short, unsigned int, void (*)(int, int));
void fn_80224B68(int idx, int arg)
{
  if (lbl_804F6810[idx]->f3C == 0)
  {
    lbl_804F6810[idx]->f3C = (arg == 0) ? (0) : (-3);
  }
  if (arg == 0)
  {
    if ((lbl_804F6810[idx]->f38 == 0) || (lbl_804F6810[idx]->f3C == 0))
    {
      BOOL enabled;
      unsigned short count = (unsigned short) ((lbl_804F9F70[idx].remaining > 16) ? (16) : (lbl_804F9F70[idx].remaining));
      lbl_804F9F70[idx].remaining -= count;
      enabled = (0, OSDisableInterrupts());
      fn_802252E8(idx, lbl_804F9F70[idx].address, count, lbl_804F9F70[idx].offset, fn_802249F8);
      OSRestoreInterrupts(enabled);
      return;
    }
    arg = -3;
  }
  if (lbl_804F9F70[idx].callback != 0)
  {
    lbl_804F9F70[idx].active = 0;
    lbl_804F9F70[idx].callback(idx, arg);
    lbl_804F9F70[idx].callback = 0;
  }
}
