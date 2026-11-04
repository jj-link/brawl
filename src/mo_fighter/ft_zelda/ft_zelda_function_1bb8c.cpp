#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
void* fn_104_1B37C();
unsigned int fn_27_33C71C(void*, Weapon*, soModuleAccesser*, void*);
unsigned int fn_27_33C9D0(void*, Weapon*, soModuleAccesser*, void*);
unsigned int fn_104_1B3EC(Weapon*, soModuleAccesser*);
unsigned int fn_104_1B508(Weapon*, soModuleAccesser*);
unsigned int fn_104_1B62C(Weapon*, soModuleAccesser*);
unsigned int fn_104_1B6E8(Weapon*, soModuleAccesser*);
}

namespace {
struct ZeldaPad8 {
    char pad[8];
};

class ZeldaModule : public ZeldaPad8 {
public:
    virtual void* f0() = 0;
    virtual void* f1() = 0;
    virtual void* f2() = 0;
    virtual void* f3() = 0;
    virtual void* f4() = 0;
    virtual void* f5() = 0;
    virtual void* f6() = 0;
};

class ZeldaHandle {
public:
    virtual void* g0() = 0;
    virtual void* g1() = 0;
    virtual void* g2() = 0;
    virtual void* g3() = 0;
    virtual void* g4() = 0;
    virtual void* g5() = 0;
    virtual void* g6() = 0;
    virtual void* g7() = 0;
    virtual void* g8() = 0;
    virtual void* g9() = 0;
    virtual void* g10() = 0;
    virtual void* g11() = 0;
    virtual void* g12() = 0;
    virtual void* g13() = 0;
    virtual void* g14() = 0;
    virtual void* g15() = 0;
    virtual void* g16() = 0;
    virtual void* g17() = 0;
};

struct ZeldaStatus {
    bool flags[2];
    ZeldaStatus() { flags[0] = false; flags[1] = false; }
};

template <unsigned Kind> struct ZeldaActivation {
    unsigned int operator()(Weapon*, soModuleAccesser*) const { return 0; }
};
template <> struct ZeldaActivation<0> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        char* p = *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8);
        char* o = *reinterpret_cast<char**>(p);
        void* r = reinterpret_cast<ZeldaModule*>(o)->f4();
        void* temp = reinterpret_cast<ZeldaHandle*>(r)->g15();
        return fn_27_33C71C(fn_104_1B37C(), owner, accesser, temp);
    }
};
template <> struct ZeldaActivation<1> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        char* p = *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8);
        char* o = *reinterpret_cast<char**>(p);
        void* r = reinterpret_cast<ZeldaModule*>(o)->f4();
        void* temp = reinterpret_cast<ZeldaHandle*>(r)->g15();
        return fn_27_33C9D0(fn_104_1B37C(), owner, accesser, temp);
    }
};
template <> struct ZeldaActivation<2> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_104_1B3EC(owner, accesser);
    }
};
template <> struct ZeldaActivation<3> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_104_1B508(owner, accesser);
    }
};
template <> struct ZeldaActivation<4> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_104_1B62C(owner, accesser);
    }
};
template <> struct ZeldaActivation<5> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_104_1B6E8(owner, accesser);
    }
};

struct ZeldaDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};

class ZeldaSelector {
public:
    soArticle* article;
    ZeldaSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};

struct ZeldaSearch {
    bool operator()(ZeldaSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};

template <unsigned Kind> struct ZeldaPool {
    static inline Weapon* find(char*, ZeldaSelector&, ZeldaSearch) { return 0; }
};
template <> struct ZeldaPool<0> {
    static inline Weapon* find(char* pool, ZeldaSelector& selector, ZeldaSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x15A78)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x159F0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13EA4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x13E1C);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x122D0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x12248);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x106FC)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x10674);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xEB28)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xEAA0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xCF54)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xCECC);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xB380)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xB2F8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x97AC)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x9724);
        else owner = 0;
        return owner;
    }
};
template <> struct ZeldaPool<1> {
    static inline Weapon* find(char* pool, ZeldaSelector& selector, ZeldaSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7F90)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7F08);
        else owner = 0;
        return owner;
    }
};
template <> struct ZeldaPool<2> {
    static inline Weapon* find(char* pool, ZeldaSelector& selector, ZeldaSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5E5C)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x5DD4);
        else owner = 0;
        return owner;
    }
};
template <> struct ZeldaPool<3> {
    static inline Weapon* find(char* pool, ZeldaSelector& selector, ZeldaSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3F10)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3E88);
        else owner = 0;
        return owner;
    }
};
template <> struct ZeldaPool<4> {
    static inline Weapon* find(char* pool, ZeldaSelector& selector, ZeldaSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1FDC)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1F54);
        else owner = 0;
        return owner;
    }
};
template <> struct ZeldaPool<5> {
    static inline Weapon* find(char* pool, ZeldaSelector& selector, ZeldaSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xA0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18);
        else owner = 0;
        return owner;
    }
};

template <unsigned Kind>
inline soArticle* allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const ZeldaActivation<Kind>& activation,
                                  const ZeldaDeactivation& deactivation) {
    ZeldaStatus status;
    if (Kind >= 6) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    ZeldaSelector selector;
    Weapon* owner = ZeldaPool<Kind>::find(pool, selector, ZeldaSearch());
    if (!owner) {
        owner = static_cast<Weapon*>(selector.article);
        if (!owner) {
            selector.release(-1);
            return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }
    if (activation(owner, accesser) == true) {
        selector.release(-1);
        return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
    }
    selector.release(-1);
    return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}

extern "C" soArticle* fn_104_1BB8C(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, ZeldaActivation<0>(), ZeldaDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, ZeldaActivation<1>(), ZeldaDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, ZeldaActivation<2>(), ZeldaDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, ZeldaActivation<3>(), ZeldaDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, ZeldaActivation<4>(), ZeldaDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, ZeldaActivation<5>(), ZeldaDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, ZeldaActivation<6>(), ZeldaDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, ZeldaActivation<7>(), ZeldaDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, ZeldaActivation<8>(), ZeldaDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, ZeldaActivation<9>(), ZeldaDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, ZeldaActivation<10>(), ZeldaDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, ZeldaActivation<11>(), ZeldaDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, ZeldaActivation<12>(), ZeldaDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, ZeldaActivation<13>(), ZeldaDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, ZeldaActivation<14>(), ZeldaDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, ZeldaActivation<15>(), ZeldaDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, ZeldaActivation<16>(), ZeldaDeactivation());
    default: return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
