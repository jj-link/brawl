#include <wn/weapon.h>
#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*);
void fn_27_8D7D0(void*, short);
bool fn_27_8D810(void*, soArticle*);
bool fn_94_94F0(Weapon*, soModuleAccesser*);
bool fn_94_96D4(Weapon*, soModuleAccesser*);
bool fn_94_9818(Weapon*, soModuleAccesser*);
bool fn_94_9954(Weapon*, soModuleAccesser*);
bool fn_94_9A90(Weapon*, soModuleAccesser*);
bool fn_94_9BC4(Weapon*, soModuleAccesser*);
bool fn_94_9D2C(Weapon*, soModuleAccesser*);
bool fn_94_A430(Weapon*, soModuleAccesser*);
}

namespace {
class ArticleSelector {
public:
    soArticle* article;
    ArticleSelector() { fn_27_8D7C4(this); }
    void release(short destroy) { fn_27_8D7D0(this, destroy); }
    bool select(soArticle* candidate) { return fn_27_8D810(this, candidate); }
};
}

extern "C" soArticle& fn_94_B460(char* pool, unsigned kind, soModuleAccesser* accesser) {
    switch (kind) {
    case 0: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x1BF14)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1BE8C);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x1A6E8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x1A660);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x18EBC)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18E34);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x17690)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x17608);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_94F0(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 1: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x15BE0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x15B58);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x14144)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x140BC);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x126A8)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x12620);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_96D4(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 2: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x10D70)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x10CE8);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0xF448)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xF3C0);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0xDB20)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xDA98);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_9818(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 3: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0xC218)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xC190);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_9A90(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 4: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0xAA44)) == true) owner = reinterpret_cast<Weapon*>(pool + 0xA9BC);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x9278)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x91F0);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x7AAC)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x7A24);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x62E0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x6258);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_9BC4(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 5: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x4A94)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x4A0C);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_9D2C(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 6: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0x3164)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x30DC);
        else if (selector.select(reinterpret_cast<soArticle*>(pool + 0x183C)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x17B4);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_9954(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 7: {
        bool status[2] = {false, false};
        ArticleSelector selector;
        bool flag[1] = {false};
        Weapon* owner;
        if (selector.select(reinterpret_cast<soArticle*>(pool + 0xA0)) == true) owner = reinterpret_cast<Weapon*>(pool + 0x18);
        else owner = 0;
        if (owner == 0) {
            owner = static_cast<Weapon*>(selector.article);
            if (owner == 0) {
                selector.release(-1);
                return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_94_A430(owner, accesser) == true) {
            selector.release(-1);
            return static_cast<soArticle&>(*owner);
        }
        selector.release(-1);
        return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 8: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 9: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 10: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 11: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 12: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 13: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 14: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 15: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 16: { bool status[2] = {false, false}; return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    default: return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
