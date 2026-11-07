#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_91_data_7304[], lbl_91_data_2C90[];
extern const char lbl_91_data_746C[], lbl_91_data_719C[];
extern const char lbl_91_data_7034[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_91_18EC4(void*, Vec3f*);
}

namespace {
struct MarioArticleStatus {
    bool flags[2];
};
}

extern "C" bool fn_91_B9C8(void*, soModuleAccesser* accesser, soArticle* article) {
    switch (article->getArticleId()) {
    case 0: {
        MarioArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_91_data_7304, lbl_91_data_2C90, 1);
        return true;
    }
    case 1: {
        MarioArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_91_data_746C, lbl_91_data_2C90, 1);
        return true;
    }
    case 2: {
        MarioArticleStatus status = {{false, false}};
        __dynamic_cast(article, 0, lbl_91_data_719C, lbl_91_data_2C90, 1);
        return true;
    }
    case 3: {
        MarioArticleStatus status = {{false, false}};
        void* weapon = __dynamic_cast(article, 0, lbl_91_data_7034, lbl_91_data_2C90, 1);
        Vec3f position = accesser->getPostureModule().getPos();
        fn_91_18EC4(weapon, &position);
        return true;
    }
    case 4: { MarioArticleStatus status = {{false, false}}; return true; }
    case 5: { MarioArticleStatus status = {{false, false}}; return true; }
    case 6: { MarioArticleStatus status = {{false, false}}; return true; }
    case 7: { MarioArticleStatus status = {{false, false}}; return true; }
    case 8: { MarioArticleStatus status = {{false, false}}; return true; }
    case 9: { MarioArticleStatus status = {{false, false}}; return true; }
    case 10: { MarioArticleStatus status = {{false, false}}; return true; }
    case 11: { MarioArticleStatus status = {{false, false}}; return true; }
    case 12: { MarioArticleStatus status = {{false, false}}; return true; }
    case 13: { MarioArticleStatus status = {{false, false}}; return true; }
    case 14: { MarioArticleStatus status = {{false, false}}; return true; }
    case 15: { MarioArticleStatus status = {{false, false}}; return true; }
    case 16: { MarioArticleStatus status = {{false, false}}; return true; }
    default: return false;
    }
}