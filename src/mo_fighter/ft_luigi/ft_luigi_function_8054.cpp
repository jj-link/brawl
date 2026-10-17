// fn_99_8054 -- ft_luigi .text [0x8054, 0x8110)
//
// Kind-0 article activation callback (paired with fn_99_8110, the Kind-1
// variant). Lazily constructs the shared article handler whose constructor
// and destructor live in module 27 (sora_melee), registers that destructor
// on the module-local global-destructor chain, then dispatches through the
// accesser's module enumeration and invokes the handler's activate entry
// with (weapon, accesser, query result, 0x1A).
//
// The lazy-init state, the handler object, and the destructor-chain anchor
// live in the rel's .bss (lbl_99_bss_1A0/1B4/1B8) and are defined by the
// auto-linked bss unit; this translation unit only references them.

#include <wn/weapon.h>
#include <so/so_module_accesser.h>

// Dispatch surface reached through the enumeration's resource-module
// pointer: the referenced object carries its table pointer at +8.
struct LuigiResourceDispatchProxy {
    unsigned int m_head0;
    unsigned int m_head1;
    virtual void p00();
    virtual void p01();
    virtual void p02();
    virtual void p03();
    virtual void* getDispatch();
};

// Object handed back by the proxy: table pointer at +0, query entry at
// table + 0x44.
struct LuigiDispatchable {
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual unsigned int query();
};

// Handler object layout: table pointer at +0, one word of state at +4.
struct LuigiHandlerBase {
    virtual void h00();
    virtual void h01();
    virtual void h02();
    virtual void h03();
    virtual void h04();
    virtual void h05();
    virtual void h06();
    virtual void h07();
    virtual void h08();
    virtual void h09();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
};
struct LuigiArticleHandler : LuigiHandlerBase {
    unsigned int m_state;
    virtual bool activate(Weapon*, soModuleAccesser*, unsigned int, unsigned int);
};

// Shapes of the .bss residents referenced below.
struct LuigiDestructorChain { void* next; void* destructor; void* object; };
struct LuigiHandlerBlob { void* vtable; unsigned int m_state; };

extern "C" {
extern LuigiDestructorChain lbl_99_bss_1A0;
extern signed char lbl_99_bss_1B4;
extern LuigiHandlerBlob lbl_99_bss_1B8;

void fn_27_328A0C(void* handler);
void fn_27_328A48(void* handler, short destroy);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" bool fn_99_8054(Weapon* weapon, soModuleAccesser* accesser) {
    if (lbl_99_bss_1B4 == 0) {
        fn_27_328A0C(&lbl_99_bss_1B8);
        __register_global_object(&lbl_99_bss_1B8, reinterpret_cast<void*>(fn_27_328A48),
                                 &lbl_99_bss_1A0);
        lbl_99_bss_1B4 = 1;
    }
    LuigiResourceDispatchProxy* proxy = reinterpret_cast<LuigiResourceDispatchProxy*>(
        accesser->m_enumerationStart->m_resourceModule);
    LuigiDispatchable* dispatchable =
        static_cast<LuigiDispatchable*>(proxy->getDispatch());
    return reinterpret_cast<LuigiArticleHandler*>(&lbl_99_bss_1B8)
        ->activate(weapon, accesser, dispatchable->query(), 0x1Au);
}
