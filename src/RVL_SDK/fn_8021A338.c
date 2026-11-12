
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
typedef void (*Callback)(int, int);
typedef struct Msg
{
  int type;
  int a;
  int b;
  int c;
  int d;
  int e;
  short f;
  short g;
  int h;
  int i;
  int j;
  int k;
  Callback cb;
} Msg;
typedef struct State
{
  char pad[0x160];
  s8 head;
  s8 tail;
  char pad2[2];
  void *buf;
  int size;
  char pad3[0x750];
  int status;
  char pad4[0x1c];
  int active;
  char pad5[0xa8];
  Callback cb;
  u8 flag;
} State;
extern State *lbl_804F6810[];
extern void fn_8021A2E4(int, int);
int fn_8021A338(int index, int value, Callback callback)
{
  int cnt;
  int result;
  u8 flag;
  State *state;
  state = lbl_804F6810[index];
  {
    int enabled = OSDisableInterrupts();
    cnt = state->active;
    result = state->status;
    flag = state->flag;
    OSRestoreInterrupts(enabled);
  }
  if (result != (-1))
  {
    if ((cnt == 0) || (flag != 0))
    {
      result = -2;
    }
    else
    {
      Msg out;
      Msg m;
      int ok;
      s8 diff;
      int enabled;
      enabled = OSDisableInterrupts();
      state->flag = 1;
      state->cb = callback;
      OSRestoreInterrupts(enabled);
      m.type = 0x15;
      m.g = 1;
      *((u8 *) (&m.a)) = 0;
      m.cb = fn_8021A2E4;
      m.k = value;
      out = m;
      enabled = OSDisableInterrupts();
      {
        int en2 = OSDisableInterrupts();
        diff = state->head;
        diff = state->tail - diff;
        if (diff < 0)
        {
          diff += state->size;
        }
        OSRestoreInterrupts(en2);
      }
      if (((u32) (state->size - 1)) == ((u32) diff))
      {
        OSRestoreInterrupts(enabled);
        ok = 0;
      }
      else
      {
        memset(((char *) state->buf) + (state->tail * 0x30), 0, 0x30);
        memcpy(((char *) state->buf) + (state->tail * 0x30), &out, 0x30);
        {
          int n = state->size - 1;
          state->tail = (state->tail == n) ? (0) : (state->tail + 1);
        }
        OSRestoreInterrupts(enabled);
        ok = 1;
      }
      if (ok != 0)
      {
        result = 0;
      }
      else
      {
        result = -2;
        enabled = OSDisableInterrupts();
        state->flag = 0;
        state->cb = 0;
        OSRestoreInterrupts(enabled);
      }
    }
  }
  if (result && callback)
  {
    callback(index, result);
  }
  return result;
}
