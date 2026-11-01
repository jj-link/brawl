#include <so/article/so_article.h>
#pragma force_active on

extern "C" void* fn_122_23AC8(void*, int);

namespace {
struct SnakeArticleState { bool first; bool second; };
inline bool allArticlesActive(char* object) {
    for (int i = 0; i < 2; ++i) {
        void* weapon = fn_122_23AC8(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(weapon) + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_122_232EC(char* object, unsigned int, unsigned int kind) {
    switch (kind) {
    case 0: { SnakeArticleState s = {false, false}; return !allArticlesActive(object); }
    case 1: { SnakeArticleState s = {false, false}; return false; }
    case 2: { SnakeArticleState s = {false, false}; return false; }
    case 3: { SnakeArticleState s = {false, false}; return false; }
    case 4: { SnakeArticleState s = {false, false}; return false; }
    case 5: { SnakeArticleState s = {false, false}; return false; }
    case 6: { SnakeArticleState s = {false, false}; return false; }
    case 7: { SnakeArticleState s = {false, false}; return false; }
    case 8: { SnakeArticleState s = {false, false}; return false; }
    case 9: { SnakeArticleState s = {false, false}; return false; }
    case 10: { SnakeArticleState s = {false, false}; return false; }
    case 11: { SnakeArticleState s = {false, false}; return false; }
    case 12: { SnakeArticleState s = {false, false}; return false; }
    case 13: { SnakeArticleState s = {false, false}; return false; }
    case 14: { SnakeArticleState s = {false, false}; return false; }
    case 15: { SnakeArticleState s = {false, false}; return false; }
    case 16: { SnakeArticleState s = {false, false}; return false; }
    default: return false;
    }
}
