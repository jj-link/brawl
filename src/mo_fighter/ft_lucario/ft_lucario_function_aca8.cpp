#pragma force_active on

#include <so/article/so_article.h>

extern "C" void* fn_118_B628(char* object, int index);
extern "C" void* fn_118_B610(void* object, int flag);

namespace {
struct ArticleState {
    bool first;
    bool second;
};

inline bool allActive0(char* object) {
    for (int i = 0; i < 3; ++i) {
        char* article = static_cast<char*>(fn_118_B628(object + 0x1E54, i));
        if (!reinterpret_cast<soArticle*>(article + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}

inline bool allActive1(char* object) {
    for (int i = 0; i < 1; ++i) {
        char* article = static_cast<char*>(fn_118_B610(object + 0xC, i));
        if (!reinterpret_cast<soArticle*>(article + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_118_ACA8(char* object, unsigned int unused, unsigned int kind) {
    switch (kind) {
    case 0: { ArticleState state = {false, false}; return !allActive0(object); }
    case 1: { ArticleState state = {false, false}; return !allActive1(object); }
    case 2: { ArticleState state = {false, false}; return false; }
    case 3: { ArticleState state = {false, false}; return false; }
    case 4: { ArticleState state = {false, false}; return false; }
    case 5: { ArticleState state = {false, false}; return false; }
    case 6: { ArticleState state = {false, false}; return false; }
    case 7: { ArticleState state = {false, false}; return false; }
    case 8: { ArticleState state = {false, false}; return false; }
    case 9: { ArticleState state = {false, false}; return false; }
    case 10: { ArticleState state = {false, false}; return false; }
    case 11: { ArticleState state = {false, false}; return false; }
    case 12: { ArticleState state = {false, false}; return false; }
    case 13: { ArticleState state = {false, false}; return false; }
    case 14: { ArticleState state = {false, false}; return false; }
    case 15: { ArticleState state = {false, false}; return false; }
    case 16: { ArticleState state = {false, false}; return false; }
    default: return false;
    }
}
