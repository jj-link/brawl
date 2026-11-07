#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
void* fn_116_21410(void* object, int index);
void* fn_116_21428(void* object, int index);
void* fn_116_21460(void* object, int index);
}

namespace {
struct ArticleSearchStatus {
    bool first;
    bool second;
};

inline bool allActive0(unsigned char* object) {
    for (int i = 0; i < 2; ++i) {
        void* member = fn_116_21460(object + 0x63A8, i);
        soArticle* article = reinterpret_cast<soArticle*>(static_cast<unsigned char*>(member) + 0x88);
        if (!article->isActiveArticle()) return false;
    }
    return true;
}

inline bool allActive1(unsigned char* object) {
    for (int i = 0; i < 3; ++i) {
        void* member = fn_116_21428(object + 0x1F94, i);
        soArticle* article = reinterpret_cast<soArticle*>(static_cast<unsigned char*>(member) + 0x88);
        if (!article->isActiveArticle()) return false;
    }
    return true;
}

inline bool allActive2(unsigned char* object) {
    for (int i = 0; i < 1; ++i) {
        void* member = fn_116_21410(object + 0xC, i);
        soArticle* article = reinterpret_cast<soArticle*>(static_cast<unsigned char*>(member) + 0x88);
        if (!article->isActiveArticle()) return false;
    }
    return true;
}
}

extern "C" int fn_116_20A00(void* object, unsigned, unsigned kind) {
    switch (kind) {
    case 0: { ArticleSearchStatus status = {false, false}; return !allActive0(static_cast<unsigned char*>(object)); }
    case 1: { ArticleSearchStatus status = {false, false}; return !allActive1(static_cast<unsigned char*>(object)); }
    case 2: { ArticleSearchStatus status = {false, false}; return !allActive2(static_cast<unsigned char*>(object)); }
    case 3: { ArticleSearchStatus status = {false, false}; return 0; }
    case 4: { ArticleSearchStatus status = {false, false}; return 0; }
    case 5: { ArticleSearchStatus status = {false, false}; return 0; }
    case 6: { ArticleSearchStatus status = {false, false}; return 0; }
    case 7: { ArticleSearchStatus status = {false, false}; return 0; }
    case 8: { ArticleSearchStatus status = {false, false}; return 0; }
    case 9: { ArticleSearchStatus status = {false, false}; return 0; }
    case 10: { ArticleSearchStatus status = {false, false}; return 0; }
    case 11: { ArticleSearchStatus status = {false, false}; return 0; }
    case 12: { ArticleSearchStatus status = {false, false}; return 0; }
    case 13: { ArticleSearchStatus status = {false, false}; return 0; }
    case 14: { ArticleSearchStatus status = {false, false}; return 0; }
    case 15: { ArticleSearchStatus status = {false, false}; return 0; }
    case 16: { ArticleSearchStatus status = {false, false}; return 0; }
    default: return 0;
    }
}
