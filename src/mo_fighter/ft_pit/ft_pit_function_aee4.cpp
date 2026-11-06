#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#include <so/resource/so_resource_module_impl.h>
#include <so/resource/so_resource_id_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_112_9FF8(Weapon*, soModuleAccesser*);
void* fn_112_A0A4();
bool fn_112_A114(Weapon*, soModuleAccesser*);
unsigned int fn_27_35A4C4(void*, Weapon*, soModuleAccesser*, unsigned int);
}

namespace {
struct PitArticleStatus {
    bool flags[2];
    PitArticleStatus() { flags[0] = false; flags[1] = false; }
};
class PitArticleSelector {
public:
    soArticle* article;
    PitArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct PitArticleSearch {
    bool operator()(PitArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct PitArticleActivation {
    unsigned int operator()(Weapon*, soModuleAccesser*) const { return 0; }
};
template <> struct PitArticleActivation<0> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_112_9FF8(owner, accesser);
    }
};
template <> struct PitArticleActivation<1> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        unsigned int resId = accesser->getResourceModule().getResourceIdAccesser()->getEtcResId();
        return fn_27_35A4C4(fn_112_A0A4(), owner, accesser, resId);
    }
};
template <> struct PitArticleActivation<2> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_112_A114(owner, accesser);
    }
};
struct PitArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
template <unsigned Kind> struct PitArticlePool {
    static inline Weapon* find(char*, PitArticleSelector&, PitArticleSearch) { return 0; }
};
template <> struct PitArticlePool<0> {
    static inline Weapon* find(char* self, PitArticleSelector& selector, PitArticleSearch search) {
        if (search(selector, reinterpret_cast<soArticle*>(self + 0x200D4)) == 1U) return reinterpret_cast<Weapon*>(self + 0x2004C);
        return 0;
    }
};
template <> struct PitArticlePool<1> {
    static inline Weapon* find(char* self, PitArticleSelector& selector, PitArticleSearch search) {
        if (search(selector, reinterpret_cast<soArticle*>(self + 0x1E0F0)) == 1U) return reinterpret_cast<Weapon*>(self + 0x1E068);
        if (search(selector, reinterpret_cast<soArticle*>(self + 0x1C114)) == 1U) return reinterpret_cast<Weapon*>(self + 0x1C08C);
        if (search(selector, reinterpret_cast<soArticle*>(self + 0x1A138)) == 1U) return reinterpret_cast<Weapon*>(self + 0x1A0B0);
        if (search(selector, reinterpret_cast<soArticle*>(self + 0x1815C)) == 1U) return reinterpret_cast<Weapon*>(self + 0x180D4);
        return 0;
    }
};
template <> struct PitArticlePool<2> {
    static inline Weapon* find(char* self, PitArticleSelector& selector, PitArticleSearch search) {
        return search(selector, reinterpret_cast<soArticle*>(self + 0xA0)) == 1U ? reinterpret_cast<Weapon*>(self + 0x18) : 0;
    }
};
template <unsigned Kind>
inline soArticle* allocateArticle(char* self, soModuleAccesser* accesser,
                                  const PitArticleActivation<Kind>& activation,
                                  const PitArticleDeactivation& deactivation) {
    PitArticleStatus status;
    if (Kind >= 3) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    PitArticleSelector selector;
    Weapon* owner = PitArticlePool<Kind>::find(self, selector, PitArticleSearch());
    if (!owner) {
        owner = reinterpret_cast<Weapon*>(selector.article);
        if (owner) {
            owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
        }
        if (!owner) {
            selector.release(-1);
            return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        }
        deactivation(owner);
    }
    if (activation(owner, accesser) == 1) {
        selector.release(-1);
        return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
    }
    selector.release(-1);
    return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
}

extern "C" soArticle* fn_112_AEE4(char* self, unsigned int kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(self, accesser, PitArticleActivation<0>(), PitArticleDeactivation());
    case 1: return allocateArticle<1>(self, accesser, PitArticleActivation<1>(), PitArticleDeactivation());
    case 2: return allocateArticle<2>(self, accesser, PitArticleActivation<2>(), PitArticleDeactivation());
    case 3: return allocateArticle<3>(self, accesser, PitArticleActivation<3>(), PitArticleDeactivation());
    case 4: return allocateArticle<4>(self, accesser, PitArticleActivation<4>(), PitArticleDeactivation());
    case 5: return allocateArticle<5>(self, accesser, PitArticleActivation<5>(), PitArticleDeactivation());
    case 6: return allocateArticle<6>(self, accesser, PitArticleActivation<6>(), PitArticleDeactivation());
    case 7: return allocateArticle<7>(self, accesser, PitArticleActivation<7>(), PitArticleDeactivation());
    case 8: return allocateArticle<8>(self, accesser, PitArticleActivation<8>(), PitArticleDeactivation());
    case 9: return allocateArticle<9>(self, accesser, PitArticleActivation<9>(), PitArticleDeactivation());
    case 10: return allocateArticle<10>(self, accesser, PitArticleActivation<10>(), PitArticleDeactivation());
    case 11: return allocateArticle<11>(self, accesser, PitArticleActivation<11>(), PitArticleDeactivation());
    case 12: return allocateArticle<12>(self, accesser, PitArticleActivation<12>(), PitArticleDeactivation());
    case 13: return allocateArticle<13>(self, accesser, PitArticleActivation<13>(), PitArticleDeactivation());
    case 14: return allocateArticle<14>(self, accesser, PitArticleActivation<14>(), PitArticleDeactivation());
    case 15: return allocateArticle<15>(self, accesser, PitArticleActivation<15>(), PitArticleDeactivation());
    case 16: return allocateArticle<16>(self, accesser, PitArticleActivation<16>(), PitArticleDeactivation());
    default: return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
