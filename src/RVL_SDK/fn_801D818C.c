typedef unsigned char bool;
typedef struct OSModuleHeader OSModuleHeader;
#include <revolution/OS/OSContext.h>
static void OSSaveFPUContext(OSContext*);
static void OSSetCurrentContext(OSContext*);
static OSContext* OSGetCurrentContext(void);
static BOOL OSSaveContext(OSContext*);
static void OSLoadContext(OSContext*);
static void OSSwitchFiber(void*, void*);
static void OSSwitchFiberEx(u32, u32, u32, u32, void*, void*);
static void OSClearContext(OSContext*);
static void OSInitContext(OSContext*, void*, void*);
static void OSDumpContext(const OSContext*);
static void __OSContextInit(void);
#include "../src/revolution/OS/OSContext.c"
#pragma force_active on
