#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on
extern "C" char lbl_27_data_731C[];
class soAnimCmdEventObserver;
template <class T> struct soEventObserver { static void __vt(int, int); };
extern "C" void __dl__FPv(void*);
extern "C" void __destroy_arr(void*, void (*)(void*, s32), s32, s32);
extern "C" void fn_27_AB510(void*, s32);
extern "C" void fn_27_AB18C(void*, s32);

extern "C" void* fn_27_37AE10(void* p, s32 flag) {
    if (p != 0) {
        if ((u32)p + 0x67c != 0) {
            if ((u32)p + 0x69c != 0 && (u32)p + 0x69c != 0) {
                s16 id = *(s16*)((char*)p + 0x6a0);
                *(void**)((char*)p + 0x69c) = (void*)lbl_27_data_731C;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(*(s16*)((char*)p + 0x6a0));
                    mgr->eraseObserver(*(s16*)((char*)p + 0x6a2), *(s16*)((char*)p + 0x6a4));
                }
                *(s16*)((char*)p + 0x6a4) = -1;
                *(s16*)((char*)p + 0x6a0) = -1;
            }
            if ((u32)p + 0x690 != 0 && (u32)p + 0x690 != 0) {
                s16 id = *(s16*)((char*)p + 0x694);
                *(void**)((char*)p + 0x690) = (void*)soEventObserver<soAnimCmdEventObserver>::__vt;
                u32 r = soEventSystem::getInstance()->getInstanceManager().isContain(id);
                if (r == 1) {
                    soEventManager* mgr = soEventSystem::getInstance()->getManager(*(s16*)((char*)p + 0x694));
                    mgr->eraseObserver(*(s16*)((char*)p + 0x696), *(s16*)((char*)p + 0x698));
                }
                *(s16*)((char*)p + 0x698) = -1;
                *(s16*)((char*)p + 0x694) = -1;
            }
        }
        if ((char*)p + 0xbc != 0) {
            if ((u32)p + 0xf0 != 0 && (u32)p + 0xf0 != 0 && (u32)p + 0xf0 != 0) {
                if ((u32)p + 0x10c != 0) {
                    __destroy_arr((char*)p + 0x118, fn_27_AB510, 0x10, 8);
                }
                if ((s32)p + 0xf0 != 0 && (s32)p + 0xf0 != 0 && (s32)p + 0xf0 != 0) {
                    __destroy_arr((char*)p + 0xfc, fn_27_AB510, 0x10, 1);
                }
            }
            if ((u32)p + 0xbc != 0) {
                __destroy_arr((char*)p + 0xc8, fn_27_AB18C, 0x14, 2);
            }
        }
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}