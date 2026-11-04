#include <em/em_area_module_impl.h>
#include <em/em_manager.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" {
int fn_27_A4950(void*);
u32* fn_27_A4964(void*, int);
int fn_27_10B294(ftManager*, int, int*);
u32 fn_41_D108(emManager*, int);
u32 fn_41_D044(emManager*, u32);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
}

bool emAreaModuleImpl::checkArea(soModuleAccesser* acc, u32 id, u32 kind) {
    int count = fn_27_A4950(this);
    if (count <= 0) return false;
    for (int i = 0; i < count; ++i) {
        u32 self;
        u32* p = fn_27_A4964(this, i);
        if (id == p[0]) {
            if (kind <= 3) {
                if (*(u8*)((char*)p + 12) == 0) {
                    int instance = 0;
                    int entry = fn_27_10B294(g_ftManager, p[1], &instance);
                    if (entry != -1) {
                        Fighter* fighter = g_ftManager->getFighter(entry, instance);
                        Fighter* main = g_ftManager->getFighter(entry, -1);
                        if (kind <= 1) {
                            if (g_ftManager->getPlayerNo(entry) == 0) {
                                if ((int)kind == 0) {
                                    if (fighter == main) return true;
                                } else if ((int)kind == 1 && fighter != main) return true;
                            }
                        } else if (kind - 2 <= 1 && g_ftManager->getPlayerNo(entry) == 1) {
                            if ((int)kind == 2) {
                                if (fighter == main) return true;
                            } else if ((int)kind == 3 && fighter != main) return true;
                        }
                    }
                }
            } else if (kind - 4 <= 1) {
                if (*(u8*)((char*)p + 12) == 1) {
                    u32 target = fn_41_D108(emManager::getInstance(), p[1]);
                    if (target != 0xffff) {
                        void* obj = __dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
                        self = *(u32*)((char*)obj + 0xb0);
                        if ((int)kind == 4) {
                            if (self == target) return true;
                        } else if ((int)kind == 5) {
                            u32 parent = fn_41_D044(emManager::getInstance(), self);
                            if (parent != 0xffff && parent == target) return true;
                        }
                    }
                }
            } else if ((int)kind == 6) {
                return true;
            } else if ((int)kind == 7) {
                return true;
            } else {
                break;
            }
        }
    }
    return false;
}