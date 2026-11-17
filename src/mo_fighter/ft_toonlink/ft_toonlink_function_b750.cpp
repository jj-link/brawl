#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
void* fn_121_A740();
unsigned int fn_27_3A5C40(void*, Weapon*, soModuleAccesser*, unsigned int);
unsigned int fn_121_A7B0(Weapon*, soModuleAccesser*);
unsigned int fn_121_A46C(Weapon*, soModuleAccesser*);
unsigned int fn_121_AA34(Weapon*, soModuleAccesser*);
unsigned int fn_121_A84C(Weapon*, soModuleAccesser*);
void* fn_27_8D6EC(int, int, int);
soArticle& fn_27_8D78C(void*);
}

class Class_8E20 {
public:
    virtual void fn_121_22F8();
    virtual void fn_121_12B5C();
    virtual void fn_121_14840();
    virtual void fn_121_14838();
    virtual void fn_121_14830();
    virtual void fn_121_14828();
    virtual void fn_121_14820();
    virtual void fn_121_14818();
    virtual void fn_121_14810();
    virtual void fn_121_14808();
    virtual void fn_121_14800();
    virtual void fn_121_147F8();
    virtual void fn_121_147F0();
    virtual void fn_121_147E8();
    virtual void fn_121_14798();
    virtual void fn_121_147E0();
    virtual void fn_121_147D0();
    virtual void fn_121_147C0();
    virtual void fn_121_147B0();
    virtual int fn_121_147A0(int);
};

class ToonResourceIdAccesser {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual unsigned int getMdlResId();
};

namespace {
struct ArticleStatus {
    bool flags[2];
    ArticleStatus() : flags() {}
};
inline int taskId(const StageObject* object) { return object->m_taskId; }

struct Scratch {
    char flags[6];
    char statuses[34];
    soArticle* selectors[6];
};
class ArticleSelector {
public:
    soArticle* article;
    ArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
struct ArticleFlag {
    bool value;
    ArticleFlag() { value = false; }
};
}

extern "C" soArticle& fn_121_B750(char* pool, unsigned kind, soModuleAccesser* accesser) {
    Scratch scratch;
    switch (kind) {
    case 0: {
#define selector (*reinterpret_cast<ArticleSelector*>(&scratch.selectors[5]))
        int zero = 0;
        scratch.statuses[32] = zero;
        scratch.statuses[33] = zero;
        fn_27_8D7C4(&scratch.selectors[5]);
        scratch.flags[5] = zero;
        unsigned int modelId;
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x10790)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x10708);
        else
            owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        modelId = reinterpret_cast<ToonResourceIdAccesser*>(
            accesser->m_enumerationStart->m_resourceModule->getResourceIdAccesser())->getMdlResId();
        if (fn_27_3A5C40(fn_121_A740(), owner, accesser, modelId) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
#undef selector
    }
    case 1: {
#undef selector
#define selector (*reinterpret_cast<ArticleSelector*>(&scratch.selectors[4]))
        int zero = 0;
        scratch.statuses[30] = zero;
        scratch.statuses[31] = zero;
        fn_27_8D7C4(&scratch.selectors[4]);
        scratch.flags[4] = zero;
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0xE7AC)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0xE724);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0xC7D0)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0xC748);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0xA7F4)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0xA76C);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x8818)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x8790);
        else
            owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_121_A7B0(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
#undef selector
    }
    case 2: {
#undef selector
#define selector (*reinterpret_cast<ArticleSelector*>(&scratch.selectors[3]))
        int zero = 0;
        scratch.statuses[28] = zero;
        scratch.statuses[29] = zero;
        fn_27_8D7C4(&scratch.selectors[3]);
        scratch.flags[3] = zero;
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x669C)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x6614);
        else
            owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_121_A46C(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
#undef selector
    }
    case 3: {
#undef selector
#define selector (*reinterpret_cast<ArticleSelector*>(&scratch.selectors[2]))
        int zero = 0;
        scratch.statuses[26] = zero;
        scratch.statuses[27] = zero;
        fn_27_8D7C4(&scratch.selectors[2]);
        scratch.flags[2] = zero;
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x4FC8)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x4F40);
        else
            owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_121_AA34(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
#undef selector
    }
    case 4: {
#undef selector
#define selector (*reinterpret_cast<ArticleSelector*>(&scratch.selectors[1]))
        int zero = 0;
        scratch.statuses[24] = zero;
        scratch.statuses[25] = zero;
        fn_27_8D7C4(&scratch.selectors[1]);
        scratch.flags[1] = zero;
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x1774)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x16EC);
        else
            owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_121_A84C(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
#undef selector
    }
    case 5: {
#undef selector
#define selector (*reinterpret_cast<ArticleSelector*>(&scratch.selectors[0]))
        int zero = 0;
        scratch.statuses[22] = zero;
        scratch.statuses[23] = zero;
        fn_27_8D7C4(&scratch.selectors[0]);
        scratch.flags[0] = zero;
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0xA0)) == true)
            owner = reinterpret_cast<Weapon*>(pool + 0x18);
        else
            owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_121_AA34(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
#undef selector
    }
    case 6: {
        int zero = 0;
        scratch.statuses[20] = zero;
        scratch.statuses[21] = zero;
        if (static_cast<Class_8E20*>(accesser->m_enumerationStart->m_generateArticleManageModule)->fn_121_147A0(6) >= 2)
            return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        void* item = fn_27_8D6EC(0x5B, 6, taskId(&accesser->getStageObject()));
        if (item == 0)
            return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        return fn_27_8D78C(item);
    }
    case 7: { int zero = 0; scratch.statuses[18] = zero; scratch.statuses[19] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 8: { int zero = 0; scratch.statuses[16] = zero; scratch.statuses[17] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 9: { int zero = 0; scratch.statuses[14] = zero; scratch.statuses[15] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 10: { int zero = 0; scratch.statuses[12] = zero; scratch.statuses[13] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 11: { int zero = 0; scratch.statuses[10] = zero; scratch.statuses[11] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 12: { int zero = 0; scratch.statuses[8] = zero; scratch.statuses[9] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 13: { int zero = 0; scratch.statuses[6] = zero; scratch.statuses[7] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 14: { int zero = 0; scratch.statuses[4] = zero; scratch.statuses[5] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 15: { int zero = 0; scratch.statuses[2] = zero; scratch.statuses[3] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 16: { int zero = 0; scratch.statuses[0] = zero; scratch.statuses[1] = zero; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}