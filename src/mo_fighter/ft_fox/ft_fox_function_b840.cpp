#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
unsigned int fn_97_A324(void*, void*);
unsigned int fn_97_A440(void*, void*);
unsigned int fn_97_A580(void*, void*);
void* fn_97_A3D0();
unsigned int fn_27_31EA68(void*, void*, void*, int, void*, int);
}

namespace {
class Class_789C {
public:
    virtual void fn_97_8138();
    virtual void fn_97_10664();
    virtual void fn_97_10B20();
    virtual void fn_97_10B1C();
    virtual void fn_97_10B18();
    virtual void fn_97_10B14();
    virtual void fn_97_10B0C();
    virtual void fn_97_10B54();
    virtual void fn_97_10B4C();
    virtual void fn_97_10B44();
    virtual void fn_97_10B3C();
    virtual void fn_97_10B34();
    virtual void fn_97_10ACC();
    virtual void fn_97_10B00();
    virtual void fn_97_10AF4();
    virtual void* fn_97_10AEC();
};

struct FoxModulePad {
    char pad[8];
};

class FoxModuleChain : public FoxModulePad {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4();
};

class FoxArticleSelector {
public:
    soArticle* article;
    FoxArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};

struct FoxArticleSearch {
    bool operator()(FoxArticleSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};

struct FoxArticleDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};

template <unsigned Kind> struct FoxArticleActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        if (Kind == 0) return fn_97_A324(owner, accesser);
        if (Kind == 1) {
            char* p = *reinterpret_cast<char**>(reinterpret_cast<char*>(accesser) + 0xd8);
            char* module = *reinterpret_cast<char**>(p);
            void* next = reinterpret_cast<FoxModuleChain*>(module)->slot4();
            void* chain = reinterpret_cast<Class_789C*>(next)->fn_97_10AEC();
            void* base = fn_97_A3D0();
            return fn_27_31EA68(base, owner, accesser, 0x3f, chain, 0x7000a);
        }
        if (Kind == 2) return fn_97_A440(owner, accesser);
        return fn_97_A580(owner, accesser);
    }
};

template <unsigned Kind> struct FoxArticlePool {
    static inline Weapon* find(char*, FoxArticleSelector&, FoxArticleSearch) { return 0; }
};
template <> struct FoxArticlePool<0> {
    static inline Weapon* find(char* pool, FoxArticleSelector& selector, FoxArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0x12F20)) == true ? reinterpret_cast<Weapon*>(pool + 0x12E98) : 0;
        return owner;
    }
};
template <> struct FoxArticlePool<1> {
    static inline Weapon* find(char* pool, FoxArticleSelector& selector, FoxArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x10D9C)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x10D14);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xEC20)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xEB98);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xCAA4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xCA1C);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xA928)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xA8A0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x87AC)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x8724);
        else owner = 0;
        return owner;
    }
};
template <> struct FoxArticlePool<2> {
    static inline Weapon* find(char* pool, FoxArticleSelector& selector, FoxArticleSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x69AC)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x6924);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4BC4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x4B3C);
        else owner = 0;
        return owner;
    }
};
template <> struct FoxArticlePool<3> {
    static inline Weapon* find(char* pool, FoxArticleSelector& selector, FoxArticleSearch search) {
        Weapon* owner = search(selector, reinterpret_cast<soArticle*>(pool + 0xA0)) == true ? reinterpret_cast<Weapon*>(pool + 0x18) : 0;
        return owner;
    }
};

template <unsigned Kind>
inline soArticle& allocateArticle(char* pool, soModuleAccesser* accesser,
                                  const FoxArticleActivation<Kind>& activation,
                                  const FoxArticleDeactivation& deactivation) {
    struct FoxArticleStatus {
        bool flags[2];
        FoxArticleStatus() { flags[0] = false; flags[1] = false; }
    } status;
    if (Kind >= 4) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    FoxArticleSelector selector;
    Weapon* owner = FoxArticlePool<Kind>::find(pool, selector, FoxArticleSearch());
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

extern "C" soArticle& fn_97_B840(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocateArticle<0>(pool, accesser, FoxArticleActivation<0>(), FoxArticleDeactivation());
    case 1: return allocateArticle<1>(pool, accesser, FoxArticleActivation<1>(), FoxArticleDeactivation());
    case 2: return allocateArticle<2>(pool, accesser, FoxArticleActivation<2>(), FoxArticleDeactivation());
    case 3: return allocateArticle<3>(pool, accesser, FoxArticleActivation<3>(), FoxArticleDeactivation());
    case 4: return allocateArticle<4>(pool, accesser, FoxArticleActivation<4>(), FoxArticleDeactivation());
    case 5: return allocateArticle<5>(pool, accesser, FoxArticleActivation<5>(), FoxArticleDeactivation());
    case 6: return allocateArticle<6>(pool, accesser, FoxArticleActivation<6>(), FoxArticleDeactivation());
    case 7: return allocateArticle<7>(pool, accesser, FoxArticleActivation<7>(), FoxArticleDeactivation());
    case 8: return allocateArticle<8>(pool, accesser, FoxArticleActivation<8>(), FoxArticleDeactivation());
    case 9: return allocateArticle<9>(pool, accesser, FoxArticleActivation<9>(), FoxArticleDeactivation());
    case 10: return allocateArticle<10>(pool, accesser, FoxArticleActivation<10>(), FoxArticleDeactivation());
    case 11: return allocateArticle<11>(pool, accesser, FoxArticleActivation<11>(), FoxArticleDeactivation());
    case 12: return allocateArticle<12>(pool, accesser, FoxArticleActivation<12>(), FoxArticleDeactivation());
    case 13: return allocateArticle<13>(pool, accesser, FoxArticleActivation<13>(), FoxArticleDeactivation());
    case 14: return allocateArticle<14>(pool, accesser, FoxArticleActivation<14>(), FoxArticleDeactivation());
    case 15: return allocateArticle<15>(pool, accesser, FoxArticleActivation<15>(), FoxArticleDeactivation());
    case 16: return allocateArticle<16>(pool, accesser, FoxArticleActivation<16>(), FoxArticleDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
