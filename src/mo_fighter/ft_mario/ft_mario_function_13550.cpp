// fn_91_13550: Mario article allocator (17-way kind switch, only kind 0 is populated).
#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_91_13358(Weapon*, soModuleAccesser*);
}

namespace {
struct MarioStatus {
    bool flags[2];
    MarioStatus() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct MarioActivation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_91_13358(owner, accesser);
    }
};
struct MarioDeactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class MarioSelector {
public:
    soArticle* article;
    MarioSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct MarioSearch {
    bool operator()(MarioSelector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct MarioPool {
    static inline Weapon* find(char*, MarioSelector&, MarioSearch) { return 0; }
};
template <> struct MarioPool<0> {
    static inline Weapon* find(char* pool, MarioSelector& selector, MarioSearch search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x14e68)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x14de0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13014)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x12f8c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x111c0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x11138);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xf36c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xf2e4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xd518)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xd490);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xb6c4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xb63c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x9870)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x97e8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7a1c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7994);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5bc8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x5b40);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x3d74)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3cec);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x1f20)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1e98);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xcc)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x44);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocate(char* pool, soModuleAccesser* accesser,
                           const MarioActivation<Kind>& activation,
                           const MarioDeactivation& deactivation) {
    MarioStatus status;
    if (Kind >= 1) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    MarioSelector selector;
    Weapon* owner = MarioPool<Kind>::find(pool, selector, MarioSearch());
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

extern "C" soArticle& fn_91_13550(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocate<0>(pool, accesser, MarioActivation<0>(), MarioDeactivation());
    case 1: return allocate<1>(pool, accesser, MarioActivation<1>(), MarioDeactivation());
    case 2: return allocate<2>(pool, accesser, MarioActivation<2>(), MarioDeactivation());
    case 3: return allocate<3>(pool, accesser, MarioActivation<3>(), MarioDeactivation());
    case 4: return allocate<4>(pool, accesser, MarioActivation<4>(), MarioDeactivation());
    case 5: return allocate<5>(pool, accesser, MarioActivation<5>(), MarioDeactivation());
    case 6: return allocate<6>(pool, accesser, MarioActivation<6>(), MarioDeactivation());
    case 7: return allocate<7>(pool, accesser, MarioActivation<7>(), MarioDeactivation());
    case 8: return allocate<8>(pool, accesser, MarioActivation<8>(), MarioDeactivation());
    case 9: return allocate<9>(pool, accesser, MarioActivation<9>(), MarioDeactivation());
    case 10: return allocate<10>(pool, accesser, MarioActivation<10>(), MarioDeactivation());
    case 11: return allocate<11>(pool, accesser, MarioActivation<11>(), MarioDeactivation());
    case 12: return allocate<12>(pool, accesser, MarioActivation<12>(), MarioDeactivation());
    case 13: return allocate<13>(pool, accesser, MarioActivation<13>(), MarioDeactivation());
    case 14: return allocate<14>(pool, accesser, MarioActivation<14>(), MarioDeactivation());
    case 15: return allocate<15>(pool, accesser, MarioActivation<15>(), MarioDeactivation());
    case 16: return allocate<16>(pool, accesser, MarioActivation<16>(), MarioDeactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
