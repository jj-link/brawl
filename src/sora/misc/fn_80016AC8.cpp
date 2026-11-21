#include <gf/gf_application.h>
#include <gf/gf_thread.h>
#include <gf/gf_shutdown_manager.h>
#include <gf/gf_error_manager.h>
#include <gf/gf_error_check.h>
#include <gf/gf_archive_manager.h>
#include <gf/gf_task_scheduler.h>
#include <gf/gf_copyefb.h>
#include <ip/ip_switch.h>
#include <nt/nt_offline.h>
#include <mt/mt_prng.h>
#include <snd/snd_system.h>
#include <revolution/OS/OS.h>
#include <revolution/VI.h>
#include <string.h>

#pragma force_active on

extern "C" {
void fn_801E83E4(void);
void fn_801F6A90(void);
void fn_8020CDB8(void);
void fn_8020A37C(void);
void fn_8020E0EC(void);
void fn_801B59D4(int);
void fn_80038254(void*);
int fn_801D714C(void);
void fn_801D717C(int, unsigned short);
void fn_8002395C(void*, int, unsigned int, unsigned int, int);
void fn_80023AD0(void*, unsigned int, int, int, int);
void fn_801E8DC8(void*);
void fn_801E98B0(void);
void fn_801D7154(void);
void fn_801D713C(void);
int fn_801D7144(void);
int fn_801D712C(void);
int fn_801D7134(void);
void fn_800242DC(void);
void fn_800244C4(void*);
void fn_80022A90(void);
void fn_80026B14(void);
void fn_80022DE4(void);
void fn_803F8C5C(int);
void fn_80072968(void);
void fn_80073184(void*);
void fn_8004C1A4(void);
void fn_8000C960(void);
void fn_8009BE1C(void);
void fn_8005AD04(void);
void fn_8005E5E8(int, int, int);
void fn_80078600(void);
void fn_80158BE0(void);
void fn_8015919C(void);
void fn_800367C8(void);
void fn_8002FDF4(void);
void fn_8014734C(void);
void fn_80017A40(int);
unsigned int fn_801DF7FC(void);
int fn_801E0714(void);
void* fn_80016938(void*);
void* create__14gfSceneManagerFv(void);
void* __nw__FUlQ25Heaps8HeapType(unsigned int, int);
void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(void*, void*, unsigned int, unsigned int, int);
void* getInstance__11ipPadConfigFv(void);
void* fn_80019F60(void);
void initilize__17gfShutdownManagerFv(void*);
extern char __vt__8gfThread[];
extern char __vt__15gfMonitorThread[];
extern char lbl_80421788[];
extern char lbl_80421890[];
extern char lbl_804953A0[];
extern char lbl_804976D8[];
extern void* lbl_8059FFB0;
}

static inline void fillArena(int end, int start) { memset((void*)start, 0xcc, end - start); }

