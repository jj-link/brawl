
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
  OS_CONTEXT_STATE_FP_SAVED = 1 << 0
} OSContextState;
typedef struct OSContext
{
  u32 gprs[32];
  u32 cr;
  u32 lr;
  u32 ctr;
  u32 xer;
  f64 fprs[32];
  u32 fpscr_pad;
  u32 fpscr;
  u32 srr0;
  u32 srr1;
  u16 mode;
  u16 state;
  u32 gqrs[8];
  u32 psf_pad;
  f64 psfs[32];
} OSContext;
void OSSaveFPUContext(OSContext *ctx);
void OSSetCurrentContext(OSContext *ctx);
OSContext *OSGetCurrentContext(void);
BOOL OSSaveContext(OSContext *ctx);
void OSLoadContext(OSContext *ctx);
void *OSGetStackPointer(void);
void OSSwitchFiber(void *func, void *stack);
void OSSwitchFiberEx(u32 r3, u32 r4, u32 r5, u32 r6, void *func, void *stack);
void OSClearContext(OSContext *ctx);
void OSInitContext(OSContext *ctx, void *_srr0, void *stack);
void OSDumpContext(const OSContext *ctx);
void __OSContextInit(void);
typedef enum 
{
  OS_THREAD_STATE_EXITED = 0,
  OS_THREAD_STATE_READY = 1,
  OS_THREAD_STATE_RUNNING = 2,
  OS_THREAD_STATE_SLEEPING = 4,
  OS_THREAD_STATE_MORIBUND = 8
} OSThreadState;
typedef enum 
{
  OS_THREAD_DETACHED = 1 << 0
} OSThreadFlag;
typedef struct OSThreadQueue
{
  struct OSThread *head;
  struct OSThread *tail;
} OSThreadQueue;
typedef struct OSMutexQueue
{
  struct OSMutex *head;
  struct OSMutex *tail;
} OSMutexQueue;
typedef struct OSThread
{
  OSContext context;
  u16 state;
  u16 flags;
  s32 suspend;
  s32 priority;
  s32 base;
  u32 val;
  OSThreadQueue *queue;
  struct OSThread *next;
  struct OSThread *prev;
  OSThreadQueue joinQueue;
  struct OSMutex *mutex;
  OSMutexQueue mutexQueue;
  struct OSThread *nextActive;
  struct OSThread *prevActive;
  u32 *stackBegin;
  u32 *stackEnd;
  s32 error;
  void *specific[2];
} OSThread;
typedef void (*OSSwitchThreadCallback)(OSThread *currThread, OSThread *newThread);
typedef void *(*OSThreadFunc)(void *arg);
OSSwitchThreadCallback OSSetSwitchThreadCallback(OSSwitchThreadCallback callback);
void __OSThreadInit(void);
void OSSetCurrentThread(OSThread *thread);
void OSInitMutexQueue(OSMutexQueue *queue);
void OSInitThreadQueue(OSThreadQueue *queue);
OSThread *OSGetCurrentThread(void);
BOOL OSIsThreadTerminated(OSThread *thread);
s32 OSDisableScheduler(void);
s32 OSEnableScheduler(void);
s32 __OSGetEffectivePriority(OSThread *thread);
void __OSPromoteThread(OSThread *thread, s32 prio);
void __OSReschedule(void);
void OSYieldThread(void);
BOOL OSCreateThread(OSThread *thread, OSThreadFunc func, void *funcArg, void *stackBegin, u32 stackSize, s32 prio, u16 flags);
void OSExitThread(OSThread *thread);
void OSCancelThread(OSThread *thread);
BOOL OSJoinThread(OSThread *thread, void *val);
void OSDetachThread(OSThread *thread);
s32 OSResumeThread(OSThread *thread);
s32 OSSuspendThread(OSThread *thread);
void OSSleepThread(OSThreadQueue *queue);
void OSWakeupThread(OSThreadQueue *queue);
BOOL OSSetThreadPriority(OSThread *thread, s32 prio);
void OSClearStack(u8 val);
void OSSleepTicks(s64 ticks);
typedef struct OSMutex
{
  OSThreadQueue queue;
  OSThread *thread;
  s32 lock;
  struct OSMutex *next;
  struct OSMutex *prev;
} OSMutex;
typedef struct OSCond
{
  OSThreadQueue queue;
} OSCond;
void OSInitMutex(OSMutex *mutex);
void OSLockMutex(OSMutex *mutex);
void OSUnlockMutex(OSMutex *mutex);
void __OSUnlockAllMutex(OSThread *thread);
BOOL OSTryLockMutex(OSMutex *mutex);
void OSInitCond(OSCond *cond);
void OSWaitCond(OSCond *cond, OSMutex *mutex);
void OSSignalCond(OSCond *cond);
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
extern int lbl_805A06F4;
extern void fn_801E07D8(OSThread *);
extern OSThread *fn_801E087C(OSThread *, int);
extern void fn_801E0A80(int);
s32 OSSuspendThread(OSThread *thread)
{
  OSMutex *mutex;
  OSThread *next;
  OSThread *prev;
  OSThread *owner;
  OSThread *waiting;
  OSThread *tail;
  s32 enabled;
  int priority;
  int old;
  enabled = OSDisableInterrupts();
  old = thread->suspend;
  thread->suspend = old + 1;
  if (old == 0)
  {
    switch (thread->state)
    {
      case 2:
        lbl_805A06F4 = 1;
        thread->state = 1;
        break;

      case 1:
        fn_801E07D8(thread);
        break;

      case 3:
        break;

      case 4:
        next = thread->next;
        prev = thread->prev;
        if (next == 0)
      {
        thread->queue->tail = prev;
      }
      else
      {
        next->prev = prev;
      }
        if (prev == 0)
      {
        thread->queue->head = next;
      }
      else
      {
        prev->next = next;
      }
        thread->priority = 32;
        tail = thread->queue->tail;
        if (tail == 0)
      {
        thread->queue->head = thread;
      }
      else
      {
        tail->next = thread;
      }
        thread->prev = tail;
        thread->next = 0;
        thread->queue->tail = thread;
        if (thread->mutex != 0)
      {
        owner = thread->mutex->thread;
        do
        {
          if (owner->suspend > 0)
          {
            break;
          }
          priority = owner->base;
          for (mutex = owner->mutexQueue.head; mutex != 0; mutex = mutex->next)
          {
            waiting = mutex->queue.head;
            if ((waiting != 0) && (waiting->priority < priority))
            {
              priority = waiting->priority;
            }
          }

          if (owner->priority == priority)
          {
            break;
          }
          owner = fn_801E087C(owner, priority);
        }
        while (owner != 0);
      }
        break;

      default:
        break;

    }

    if (lbl_805A06F4)
    {
      fn_801E0A80(0);
    }
  }
  OSRestoreInterrupts(enabled);
  return old;
}
