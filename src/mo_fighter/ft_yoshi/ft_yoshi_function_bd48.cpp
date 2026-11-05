#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_95_A490(Weapon*, soModuleAccesser*);
bool fn_95_A5CC(Weapon*, soModuleAccesser*);
bool fn_95_A8BC(Weapon*, soModuleAccesser*);
bool fn_95_A974(Weapon*, soModuleAccesser*);
bool fn_95_ABC4(Weapon*, soModuleAccesser*);
}
namespace {
struct Status {
    bool flags[2];
    Status() { flags[0] = false; flags[1] = false; }
};
template <unsigned Kind> struct Activation {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_95_A490(owner, accesser);
    }
};
template <> struct Activation<1> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_95_A5CC(owner, accesser);
    }
};
template <> struct Activation<2> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_95_A8BC(owner, accesser);
    }
};
template <> struct Activation<3> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_95_A974(owner, accesser);
    }
};
template <> struct Activation<4> {
    unsigned int operator()(Weapon* owner, soModuleAccesser* accesser) const {
        return fn_95_ABC4(owner, accesser);
    }
};
struct Deactivation {
    void operator()(Weapon* owner) const { owner->deactivateArticle(); }
};
class Selector {
public:
    soArticle* article;
    Selector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct Search {
    bool operator()(Selector& selector, soArticle* candidate) const {
        return selector.select(candidate);
    }
};
template <unsigned Kind> struct Pool {
    static inline Weapon* find(char*, Selector&, Search) { return 0; }
};
template <> struct Pool<0> {
    static inline Weapon* find(char* pool, Selector& selector, Search search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x17e4c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x17dc4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x15e6c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x15de4);
        else owner = 0;
        return owner;
    }
};
template <> struct Pool<1> {
    static inline Weapon* find(char* pool, Selector& selector, Search search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x13e64)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x13ddc);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x11e68)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x11de0);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xfe6c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xfde4);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xde70)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xdde8);
        else owner = 0;
        return owner;
    }
};
template <> struct Pool<2> {
    static inline Weapon* find(char* pool, Selector& selector, Search search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0xbd48)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xbcc0);
        else owner = 0;
        return owner;
    }
};
template <> struct Pool<3> {
    static inline Weapon* find(char* pool, Selector& selector, Search search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x9e0c)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x9d84);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x7ed8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7e50);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x5fa4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x5f1c);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0x4070)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x3fe8);
        else owner = 0;
        return owner;
    }
};
template <> struct Pool<4> {
    static inline Weapon* find(char* pool, Selector& selector, Search search) {
        Weapon* owner;
        if (search(selector, reinterpret_cast<soArticle*>(pool + 0x2080)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1ff8);
        else if (search(selector, reinterpret_cast<soArticle*>(pool + 0xa4)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1c);
        else owner = 0;
        return owner;
    }
};
template <unsigned Kind>
inline soArticle& allocate(char* pool, soModuleAccesser* accesser,
                           const Activation<Kind>& activation,
                           const Deactivation& deactivation) {
    Status status;
    if (Kind >= 5) return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    Selector selector;
    Weapon* owner = Pool<Kind>::find(pool, selector, Search());
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
extern "C" soArticle& fn_95_BD48(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: return allocate<0>(pool, accesser, Activation<0>(), Deactivation());
    case 1: return allocate<1>(pool, accesser, Activation<1>(), Deactivation());
    case 2: return allocate<2>(pool, accesser, Activation<2>(), Deactivation());
    case 3: return allocate<3>(pool, accesser, Activation<3>(), Deactivation());
    case 4: return allocate<4>(pool, accesser, Activation<4>(), Deactivation());
    case 5: return allocate<5>(pool, accesser, Activation<5>(), Deactivation());
    case 6: return allocate<6>(pool, accesser, Activation<6>(), Deactivation());
    case 7: return allocate<7>(pool, accesser, Activation<7>(), Deactivation());
    case 8: return allocate<8>(pool, accesser, Activation<8>(), Deactivation());
    case 9: return allocate<9>(pool, accesser, Activation<9>(), Deactivation());
    case 10: return allocate<10>(pool, accesser, Activation<10>(), Deactivation());
    case 11: return allocate<11>(pool, accesser, Activation<11>(), Deactivation());
    case 12: return allocate<12>(pool, accesser, Activation<12>(), Deactivation());
    case 13: return allocate<13>(pool, accesser, Activation<13>(), Deactivation());
    case 14: return allocate<14>(pool, accesser, Activation<14>(), Deactivation());
    case 15: return allocate<15>(pool, accesser, Activation<15>(), Deactivation());
    case 16: return allocate<16>(pool, accesser, Activation<16>(), Deactivation());
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}