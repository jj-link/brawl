#include <types.h>
#pragma force_active on

extern "C" {
void* create__5MuMsgFUlQ25Heaps8HeapTypeUl(u32, u32, u32);
void allocMsgBuf__5MuMsgFUlUl(void*, u32, u32);
void setMsgData__5MuMsgFPv(void*, void*);
void attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(void*, u32, void*, u32, float);
void getHScale__5MuMsgFUlf(void*, u32, float);
void fn_8006B660(void*, u32, u32);
int getReturnStatus__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
extern float lbl_2_rodata_354;
extern float lbl_2_rodata_358;
}

extern "C" void fn_2_9708(u8* s) {
    void* data;
    void** holder;
    u8* p;
    int i;
    void* msg;
    msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, 0x2a, 0x2b);
    *reinterpret_cast<void**>(s + 0xd4) = msg;
    allocMsgBuf__5MuMsgFUlUl(msg, 0x100, 7);
    if (getReturnStatus__14gfFileIOHandleCFv(s + 0x284) == 0x15) {
        data = 0;
    } else {
        data = getBuffer__14gfFileIOHandleCFv(s + 0x284);
        release__14gfFileIOHandleFv(s + 0x284);
    }
    setMsgData__5MuMsgFPv(msg, data);

    holder = *reinterpret_cast<void***>(s + 0x118);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 0, holder[4], 0, lbl_2_rodata_354);
    getHScale__5MuMsgFUlf(msg, 0, lbl_2_rodata_358);
    fn_8006B660(*reinterpret_cast<void**>(reinterpret_cast<u8*>(msg) + 8), 0, 7);
    attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, 6, holder[4], 1, lbl_2_rodata_354);
    fn_8006B660(*reinterpret_cast<void**>(reinterpret_cast<u8*>(msg) + 8), 6, 7);

    p = s;
    for (i = 0; i < 4; i++) {
        void** h = *reinterpret_cast<void***>(p + 0x11c);
        attachScnMdlSimple__5MuMsgFUlPQ34nw4r3g3d12ScnMdlSimpleUlf(msg, i + 1, h[4], 0, lbl_2_rodata_354);
        getHScale__5MuMsgFUlf(msg, i + 1, lbl_2_rodata_358);
        fn_8006B660(*reinterpret_cast<void**>(reinterpret_cast<u8*>(msg) + 8), i + 1, 7);
        p += 4;
    }

    if (getReturnStatus__14gfFileIOHandleCFv(s + 0x288) == 0x15) {
        data = 0;
    } else {
        data = getBuffer__14gfFileIOHandleCFv(s + 0x288);
        release__14gfFileIOHandleFv(s + 0x288);
    }
    *reinterpret_cast<void**>(s + 0xdc) = data;
    if (getReturnStatus__14gfFileIOHandleCFv(s + 0x28c) == 0x15) {
        data = 0;
    } else {
        data = getBuffer__14gfFileIOHandleCFv(s + 0x28c);
        release__14gfFileIOHandleFv(s + 0x28c);
    }
    *reinterpret_cast<void**>(s + 0xe0) = data;
}
