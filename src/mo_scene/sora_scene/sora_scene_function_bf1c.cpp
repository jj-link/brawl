#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_scene.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <string.h>
#pragma force_active on

struct CopyD0 { u32 first; u32 words[51]; };
struct Copy5C { u32 a, b; u8 c; u32 words[20]; };
struct CopyCA { u16 words[100]; };
struct Args {
    u32 mode;
    void* res1;
    void* res2;
    void* res3;
    void* data1;
    void* data2;
    void* data3;
    void* data4;
    void* data5;
    CopyD0 a;
    Copy5C b;
    CopyD0 c;
    u8 flag1, flag2;
    u32 value1, value2;
    void* res4;
    void* data6;
    CopyCA d;
    u16 last;
    void* res5;
    void* data7;
    u32 size;
    u8 flag3;
};
extern "C" void fn_15_0(void*);
#define HANDLE(off) ((gfFileIOHandle*)(self + (off)))

extern "C" void fn_1_BF1C(u8* self) {
    Args args;
    u32 sp18, sp14, sp10, spC, sp8;
    void* buf;
    int special;
    int layout;

    args.mode = 0;
    args.res1 = 0;
    args.res2 = 0;
    args.res3 = 0;
    args.data1 = 0;
    args.data2 = 0;
    args.data3 = 0;
    args.data4 = 0;
    args.data5 = 0;
    args.flag1 = 0;
    args.flag2 = 0;
    args.value1 = 0;
    args.value2 = 0;
    args.res4 = 0;
    args.data6 = 0;
    args.res5 = 0;
    args.data7 = 0;
    args.size = 0;
    args.flag3 = 0;
    memset(&args.b, 0, sizeof(args.b));
    memset(&args.a, 0, sizeof(args.a));
    memset(&args.c, 0, sizeof(args.c));
    memset(&args.d, 0, 0xca);

    special = 0;
    layout = gfSceneManager::getInstance()->m_memoryLayout;
    if (layout < 0) {
        special = 1;
        layout = (int)((u32)((-1 - layout) | (layout + 1)) >> 31);
    }

    sp18 = 0;
    if (HANDLE(0x390)->getReturnStatus() == 0x15) buf = 0;
    else { buf = HANDLE(0x390)->getBuffer(); HANDLE(0x390)->release(); }
    if (buf) { sp18 = (u32)buf; nw4r::g3d::ResFile::Init(&sp18); }
    *(u32*)(self + 0x360) = sp18;
    sp14 = 0;
    if (HANDLE(0x394)->getReturnStatus() == 0x15) buf = 0;
    else { buf = HANDLE(0x394)->getBuffer(); HANDLE(0x394)->release(); }
    if (buf) { sp14 = (u32)buf; nw4r::g3d::ResFile::Init(&sp14); }
    *(u32*)(self + 0x364) = sp14;
    sp10 = 0;
    if (HANDLE(0x398)->getReturnStatus() == 0x15) buf = 0;
    else { buf = HANDLE(0x398)->getBuffer(); HANDLE(0x398)->release(); }
    if (buf) { sp10 = (u32)buf; nw4r::g3d::ResFile::Init(&sp10); }
    *(u32*)(self + 0x370) = sp10;
    if (HANDLE(0x39c)->getReturnStatus() == 0x15) buf = 0;
    else { buf = HANDLE(0x39c)->getBuffer(); HANDLE(0x39c)->release(); }
    *(void**)(self + 0x374) = buf;
    if (HANDLE(0x3a0)->getReturnStatus() == 0x15) buf = 0;
    else { buf = HANDLE(0x3a0)->getBuffer(); HANDLE(0x3a0)->release(); }
    *(void**)(self + 0x378) = buf;
    if (HANDLE(0x3a4)->getReturnStatus() == 0x15) buf = 0;
    else { buf = HANDLE(0x3a4)->getBuffer(); HANDLE(0x3a4)->release(); }
    *(void**)(self + 0x37c) = buf;
    args.res1 = self + 0x360;
    args.res2 = self + 0x364;
    args.res3 = self + 0x370;
    args.data1 = *(void**)(self + 0x374);
    args.data2 = *(void**)(self + 0x37c);
    args.data3 = *(void**)(self + 0x378);
    args.data4 = *(void**)(*(u8**)(self + 0x35c) + 0x48);
    args.data5 = *(void**)(self + 0x558);

    if (layout == 0) {
        args.mode = 0;
        args.a = *(CopyD0*)(self + 0x3b8);
    } else {
        args.mode = 1;
        args.b = *(Copy5C*)(self + 0x628);
        args.c = *(CopyD0*)(self + 0x3b8);
        args.a = *(CopyD0*)(self + 0x488);
        spC = 0;
        if (HANDLE(0x3a8)->getReturnStatus() == 0x15) buf = 0;
        else { buf = HANDLE(0x3a8)->getBuffer(); HANDLE(0x3a8)->release(); }
        if (buf) { spC = (u32)buf; nw4r::g3d::ResFile::Init(&spC); }
        *(u32*)(self + 0x368) = spC;
        args.res4 = self + 0x368;
        if (HANDLE(0x3ac)->getReturnStatus() == 0x15) buf = 0;
        else { buf = HANDLE(0x3ac)->getBuffer(); HANDLE(0x3ac)->release(); }
        *(void**)(self + 0x380) = buf;
        args.data6 = buf;
        args.d = *(CopyCA*)(self + 0x55c);
        args.last = *(u16*)(self + 0x624);
        sp8 = 0;
        if (HANDLE(0x3b0)->getReturnStatus() == 0x15) buf = 0;
        else { buf = HANDLE(0x3b0)->getBuffer(); HANDLE(0x3b0)->release(); }
        if (buf) { sp8 = (u32)buf; nw4r::g3d::ResFile::Init(&sp8); }
        *(u32*)(self + 0x36c) = sp8;
        args.res5 = self + 0x36c;
        int size = HANDLE(0x3b4)->getSize();
        if (HANDLE(0x3b4)->getReturnStatus() == 0x15) buf = 0;
        else { buf = HANDLE(0x3b4)->getBuffer(); HANDLE(0x3b4)->release(); }
        *(void**)(self + 0x384) = buf;
        args.data7 = buf;
        args.size = size;
        args.flag2 = *(u8*)(self + 0x684);
        args.value1 = *(u32*)(self + 0x688);
        args.value2 = *(u32*)(self + 0x68c);
        args.flag1 = *(u8*)(self + 0x626);
    }
    args.flag3 = special;
    fn_15_0(&args);
}