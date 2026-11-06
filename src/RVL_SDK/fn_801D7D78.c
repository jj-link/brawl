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
static void OSClearContext(OSContext*);
static void OSInitContext(OSContext*, void*, void*);
static void OSDumpContext(const OSContext*);
static void __OSContextInit(void);
#pragma force_active on
void fn_801D7D78(UNKWORD, OSContext*);
static void __OSSaveFPUContext(UNKWORD, UNKWORD, OSContext*);
static void OSSwitchFPUContext(u8, OSContext*);
#define __OSLoadFPUContext fn_801D7D78
#include <revolution/BASE.h>
#include <revolution/DB.h>
#include <revolution/OS.h>
#define static
#include "../src/revolution/OS/OSContext.c"
#undef static
