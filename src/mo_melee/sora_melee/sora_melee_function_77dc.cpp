#include <types.h>
#pragma force_active on

class soModuleAccesser;
class soModelNodeSetUp;
class soModelVirtualNode;
class soEventObserverRegistrationDesc;
template <class T> class soArray;
class soModelEventObserver;

template <class T>
class soEventPresenter {
public:
    s16 m_manageID;
};

template <>
class soEventPresenter<soModelEventObserver> {
public:
    virtual ~soEventPresenter();
    s16 m_manageID;
    s16 m_unitID;
    void* m_list;
    soEventPresenter(s32 mid) {
        m_manageID = mid;
        m_unitID = 9;
        m_list = 0;
    }
};

struct World {
    char pad[8];
    float f8;
};

extern "C" {
extern u8 lbl_27_data_4A4[1];
extern char lbl_27_data_548[8];
extern char __RTTI__11soEventUnit[8];
extern char __vt__22soAnimCmdEventObserver[0x14];
extern char __vt__17soModelModuleImpl[0x17c];
extern World* g_soWorld;
void __ct__19soModelModuleSimpleFv(void*);
void fn_27_FED0(void*, void*);
void fn_27_FFF8(void*, void*);
void fn_27_100D8(void*, void*);
void fn_8015BF9C(void*, int);
void fn_8015BFB4(void*, void*);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void* __dynamic_cast(void*, long, const void*, const void*, long);
}

struct Desc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual u32 checkA();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u32 checkB();
};

struct IdSrc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

struct Obs {
    virtual void init(s16, s8);
};

struct Sys {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 check(long);
};

struct Mgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 check(long);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void* s10(long);
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void* get();
};

struct VList {
    virtual void v0();
    virtual void* at(s32);
    virtual void v2();
    virtual s32 size();
};

struct Bits {
    u8 hi : 4;
    u8 lo : 4;
};

struct B8 { char pad[8]; };
struct Fin : B8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void fin();
};

inline void* getResult(soEventPresenter<soModelEventObserver>* self) {
    s16 id = self->m_unitID;
    Mgr* mgr2 = (Mgr*)getManager__13soEventSystemFl(
        getInstance__13soEventSystemFv(), self->m_manageID);
    if (mgr2->check(id) == 0) {
        return 0;
    }
    Unit* u = (Unit*)__dynamic_cast(
        mgr2->s10(id), 0, lbl_27_data_548, __RTTI__11soEventUnit, 0);
    if (u == 0) {
        return 0;
    }
    return u->get();
}

struct Pre {
    char pad[0x20];
    Pre(soModuleAccesser* acc, Desc* desc) {
        char* p = (char*)this;
        __ct__19soModelModuleSimpleFv(this);
        s32 mid;
        if (desc->checkA() == 1) {
            mid = ((IdSrc*)(*(char**)(*(char**)((char*)acc + 0xD8) + 0x80) + 8))->get();
        } else {
            mid = -1;
        }
        Obs* o = (Obs*)(p + 0x14);
        *(s16*)(p + 0x18) = -1;
        *(s16*)(p + 0x1A) = 5;
        *(s16*)(p + 0x1C) = -1;
        *(void**)o = __vt__22soAnimCmdEventObserver;
        o->init((s16)mid, -1);
    }
};

inline s32 getId2(soModuleAccesser* acc, Desc* desc) {
    s32 mid2;
    if (desc->checkB() == 1) {
        mid2 = ((IdSrc*)(*(char**)(*(char**)((char*)acc + 0xD8) + 0x80) + 8))->get();
    } else {
        mid2 = -1;
    }
    return mid2;
}

class soModelModuleImpl {
    Pre pre;
    soEventPresenter<soModelEventObserver> pres;
public:
    soModelModuleImpl(soModuleAccesser*, soArray<soModelNodeSetUp>*, float, void*, soArray<soModelVirtualNode>*, soEventObserverRegistrationDesc*);
};

soModelModuleImpl::soModelModuleImpl(soModuleAccesser* acc, soArray<soModelNodeSetUp>* nodeSetUps, float f1, void* ext, soArray<soModelVirtualNode>* virt, soEventObserverRegistrationDesc* regDesc)
    : pre(acc, (Desc*)regDesc), pres(getId2(acc, (Desc*)regDesc)) {
    char* p = (char*)this;
    VList* vl = (VList*)nodeSetUps;
    soEventPresenter<soModelEventObserver>* pr = &pres;
    s32 mid2 = pr->m_manageID;
    if (mid2 > 0 && mid2 > -1) {
        if (((Sys*)getInstance__13soEventSystemFv())->check(mid2) != 0) {
            Mgr* mgr = (Mgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), pr->m_manageID);
            if (mgr->check(pr->m_unitID) == 0) {
                pr->m_list = 0;
            } else {
                void* r = getResult(pr);
                pr->m_list = r;
            }
        }
    }

    *(void**)(p + 8) = __vt__17soModelModuleImpl;
    *(void**)(p + 0) = __vt__17soModelModuleImpl + 8;
    *(void**)(p + 0x14) = __vt__17soModelModuleImpl + 0x154;
    *(void**)(p + 0x20) = __vt__17soModelModuleImpl + 0x168;
    fn_27_FED0(p + 0x2C, this);
    fn_27_FFF8(p + 0x34, this);
    *(s32*)(p + 0x48) = 0;
    *(float*)(p + 0x4C) = f1;
    *(float*)(p + 0x50) = g_soWorld->f8;
    *(s32*)(p + 0x88) = -1;
    *(void**)(p + 0x8C) = ext;
    *(void**)(p + 0x90) = virt;
    fn_27_100D8(p + 0x98, this);
    *(s32*)(p + 0xA8) = 0;
    *(s32*)(p + 0xAC) = 0;
    *(s32*)(p + 0xB0) = 0;
    *(s32*)(p + 0xB4) = 0;
    *(u8*)(p + 0xB8) = 0;
    *(s32*)(p + 0xBC) = 0;
    *(u8*)(p + 0xC2) = 0;
    *(u8*)(p + 0xC3) = 0;
    *(u8*)(p + 0xC4) = lbl_27_data_4A4[0];
    ((Bits*)(p + 0xC5))->hi = 0;
    *(void**)(p + 0xC8) = acc;
    fn_8015BF9C(p + 0x3C, 0x2C);
    for (s32 i = 0; i < vl->size(); i++) {
        void* e = vl->at(i);
        *(s32*)((char*)e + 0x28) = 0;
        fn_8015BFB4(p + 0x3C, e);
    }
    ((Fin*)p)->fin();
}