void gfApplication::init()
{
    unsigned char* p = (unsigned char*)this;
    struct Bits { unsigned char b0:1; unsigned char b1:1; unsigned char b2:1; unsigned char b3:1; unsigned char b4:1; unsigned char b5:1; unsigned char b6:1; unsigned char b7:1; };
    Bits& a = *(Bits*)(p + 0xed);
    Bits& b = *(Bits*)(p + 0xee);
    a.b6 = 0;
    b.b2 = 0;
    b.b5 = 0;
    b.b3 = 0;

    OSInit();
    fn_801E83E4();
    fn_801F6A90();
    fn_8020CDB8();
    fn_8020A37C();
    fn_8020E0EC();
    fn_801B59D4(1);
    fn_80038254(this);

    unsigned int h;
    unsigned int w;
    w = (unsigned int)(float)*(unsigned short*)(p + 0x40);
    h = (unsigned int)(float)*(unsigned short*)(p + 0x42);
    unsigned int maxh = h > 0x23e ? h : 0x23e;
    unsigned int base = ((unsigned int)fn_801D714C() + 31) & ~31;

    fn_801D717C(base + (((unsigned int)((unsigned short)w + 15) & 0xfff0) * maxh * 4), w);
    *(unsigned short*)(p + 0x90) = h;
    fn_8002395C(p + 0x58, 2, w, h, base);
    fn_80023AD0(p + 0x58, w, 0x1e0, 0, 0);

    p[0x84] = 0;
    p[0x85] = 0;
    p[0x86] = 0;
    p[0x87] = 0;
    *(int*)(p + 0x88) = 0xffffff;

    fn_801E8DC8(this);
    fn_801E98B0();
    VIWaitForRetrace();
    VIWaitForRetrace();
    fn_801D7154();
    fn_801D713C();

    int s1 = fn_801D7144();
    fillArena(fn_801D712C(), s1);
    int s2 = fn_801D714C();
    fillArena(fn_801D7134(), s2);

    fn_800242DC();
    fn_800244C4(lbl_80421788);
    fn_800244C4(lbl_80421890);
    initilize__17gfShutdownManagerFv(fn_80016938(this));

    fn_80022A90();
    fn_80026B14();
    fn_80022DE4();
    unsigned int seed = OSGetTick() & 0x07ffffff;
    fn_803F8C5C(seed);
    srandi(seed);

    gfErrorManager::create();
    lbl_8059FFB0 = gfErrorManager::getInstance();
    gfErrorCheck::init();
    gfArchiveManager::create();
    gfPadSystem::create();
    fn_80072968();
    fn_80073184(g_sndSystem);

    struct WordBits { unsigned int upper : 5; unsigned int value : 5; unsigned int lower : 22; };
    ((WordBits*)(p + 0xec))->value &= 0x1e;

    *(void**)(p + 0xd4) = create__14gfSceneManagerFv();
    *(gfTaskScheduler**)(p + 0xd8) = gfTaskScheduler::create();

    void* thread = __nw__FUlQ25Heaps8HeapType(0x358, 1);
    if (thread != 0) {
        *(void**)thread = __vt__8gfThread;
        createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(thread, thread, 0, 0x1000, 1);
        *(void**)thread = __vt__15gfMonitorThread;
        *(int*)((char*)thread + 0x340) = 0;
        Bits& flags = *(Bits*)((char*)thread + 0x350);
        flags.b0 = 1;
        flags.b1 = 0;
        flags.b2 = 1;
        flags.b3 = 1;
        *(unsigned short*)((char*)thread + 0x352) = 0xbb8;
    }

    *(void**)(p + 0xe0) = thread;
    *(int*)((char*)*(void**)(p + 0xe0) + 0x340) = fn_801E0714();
    OSResumeThread((OSThread*)((char*)*(void**)(p + 0xe0) + 8));

    getInstance__11ipPadConfigFv();
    ipSwitch::getInstance();
    fn_8004C1A4();
    fn_80019F60();
    ntFriendInfo::getInstance();

    fn_8002FDF4();
    gfCopyEFBMgr::getInstance()->createCopyEFB(0, (HeapType)0x2c);
    gfCopyEFBMgr::getInstance()->createCopyEFB(1, (HeapType)0x2c);

    fn_8000C960();
    fn_8009BE1C();
    fn_8005AD04();
    fn_8005E5E8(0x100, 0x20, 0x40);
    fn_80078600();
    fn_80158BE0();
    fn_8015919C();
    fn_800367C8();
    fn_8014734C();
    fn_80017A40(0);

    *(int*)(p + 0xe8) = 0;
    *(unsigned int*)(p + 0xe4) &= 0x00ffffff;
    if ((int)(fn_801DF7FC() >> 31) == 1) {
        int v = fn_801DF7FC();
        *(int*)(p + 0xe8) = v;
        struct StatusBits { unsigned int code : 8; unsigned int rest : 24; };
        if ((unsigned short)v == 2)
            ((StatusBits*)(p + 0xe4))->code = 2;
        else
            ((StatusBits*)(p + 0xe4))->code = 1;
    }

    g_gfShutdownManager.unk8.add((gfReturnStatusCallback*)lbl_804953A0);
    g_gfShutdownManager.unk8.add((gfReturnStatusCallback*)lbl_804976D8);
}
