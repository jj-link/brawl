#include <types.h>
#pragma force_active on

struct grCollisionList {
    void* m_0;
    void* m_4;
    void* m_8;
};

extern grCollisionList g_grCollisionList;

extern "C" {
void fn_80112288();
extern char lbl_8049E570[];
void __register_global_object(void* obj, void* dtor, void* handle);

void fn_80112250() {
    g_grCollisionList.m_4 = nullptr;
    g_grCollisionList.m_8 = nullptr;
    g_grCollisionList.m_0 = nullptr;
    void* p = &g_grCollisionList.m_4;
    g_grCollisionList.m_4 = p;
    g_grCollisionList.m_8 = p;
    __register_global_object(&g_grCollisionList, (void*)fn_80112288, lbl_8049E570);
}
}

__declspec(section ".ctors") extern void* const fn_80112250_ctor = (void*)fn_80112250;
