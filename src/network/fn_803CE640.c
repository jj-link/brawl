
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
typedef struct 
{
  char pad[0x1b40];
  int state;
  int unused;
  int error;
} State;
typedef struct 
{
  void (*fn)(void);
  void *buf;
  unsigned int size;
  char pad[0x45 - 0x0c];
  unsigned char unk45;
  unsigned char unk46;
  unsigned char unk47;
  char pad2[0x1d8 - 0x48];
  unsigned char unk1d8;
} Entry;
extern int fn_8020B8A0(int);
extern Entry *fn_803CD3B4(int);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern void fn_8020B898(void *, void *);
extern int fn_8020A7F8(void *, int, int, void (*)(void), void *);
extern void fn_803CE924(void);
void fn_803CE640(int arg0, int arg1)
{
  int notify;
  Entry *entry;
  void *buf;
  int *info;
  notify = 1;
  arg1 = *((unsigned int *) (((char *) fn_8020B8A0(arg1)) + 4));
  entry = fn_803CD3B4(arg1);
  switch (arg0)
  {
    case 0:
      entry->unk1d8 = 1;
      switch (fn_803CD324()->state)
    {
      case 0:

      case 6:
      {
        BOOL enabled = OSDisableInterrupts();
        fn_803CD318(0);
        fn_803CD324()->state = 0;
        fn_803CD324()->error = 0;
        OSRestoreInterrupts(enabled);
        break;
      }

    }

      break;

    case -1:

    case -3:

    case -4:

    case -5:

    case -9:

    case -10:

    case -11:

    case -15:
      entry->unk1d8 = 0;
      switch (fn_803CD324()->state)
    {
      case 0:

      case 6:
      {
        BOOL enabled = OSDisableInterrupts();
        fn_803CD318(0);
        fn_803CD324()->state = 2;
        fn_803CD324()->error = arg0;
        OSRestoreInterrupts(enabled);
        break;
      }

    }

      break;

    case -12:
      entry->unk1d8 = 0;
      if (entry->unk45 == 1)
    {
      switch (fn_803CD324()->state)
      {
        case 0:

        case 6:
        {
          BOOL enabled = OSDisableInterrupts();
          fn_803CD318(0);
          fn_803CD324()->state = 2;
          fn_803CD324()->error = arg0;
          OSRestoreInterrupts(enabled);
          break;
        }

      }

    }
    else
    {
      int result;
      buf = ((char *) fn_803CD3B4(arg1)) + 0xd4;
      info = (int *) (((char *) fn_803CD3B4(arg1)) + 0x18c);
      info[0] = 10;
      info[1] = arg1;
      fn_8020B898(buf, info);
      result = fn_8020A7F8(&entry->buf, entry->unk46, entry->unk47, fn_803CE924, buf);
      switch (result)
      {
        case 0:
          notify = 0;
          break;

        default:
          switch (fn_803CD324()->state)
        {
          case 0:

          case 6:
          {
            BOOL enabled = OSDisableInterrupts();
            fn_803CD318(0);
            fn_803CD324()->state = 2;
            fn_803CD324()->error = result;
            OSRestoreInterrupts(enabled);
            break;
          }

        }

          break;

      }

    }
      break;

    case -2:

    case -8:

    case -64:

    case -128:

    default:
      entry->unk1d8 = 0;
      switch (fn_803CD324()->state)
    {
      case 0:

      case 6:
      {
        BOOL enabled = OSDisableInterrupts();
        fn_803CD318(0);
        fn_803CD324()->state = 5;
        fn_803CD324()->error = arg0;
        OSRestoreInterrupts(enabled);
        break;
      }

    }

      break;

  }

  if (notify != 0)
  {
    if (entry->fn != 0)
    {
      entry->fn();
    }
  }
}
