#include <types.h>
#include <gf/gf_task.h>
#include <gf/gf_archive.h>
#include <gf/gf_file_io_handle.h>
#include <mu/mu_msg.h>
#include <cm/cm_camera_controller.h>
#include <snd/snd_system.h>
#include <string.h>
#pragma force_active on
extern "C" {
extern const char lbl_80456A80[];
extern const char lbl_80456A90[];
extern u8 lbl_80456CAC[];
extern const f32 lbl_805A2248;
extern const f32 lbl_805A224C;
extern void* g_GameGlobal;
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void fn_800B96E8(void*, int);
void* fn_800B08A8(int);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void*, const char*, int, int, int);
int loadSoundGroup__9sndSystemF10SndGroupIDib(void*, int, int, int);
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, int, unsigned long);
void allocMsgBuf__5MuMsgFUlUl(void*, unsigned long, unsigned long);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
}
inline void clearWords(int* p, int* e) { do { *p = 0; ++p; } while (p < e); }
struct Arrays { char pad[0x100]; int a[665]; int b[132]; char gap[8]; int d7c; int c[65]; };
#define W(o) (*(u32*)(p + (o)))
#define B(o) (*(u8*)(p + (o)))
extern "C" Arrays* fn_800BA7C0(Arrays* self, s32 arg1, s32 arg2, s32 arg3) {
    char* p = (char*)self;
    void* obj;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80456A80, 0x12, 0xE, 6, true);
    W(0x44) = 0;
    W(0x3c) = (u32)lbl_80456CAC;
    W(0x48) = 0;
    fn_800B96E8(p + 0x4c, 0xff);
    W(0xf4) = *(u32*)(*(u32*)((char*)g_GameGlobal + 0x1c) + 0x24);
    W(0xf8) = arg3;
    W(0xd7c) = 0;
    clearWords((int*)(p + 0xd80), (int*)(p + 0xe84));
    W(0x108c) = arg2;
    W(0x1090) = 0x10;
    W(0x1094) = 2;
    B(0x1098) = 1;
    W(0x109c) = 1;
    W(0x10a0) = 0x10;
    B(0x10a4) = 0;
    W(0x12a8) = 0;
    *(f32*)(p + 0x12ac) = lbl_805A2248;
    W(0x12b0) = 0;
    B(0x12d8) = 0;
    B(0x12d9) = 0;
    B(0x12e4) = 0;
    B(0x12e5) = 0;
    B(0x12ec) = 0;
    W(0x12f0) = 0;
    W(0x12fc) = 0;
    W(0x1300) = 0;
    W(0x1304) = arg1;
    if ((s32)W(0xf8) < 0 || (s32)W(0xf8) >= 8) W(0xf8) = 0;
    if ((s32)W(0xf4) < 0 || (s32)W(0xf4) >= 8) W(0xf4) = 0;
    fn_800B96E8(p + 0x4c, W(0xf8) & 0xff);
    W(0x12b4) = *(u8*)(*(u32*)((char*)g_GameGlobal + 0x24) + 0x15a8);
    *(f32*)(p + 0x12cc) = lbl_805A2248;
    *(f32*)(p + 0x12d0) = lbl_805A2248;
    *(f32*)(p + 0x12d4) = lbl_805A224C;
    obj = fn_800B08A8(0x2a);
    W(0xd74) = (u32)obj;
    *(u32*)((char*)obj + 0x40) = (u32)(p + 0x100);
    *(u32*)((char*)obj + 0x44) = 0x299;
    for (int i = 0; i < 665; ++i) self->a[i] = 0;
    for (int i = 0; i < 132; ++i) self->b[i] = 0;
    W(0xd7c) = 0;
    for (int i = 0; i < 65; ++i) self->c[i] = 0;
    obj = __nw__FUlQ25Heaps8HeapType(0x80, 0x2a);
    if (obj) obj = __ct__9gfArchiveFv(obj);
    W(0x12f8) = (u32)obj;
    obj = __nw__FUlQ25Heaps8HeapType(0x80, 0x2a);
    if (obj) obj = __ct__9gfArchiveFv(obj);
    W(0x12f4) = (u32)obj;
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(p + 0x12fc, lbl_80456A90, 0x2b, 0, 0);
    W(0xfc) = loadSoundGroup__9sndSystemF10SndGroupIDib(g_sndSystem, 0x72, 1, 1);
    W(0xd78) = (u32)create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    allocMsgBuf__5MuMsgFUlUl((void*)W(0xd78), 0x400, 5);
    changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
    return self;
}