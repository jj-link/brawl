#pragma force_active on

#include <so/article/so_article.h>

extern "C" void* fn_119_A928(void*, int);

namespace {
struct ArticleState {
    bool first;
    bool second;
};

inline bool allActive(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* w = fn_119_A928(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(w) + 0x88)->isActiveArticle())
            return false;
    }
    return true;
}
}

extern "C" bool fn_119_A0D0(char* object, unsigned int unused, unsigned int kind) {
    switch (kind) {
    case 0: { ArticleState st = {false, false}; return !allActive(object); }
    case 1: { ArticleState st = {false, false}; return false; }
    case 2: { ArticleState st = {false, false}; return false; }
    case 3: { ArticleState st = {false, false}; return false; }
    case 4: { ArticleState st = {false, false}; return false; }
    case 5: { ArticleState st = {false, false}; return false; }
    case 6: { ArticleState st = {false, false}; return false; }
    case 7: { ArticleState st = {false, false}; return false; }
    case 8: { ArticleState st = {false, false}; return false; }
    case 9: { ArticleState st = {false, false}; return false; }
    case 10: { ArticleState st = {false, false}; return false; }
    case 11: { ArticleState st = {false, false}; return false; }
    case 12: { ArticleState st = {false, false}; return false; }
    case 13: { ArticleState st = {false, false}; return false; }
    case 14: { ArticleState st = {false, false}; return false; }
    case 15: { ArticleState st = {false, false}; return false; }
    case 16: { ArticleState st = {false, false}; return false; }
    default: return false;
    }
}
