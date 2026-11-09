typedef unsigned char bool;
typedef struct OSModuleHeader OSModuleHeader;
#include <revolution/OS/OSContext.h>
static void OSSaveFPUContext(OSContext*);
static void OSSetCurrentContext(OSContext*);
static OSContext* OSGetCurrentContext(void);
static BOOL OSSaveContext(OSContext*);
static void OSLoadContext(OSContext*);
static void* OSGetStackPointer(void);
static void OSSwitchFiber(void*, void*);
static void OSSwitchFiberEx(u32, u32, u32, u32, void*, void*);
static void OSDumpContext(const OSContext*);
static void __OSContextInit(void);
extern void fn_801D81F4(OSContext*);
static void dead_OSClearContext(OSContext*);
#include <revolution/BASE.h>
#include <revolution/DB.h>
#include <revolution/OS.h>
#define OSInitContext fn_801D8218
#define OSClearContext fn_801D81F4
#define fn_801D81F4(x) dead_OSClearContext(x)
#include "../src/revolution/OS/OSContext.c"
#pragma force_active on
