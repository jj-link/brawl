#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" char lbl_27_data_731C[];
class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, s32), s32, s32);
extern "C" void fn_27_AB510(void*, s32);
extern "C" void fn_27_AB18C(void*, s32);
extern "C" void* fn_27_2F5BA0(void* p, s32 flag) {
    if (p != nullptr) {
        if ((u32)p + 0xD0 != 0) {
            if ((u32)p + 0xF0 != 0 && (u32)p + 0xF0 != 0) {
                s16 id = *(s16*)((char*)p + 0xF4);
                *(void**)((char*)p + 0xF0) = (void*)lbl_27_data_731C;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(*(s16*)((char*)p + 0xF4));
                    mgr->eraseObserver(*(s16*)((char*)p + 0xF6), *(s16*)((char*)p + 0xF8));
                }
                *(s16*)((char*)p + 0xF8) = -1;
                *(s16*)((char*)p + 0xF4) = -1;
            }
            if ((u32)p + 0xE4 != 0 && (u32)p + 0xE4 != 0) {
                s16 id = *(s16*)((char*)p + 0xE8);
                *(void**)((char*)p + 0xE4) = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(*(s16*)((char*)p + 0xE8));
                    mgr->eraseObserver(*(s16*)((char*)p + 0xEA), *(s16*)((char*)p + 0xEC));
                }
                *(s16*)((char*)p + 0xEC) = -1;
                *(s16*)((char*)p + 0xE8) = -1;
            }
        }
        if ((char*)p + 0x48 != 0) {
            if ((u32)p + 0x68 != 0 && (u32)p + 0x68 != 0 && (u32)p + 0x68 != 0 && (u32)p + 0x68 != 0) {
                __destroy_arr((char*)p + 0x74, fn_27_AB510, 0x10, 2);
            }
            if ((u32)p + 0x48 != 0) {
                __destroy_arr((char*)p + 0x54, fn_27_AB18C, 0x14, 1);
            }
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}