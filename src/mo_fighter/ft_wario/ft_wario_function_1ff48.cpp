#include <so/article/so_article.h>
#pragma force_active on

extern "C" char* fn_110_2074C(void*, int);

namespace {
struct WarioArticleState {
    bool first;
    bool second;
};
template <unsigned Kind> inline bool allArticlesActive(char* object) {
    for (int i = 0; i < 1; ++i) {
        char* weapon = fn_110_2074C(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(weapon + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" int fn_110_1FF48(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { WarioArticleState state = {false, false}; return !allArticlesActive<0>(object); }
    case 1: { WarioArticleState state = {false, false}; return 0; }
    case 2: { WarioArticleState state = {false, false}; return 0; }
    case 3: { WarioArticleState state = {false, false}; return 0; }
    case 4: { WarioArticleState state = {false, false}; return 0; }
    case 5: { WarioArticleState state = {false, false}; return 0; }
    case 6: { WarioArticleState state = {false, false}; return 0; }
    case 7: { WarioArticleState state = {false, false}; return 0; }
    case 8: { WarioArticleState state = {false, false}; return 0; }
    case 9: { WarioArticleState state = {false, false}; return 0; }
    case 10: { WarioArticleState state = {false, false}; return 0; }
    case 11: { WarioArticleState state = {false, false}; return 0; }
    case 12: { WarioArticleState state = {false, false}; return 0; }
    case 13: { WarioArticleState state = {false, false}; return 0; }
    case 14: { WarioArticleState state = {false, false}; return 0; }
    case 15: { WarioArticleState state = {false, false}; return 0; }
    case 16: { WarioArticleState state = {false, false}; return 0; }
    default: return 0;
    }
}
