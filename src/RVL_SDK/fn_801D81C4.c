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
static void OSClearContext(OSContext*);
static void OSInitContext(OSContext*, void*, void*);
static void OSDumpContext(const OSContext*);
static void __OSContextInit(void);
#include <revolution/BASE.h>
#include <revolution/DB.h>
#include <revolution/OS.h>
#define OSSwitchFiberEx fn_801D81C4
#include "../src/revolution/OS/OSContext.c"
#pragma force_active on
