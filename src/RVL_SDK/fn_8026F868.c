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
extern void *fn_801C0CA0(void *);
extern void fn_801C0D44(void *, int);
extern int fn_802049BC(int, int, int);
extern void *fn_80204E5C(void *, int);
extern void fn_80204E98(void *, int, int);
extern void fn_80278854(void *, void *, int);
extern int lbl_80532160[4];
extern OSMutex lbl_80532170;
extern char *lbl_805A0E80;
void fn_8026F868(int a, int b, int c)
{
  int *base;
  int *new_var;
  OSMutex **new_var3;
  OSMutex *m;
  char *s;
  void *r;
  char *new_var2;
  new_var = lbl_80532160;
  base = new_var;
  new_var3 = &m;
  fn_80204E98(base, fn_802049BC(b, c, 0), 0x20);
  s = (new_var2 = lbl_805A0E80);
  m = &lbl_80532170;
  OSLockMutex(*new_var3);
  r = fn_80204E5C(base, 0x150);
  if (r != 0)
  {
    if (r != 0)
    {
      r = fn_801C0CA0(r);
    }
    *((void **) (s + 0x5D8)) = r;
  }
  fn_801C0D44(*((void **) (s + 0x5D8)), a);
  fn_80278854(s, *((void **) (s + 0x5D8)), 0);
  OSUnlockMutex(*new_var3);
}
