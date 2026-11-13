
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
typedef struct OSSram
{
  u16 checksum;
  u16 invchecksum;
  u32 ead0;
  u32 ead1;
  u32 counterBias;
  u8 dispOfsH;
  u8 ntd;
  u8 lang;
  u8 flags;
} OSSram;
typedef struct OSSramEx
{
  char UNK_0x0[0x1C];
  u16 wirelessPadId[4];
  char UNK_0x38[0x3C - 0x38];
  u16 gbs;
  char UNK_0x3E[0x40 - 0x3E];
} OSSramEx;
void __OSInitSram(void);
OSSramEx *__OSLockSramEx(void);
BOOL __OSUnlockSramEx(BOOL save);
BOOL __OSSyncSram(void);
BOOL __OSReadROM(void *dst, s32 size, const void *src);
u16 OSGetWirelessID(s32 pad);
void OSSetWirelessID(s32 pad, u16 id);
u16 OSGetGbsMode(void);
void OSSetGbsMode(u16 gbs);
BOOL __OSGetRTCFlags(u32 *out);
BOOL __OSClearRTCFlags(void);
typedef struct 
{
  union 
  {
    struct 
    {
      OSSram sram;
      OSSramEx sramEx;
    };
    u8 block[0x40];
  };
  u32 pos;
  BOOL enabled;
  BOOL locked;
  BOOL sync;
  u32 word50;
} OSScb;
extern OSScb lbl_804DD500;
extern void fn_801DF848(void);
extern s32 fn_801E42E4(s32, void *, s32, s32, s32);
extern s32 fn_801E4560(s32, void *, s32, s32);
extern s32 fn_801E46FC(s32);
extern s32 fn_801E4D4C(s32, s32, s32);
extern s32 fn_801E4E7C(s32);
extern s32 fn_801E54E0(s32, s32, void (*)(void));
extern void fn_801E55DC(s32);
s32 fn_801DFB80(s32 save, u32 pos)
{
  u16 *data;
  OSSram *sram;
  OSSramEx *sramEx;
  u32 p;
  OSSramEx **new_var;
  void *buffer;
  s32 size;
  u32 imm;
  s32 err;
  s32 err2;
  BOOL result;
  if (save)
  {
    if (pos == 0)
    {
      sram = &lbl_804DD500.sram;
      if (((u8) (sram->flags & 0x3)) > 2)
      {
        sram->flags &= ~0x3;
      }
      sram->invchecksum = 0;
      sram->checksum = 0;
      for (data = (u16 *) (&sram->counterBias); ((u8 *) data) < ((u8 *) (&lbl_804DD500.sramEx)); data++)
      {
        sram->checksum += *data;
        sram->invchecksum += ~(*data);
      }

    }
    if (pos < lbl_804DD500.pos)
    {
      lbl_804DD500.pos = pos;
    }
    new_var = &sramEx;
    if (lbl_804DD500.pos <= 0x14)
    {
      sramEx = &lbl_804DD500.sramEx;
      if (((((u32) (*new_var)->gbs) & 0x7C00) == 0x5000) || ((((u32) sramEx->gbs) & 0xC0) == 0xC0))
      {
        sramEx->gbs = 0;
      }
    }
    p = lbl_804DD500.pos;
    size = 0x40 - p;
    buffer = lbl_804DD500.block + p;
    if (!fn_801E54E0(0, 1, fn_801DF848))
    {
      result = 0;
    }
    else
      if (!fn_801E4D4C(0, 1, 3))
    {
      fn_801E55DC(0);
      result = 0;
    }
    else
    {
      imm = ((p * 0x40) + 0x100) | 0xA0000000;
      err = fn_801E42E4(0, &imm, 4, 1, 0) == 0;
      err2 = err | (fn_801E46FC(0) == 0);
      err2 |= fn_801E4560(0, buffer, size, 1) == 0;
      err2 |= fn_801E4E7C(0) == 0;
      fn_801E55DC(0);
      result = !err2;
    }
    lbl_804DD500.sync = result;
    if (result)
    {
      lbl_804DD500.pos = 0x40;
    }
  }
  lbl_804DD500.locked = 0;
  OSRestoreInterrupts(lbl_804DD500.enabled);
  return lbl_804DD500.sync;
}
