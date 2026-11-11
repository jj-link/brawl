#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_113_10428(Weapon*, soModuleAccesser*);
bool fn_113_10734(Weapon*, soModuleAccesser*);
bool fn_113_10828(Weapon*, soModuleAccesser*);
}

namespace {
struct PikminStatus {
    bool flags[2];
    PikminStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct PikminActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_113_10428(owner, accesser);
    }
};
template <> struct PikminActivation<1> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_113_10734(owner, accesser);
    }
};
template <> struct PikminActivation<2> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_113_10828(owner, accesser);
    }
};
struct PikminDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class PikminSelector {
public:
    soArticle* article;
    PikminSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct PikminSearch {
    bool operator()(PikminSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct PikminPool {
    static inline Weapon* find(char*, PikminSelector&, PikminSearch) { return 0; }
};
template <> struct PikminPool<0> {
    static inline Weapon* find(char* pool, PikminSelector& selector, PikminSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1449c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x14414);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x11154)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x110cc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xde0c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xdd84);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xaac4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xaa3c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x777c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x76f4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4434)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x43ac);
        else owner = 0;
        return owner;
    }
};
template <> struct PikminPool<1> {
    static inline Weapon* find(char* pool, PikminSelector& selector, PikminSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1fec)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1f64);
        else owner = 0;
        return owner;
    }
};
template <> struct PikminPool<2> {
    static inline Weapon* find(char* pool, PikminSelector& selector, PikminSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocatePikmin(char* pool, soModuleAccesser* accesser,
                                 const PikminActivation<Kind>& activation,
                                 const PikminDeactivation& deactivation) {
    PikminStatus status;
    if (Kind >= 3) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    PikminSelector selector;
    Weapon* owner = PikminPool<Kind>::find(pool, selector, PikminSearch());
    if (!owner) {
        owner = static_cast<Weapon*>(selector.article);
        if (!owner) {
            selector.release(-1);
            return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }
    if (activation(owner, accesser) == true) {
        selector.release(-1);
        return static_cast<soArticle&>(*owner);
    }
    selector.release(-1);
    return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}

extern "C" soArticle& fn_113_D174(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocatePikmin<0>(pool, accesser, PikminActivation<0>(), PikminDeactivation());
    case 1: return allocatePikmin<1>(pool, accesser, PikminActivation<1>(), PikminDeactivation());
    case 2: return allocatePikmin<2>(pool, accesser, PikminActivation<2>(), PikminDeactivation());
    case 3: return allocatePikmin<3>(pool, accesser, PikminActivation<3>(), PikminDeactivation());
    case 4: return allocatePikmin<4>(pool, accesser, PikminActivation<4>(), PikminDeactivation());
    case 5: return allocatePikmin<5>(pool, accesser, PikminActivation<5>(), PikminDeactivation());
    case 6: return allocatePikmin<6>(pool, accesser, PikminActivation<6>(), PikminDeactivation());
    case 7: return allocatePikmin<7>(pool, accesser, PikminActivation<7>(), PikminDeactivation());
    case 8: return allocatePikmin<8>(pool, accesser, PikminActivation<8>(), PikminDeactivation());
    case 9: return allocatePikmin<9>(pool, accesser, PikminActivation<9>(), PikminDeactivation());
    case 10: return allocatePikmin<10>(pool, accesser, PikminActivation<10>(), PikminDeactivation());
    case 11: return allocatePikmin<11>(pool, accesser, PikminActivation<11>(), PikminDeactivation());
    case 12: return allocatePikmin<12>(pool, accesser, PikminActivation<12>(), PikminDeactivation());
    case 13: return allocatePikmin<13>(pool, accesser, PikminActivation<13>(), PikminDeactivation());
    case 14: return allocatePikmin<14>(pool, accesser, PikminActivation<14>(), PikminDeactivation());
    case 15: return allocatePikmin<15>(pool, accesser, PikminActivation<15>(), PikminDeactivation());
    case 16: return allocatePikmin<16>(pool, accesser, PikminActivation<16>(), PikminDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}