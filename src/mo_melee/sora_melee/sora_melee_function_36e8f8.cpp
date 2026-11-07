#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" char lbl_27_data_731C[];
class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, s32), s32, s32);
extern "C" void fn_27_AB510(void*, s32);
extern "C" void fn_27_AB18C(void*, s32);
extern "C" void* fn_27_36E8F8(void* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0x80 != 0) {
            if ((u32)p + 0xA0 != 0 && (u32)p + 0xA0 != 0) {
                s16 id = *(s16*)((char*)p + 0xA4);
                *(void**)((char*)p + 0xA0) = (void*)lbl_27_data_731C;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(*(s16*)((char*)p + 0xA4));
                    mgr->eraseObserver(*(s16*)((char*)p + 0xA6), *(s16*)((char*)p + 0xA8));
                }
                *(s16*)((char*)p + 0xA8) = -1;
                *(s16*)((char*)p + 0xA4) = -1;
            }
            if ((u32)p + 0x94 != 0 && (u32)p + 0x94 != 0) {
                s16 id = *(s16*)((char*)p + 0x98);
                *(void**)((char*)p + 0x94) = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(*(s16*)((char*)p + 0x98));
                    mgr->eraseObserver(*(s16*)((char*)p + 0x9A), *(s16*)((char*)p + 0x9C));
                }
                *(s16*)((char*)p + 0x9C) = -1;
                *(s16*)((char*)p + 0x98) = -1;
            }
        }
        if ((char*)p + 0x14 != 0) {
            if ((u32)p + 0x34 != 0 && (u32)p + 0x34 != 0 && (u32)p + 0x34 != 0 && (u32)p + 0x34 != 0) {
                __destroy_arr((char*)p + 0x40, fn_27_AB510, 0x10, 1);
            }
            if ((u32)p + 0x14 != 0) {
                __destroy_arr((char*)p + 0x20, fn_27_AB18C, 0x14, 1);
            }
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}