#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
void* fn_27_8D6EC(int, int, int);
soArticle* fn_27_8D78C(void*);
void* fn_93_A740();
bool fn_27_2DE9A8(void*, Weapon*, soModuleAccesser*, u32);
bool fn_93_A7B0(Weapon*, soModuleAccesser*);
bool fn_93_A46C(Weapon*, soModuleAccesser*);
bool fn_93_A84C(Weapon*, soModuleAccesser*);
bool fn_93_AA34(Weapon*, soModuleAccesser*);
}

class Class_8D00 {
public:
    virtual void fn_93_22F8();
    virtual void fn_93_12B10();
    virtual void fn_93_147F4();
    virtual void fn_93_147EC();
    virtual void fn_93_147E4();
    virtual void fn_93_147DC();
    virtual void fn_93_147D4();
    virtual void fn_93_147CC();
    virtual void fn_93_147C4();
    virtual void fn_93_147BC();
    virtual void fn_93_147B4();
    virtual void fn_93_147AC();
    virtual void fn_93_147A4();
    virtual void fn_93_1479C();
    virtual void fn_93_1474C();
    virtual void fn_93_14794();
    virtual void fn_93_14784();
    virtual void fn_93_14774();
    virtual void fn_93_14764();
    virtual int fn_93_14754(int);
};

namespace {
inline int taskId(const StageObject* object) { return object->m_taskId; }
struct LinkStatus {
    bool flags[2];
    LinkStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct LinkActivation {
    unsigned int operator()(Weapon*, soModuleAccesser*) const { return 0; }
};
template <> struct LinkActivation<0> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        u32 id = accesser->getResourceModule().getResourceIdAccesser()->getEtcResId();
        return fn_27_2DE9A8(fn_93_A740(), owner, accesser, id);
    }
};
template <> struct LinkActivation<1> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_93_A7B0(owner, accesser);
    }
};
template <> struct LinkActivation<2> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_93_A46C(owner, accesser);
    }
};
template <> struct LinkActivation<3> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_93_A84C(owner, accesser);
    }
};
template <> struct LinkActivation<4> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_93_AA34(owner, accesser);
    }
};
template <> struct LinkActivation<5> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_93_AA34(owner, accesser);
    }
};
struct LinkDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class LinkSelector {
public:
    soArticle* article;
    LinkSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct LinkSearch {
    bool operator()(LinkSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct LinkPool {
    static inline Weapon* find(char*, LinkSelector&, LinkSearch) { return 0; }
};
template <> struct LinkPool<0> {
    static inline Weapon* find(char* pool, LinkSelector& selector, LinkSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x10790)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x10708);
        else owner = 0;
        return owner;
    }
};
template <> struct LinkPool<1> {
    static inline Weapon* find(char* pool, LinkSelector& selector, LinkSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xe7ac)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xe724);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xc7d0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xc748);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xa7f4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xa76c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x8818)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x8790);
        else owner = 0;
        return owner;
    }
};
template <> struct LinkPool<2> {
    static inline Weapon* find(char* pool, LinkSelector& selector, LinkSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x669c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x6614);
        else owner = 0;
        return owner;
    }
};
template <> struct LinkPool<3> {
    static inline Weapon* find(char* pool, LinkSelector& selector, LinkSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2e48)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x2dc0);
        else owner = 0;
        return owner;
    }
};
template <> struct LinkPool<4> {
    static inline Weapon* find(char* pool, LinkSelector& selector, LinkSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1774)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x16ec);
        else owner = 0;
        return owner;
    }
};
template <> struct LinkPool<5> {
    static inline Weapon* find(char* pool, LinkSelector& selector, LinkSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xa0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocateLink(char* pool, soModuleAccesser* accesser,
                               const LinkActivation<Kind>& activation,
                               const LinkDeactivation& deactivation) {
    LinkStatus status;
    if (Kind >= 7) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    if (Kind == 6) {
        Class_8D00* module = reinterpret_cast<Class_8D00*>(accesser->m_enumerationStart->m_generateArticleManageModule);
        if (module->fn_93_14754(6) >= 2)
            return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        void* item = fn_27_8D6EC(0x55, 6, taskId(&accesser->getStageObject()));
        return item == 0 ? *reinterpret_cast<soArticle*>(lbl_27_bss_1CC) : *fn_27_8D78C(item);
    }
    LinkSelector selector;
    Weapon* owner = LinkPool<Kind>::find(pool, selector, LinkSearch());
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

extern "C" soArticle& fn_93_B754(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateLink<0>(pool, accesser, LinkActivation<0>(), LinkDeactivation());
    case 1: return allocateLink<1>(pool, accesser, LinkActivation<1>(), LinkDeactivation());
    case 2: return allocateLink<2>(pool, accesser, LinkActivation<2>(), LinkDeactivation());
    case 3: return allocateLink<3>(pool, accesser, LinkActivation<3>(), LinkDeactivation());
    case 4: return allocateLink<4>(pool, accesser, LinkActivation<4>(), LinkDeactivation());
    case 5: return allocateLink<5>(pool, accesser, LinkActivation<5>(), LinkDeactivation());
    case 6: return allocateLink<6>(pool, accesser, LinkActivation<6>(), LinkDeactivation());
    case 7: return allocateLink<7>(pool, accesser, LinkActivation<7>(), LinkDeactivation());
    case 8: return allocateLink<8>(pool, accesser, LinkActivation<8>(), LinkDeactivation());
    case 9: return allocateLink<9>(pool, accesser, LinkActivation<9>(), LinkDeactivation());
    case 10: return allocateLink<10>(pool, accesser, LinkActivation<10>(), LinkDeactivation());
    case 11: return allocateLink<11>(pool, accesser, LinkActivation<11>(), LinkDeactivation());
    case 12: return allocateLink<12>(pool, accesser, LinkActivation<12>(), LinkDeactivation());
    case 13: return allocateLink<13>(pool, accesser, LinkActivation<13>(), LinkDeactivation());
    case 14: return allocateLink<14>(pool, accesser, LinkActivation<14>(), LinkDeactivation());
    case 15: return allocateLink<15>(pool, accesser, LinkActivation<15>(), LinkDeactivation());
    case 16: return allocateLink<16>(pool, accesser, LinkActivation<16>(), LinkDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
