#include <types.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* __construct_new_array(void*, void (*)(), void (*)(), unsigned long, int);
extern "C" void fn_800B8BC8(void);
extern "C" void fn_800B8AC8(void);

bool MuMsg::allocMsgBuf(u32 msgSizes, u32 numMsgs) {
    if (m_message->allocMsgBuf(msgSizes, numMsgs, m_heapType) == 0) {
        return false;
    }
    void* heap = __nwa__FUlQ25Heaps8HeapType(numMsgs * 0x48 + 0x10, m_heapType);
    s32 i;
    MuMsg::WindowSetting* p = (MuMsg::WindowSetting*)__construct_new_array(heap, fn_800B8BC8, fn_800B8AC8, 0x48, numMsgs);
    *(MuMsg::WindowSetting**)&_12 = p;
    m_numMsgs = numMsgs;
    i = 0;
    while (i < (s32)numMsgs) {
        initWindowSetting(p);
        i++;
        p++;
    }
    return true;
}
