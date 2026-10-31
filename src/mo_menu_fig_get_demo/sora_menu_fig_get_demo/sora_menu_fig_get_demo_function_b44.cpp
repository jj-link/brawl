#include <types.h>
#pragma force_active on
extern "C" {
bool isReady__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
extern void* g_gfSceneRoot;
extern u8* g_GameGlobal;
extern const float lbl_26_rodata_2C;
}
struct Arc { u8 pad[9]; u8 flag : 1; };
struct S {
    u8 p0[0x4c];
    u32 ids[(0x1dc - 0x4c) / 4];
    int count;
    u8 p1[0x394 - 0x1e0];
    void* files[1];
};
#define F(o, t) (*(t*)(self + (o)))
extern "C" int fn_26_B44(u8* self) {
    if (!isReady__14gfFileIOHandleCFv(self + 0x9fc)) return F(0x1368, int);
    if (!F(0x9fc, int)) return F(0x1368, int);
    if (!isReady__14gfFileIOHandleCFv(self + 0xd1c)) return F(0x1368, int);
    if (!F(0xd1c, int)) return F(0x1368, int);
    if (!isReady__14gfFileIOHandleCFv(self + 0x103c)) return F(0x1368, int);
    if (!F(0x103c, int)) return F(0x1368, int);
    if (!isReady__14gfFileIOHandleCFv(self + 0x11cc)) return F(0x1368, int);
    if (!F(0x11cc, int)) return F(0x1368, int);
    if (!F(0x135c, Arc*)->flag) return F(0x1368, int);
    F(0x524, void*) = getBuffer__14gfFileIOHandleCFv(self + 0x9fc);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x524);
    S* s = (S*)self;
    for (int i = 0; i < s->count; i++) {
        s->files[i] = getData__9gfArchiveF11ARCNodeTypeiUs(
            F(0x135c, void*), 3, s->ids[i] / 10, 0xfffe);
        Init__Q34nw4r3g3d7ResFileFPv(&s->files[i]);
    }
    F(0x52c, void*) = getBuffer__14gfFileIOHandleCFv(self + 0xd1c);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x52c);
    F(0x528, void*) = getBuffer__14gfFileIOHandleCFv(self + 0x103c);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x528);
    void* anm;
    void* tmp = 0;
    F(0x530, void*) = getBuffer__14gfFileIOHandleCFv(self + 0x11cc);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x530);
    tmp = GetResAnmScn__Q34nw4r3g3d7ResFileFi(self + 0x530, 0);
    anm = tmp;
    fn_801971D0(&tmp, &anm);
    fn_8000D6DC(g_gfSceneRoot, &tmp);
    (*(float**)(g_GameGlobal + 0x44))[1] = lbl_26_rodata_2C;
    (*(float**)(g_GameGlobal + 0x44))[2] = lbl_26_rodata_2C;
    return 3;
}
