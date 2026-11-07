#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_115_8B10(Weapon*, soModuleAccesser*);
unsigned int fn_115_8BC0(Weapon*, soModuleAccesser*);
unsigned int fn_115_9180(Weapon*, soModuleAccesser*);
unsigned int fn_115_93FC(Weapon*, soModuleAccesser*);
}

namespace {
struct DiddyArticleStatus {
    bool flags[2];
    DiddyArticleStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct DiddyArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        switch (Kind) {
        case 0: return fn_115_8B10(owner, accesser);
        case 1: return fn_115_8BC0(owner, accesser);
        case 2: return fn_115_9180(owner, accesser);
        case 3: return fn_115_93FC(owner, accesser);
        default: return false;
        }
    }
};
struct DiddyArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class DiddyArticleSelector {
public:
    soArticle* article;
    DiddyArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct DiddyArticleSearch {
    bool operator()(DiddyArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct DiddyArticlePool {
    static inline Weapon* find(char*, DiddyArticleSelector&, DiddyArticleSearch) { return 0; }
};
template <> struct DiddyArticlePool<0> {
    static inline Weapon* find(char* pool, DiddyArticleSelector& selector, DiddyArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1C650)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1C5C8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1A998)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1A910);
        else owner = 0;
        return owner;
    }
};
template <> struct DiddyArticlePool<1> {
    static inline Weapon* find(char* pool, DiddyArticleSelector& selector, DiddyArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x18398)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18310);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x15DA4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x15D1C);
        else owner = 0;
        return owner;
    }
};
template <> struct DiddyArticlePool<2> {
    static inline Weapon* find(char* pool, DiddyArticleSelector& selector, DiddyArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13DE0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x13D58);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x11E28)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x11DA0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xFE70)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xFDE8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xDEB8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xDE30);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xBF00)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xBE78);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x9F48)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x9EC0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7F90)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7F08);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5FD8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x5F50);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4020)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3F98);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2068)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1FE0);
        else owner = 0;
        return owner;
    }
};
template <> struct DiddyArticlePool<3> {
    static inline Weapon* find(char* pool, DiddyArticleSelector& selector, DiddyArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xA0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const DiddyArticleActivation<Kind>& activation,
                                  const DiddyArticleDeactivation& deactivation) {
    DiddyArticleStatus status;
    if (Kind >= 4) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    DiddyArticleSelector selector;
    Weapon* owner = DiddyArticlePool<Kind>::find(pool, selector, DiddyArticleSearch());
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

extern "C" soArticle& fn_115_A834(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, DiddyArticleActivation<0>(), DiddyArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, DiddyArticleActivation<1>(), DiddyArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, DiddyArticleActivation<2>(), DiddyArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, DiddyArticleActivation<3>(), DiddyArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, DiddyArticleActivation<4>(), DiddyArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, DiddyArticleActivation<5>(), DiddyArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, DiddyArticleActivation<6>(), DiddyArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, DiddyArticleActivation<7>(), DiddyArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, DiddyArticleActivation<8>(), DiddyArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, DiddyArticleActivation<9>(), DiddyArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, DiddyArticleActivation<10>(), DiddyArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, DiddyArticleActivation<11>(), DiddyArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, DiddyArticleActivation<12>(), DiddyArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, DiddyArticleActivation<13>(), DiddyArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, DiddyArticleActivation<14>(), DiddyArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, DiddyArticleActivation<15>(), DiddyArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, DiddyArticleActivation<16>(), DiddyArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
