// The switch table occupies a four-byte-aligned range in the original REL.
#pragma section data_type ".data$pikachuA548" ".bss"

#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_98_9570(Weapon*, soModuleAccesser*);
bool fn_98_9620(Weapon*, soModuleAccesser*);
bool fn_98_9708(Weapon*, soModuleAccesser*);
bool fn_27_32625C(Weapon*, soModuleAccesser*);
}

namespace {
struct PikachuArticleStatus {
    bool flags[2];
    PikachuArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct PikachuArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        switch (Kind) {
        case 0: return fn_98_9570(owner, accesser);
        case 1: return fn_98_9620(owner, accesser);
        case 2: return fn_98_9708(owner, accesser);
        case 3: return fn_27_32625C(owner, accesser);
        default: return false;
        }
    }
};
struct PikachuArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class PikachuArticleSelector {
public:
    soArticle* article;
    PikachuArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct PikachuArticleSearch {
    bool operator()(PikachuArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct PikachuArticlePool {
    static inline Weapon* find(char*, PikachuArticleSelector&, PikachuArticleSearch) { return 0; }
};
template <> struct PikachuArticlePool<0> {
    static inline Weapon* find(char* pool, PikachuArticleSelector& selector, PikachuArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x20b20)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x20a98);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1eb88)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1eb00);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1cbf0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1cb68);
        else owner = 0;
        return owner;
    }
};
template <> struct PikachuArticlePool<1> {
    static inline Weapon* find(char* pool, PikachuArticleSelector& selector, PikachuArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x125e0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x12558);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7fe0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7f58);
        else owner = 0;
        return owner;
    }
};
template <> struct PikachuArticlePool<2> {
    static inline Weapon* find(char* pool, PikachuArticleSelector& selector, PikachuArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x6008)) == true ? reinterpret_cast<Weapon*>(pool + 0x5f80) : 0;
        return owner;
    }
};
template <> struct PikachuArticlePool<3> {
    static inline Weapon* find(char* pool, PikachuArticleSelector& selector, PikachuArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4038)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3fb0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2070)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1fe8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xa8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x20);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const PikachuArticleActivation<Kind>& activation,
                                  const PikachuArticleDeactivation& deactivation) {
    PikachuArticleStatus status;
    if (Kind >= 4) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    PikachuArticleSelector selector;
    Weapon* owner = PikachuArticlePool<Kind>::find(pool, selector, PikachuArticleSearch());
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

extern "C" soArticle& fn_98_A548(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, PikachuArticleActivation<0>(), PikachuArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, PikachuArticleActivation<1>(), PikachuArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, PikachuArticleActivation<2>(), PikachuArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, PikachuArticleActivation<3>(), PikachuArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, PikachuArticleActivation<4>(), PikachuArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, PikachuArticleActivation<5>(), PikachuArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, PikachuArticleActivation<6>(), PikachuArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, PikachuArticleActivation<7>(), PikachuArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, PikachuArticleActivation<8>(), PikachuArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, PikachuArticleActivation<9>(), PikachuArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, PikachuArticleActivation<10>(), PikachuArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, PikachuArticleActivation<11>(), PikachuArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, PikachuArticleActivation<12>(), PikachuArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, PikachuArticleActivation<13>(), PikachuArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, PikachuArticleActivation<14>(), PikachuArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, PikachuArticleActivation<15>(), PikachuArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, PikachuArticleActivation<16>(), PikachuArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
