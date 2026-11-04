#include <mu/adv/mu_adv_result.h>
#include <it/it_manager.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_34_D8(void*);
extern "C" void fn_800B96E8(void*, int);
extern "C" void* fn_800AD808(void*, int);

muAdvResultTask* muAdvResultTask::create(const muAdvResultTaskParam* param) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x5b0, 0x2a);
    if (obj) {
        obj = fn_34_D8(obj);
    }
    char* p = (char*)obj;
    *(u32*)(p + 0x44) = param->m_mainPlayerPort;
    fn_800B96E8(p + 0x4c, (u8)param->m_mainPlayerPort);
    *(u32*)(p + 0xfc) = param->m_earnedCoinsForClear;
    *(u32*)(p + 0x100) = param->m_scoreInCurrentStage;
    *(u32*)(p + 0x104) = param->m_totalScore;
    *(void**)(p + 0x108) = param->unk10;
    *(void**)(p + 0x10c) = param->unk14;
    *(void**)(p + 0x110) = param->unk18;
    void* figure = *(void**)((char*)itManager::getInstance() + 0x14b8);
    if (figure) {
        *(u32*)(p + 0x114) = *(u32*)((char*)figure + 4);
    }
    void* other = __nw__FUlQ25Heaps8HeapType(0x3eb4, 0x2a);
    if (other) {
        other = fn_800AD808(other, 1);
    }
    *(void**)(p + 0x11c) = other;
    *(u32*)(p + 0x48) = 0x3c;
    return (muAdvResultTask*)obj;
}