#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
void* fn_110_AA48(void*, int);
void* fn_110_AA60(void*, int);
}

namespace {
struct WarioArticleState {
    bool first;
    bool second;
};
template <unsigned Kind> inline bool allArticlesActive(char* object) {
    for (int i = 0; i < 1; ++i) {
        char* weapon = Kind == 0 ? static_cast<char*>(fn_110_AA60(object + 0x20B8, i))
                                : static_cast<char*>(fn_110_AA48(object + 0xC, i));
        if (!reinterpret_cast<soArticle*>(weapon + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

extern "C" bool fn_110_A0FC(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { WarioArticleState state = {false, false}; return !allArticlesActive<0>(object); }
    case 1: { WarioArticleState state = {false, false}; return !allArticlesActive<1>(object); }
    case 2: { WarioArticleState state = {false, false}; return false; }
    case 3: { WarioArticleState state = {false, false}; return false; }
    case 4: { WarioArticleState state = {false, false}; return false; }
    case 5: { WarioArticleState state = {false, false}; return false; }
    case 6: { WarioArticleState state = {false, false}; return false; }
    case 7: { WarioArticleState state = {false, false}; return false; }
    case 8: { WarioArticleState state = {false, false}; return false; }
    case 9: { WarioArticleState state = {false, false}; return false; }
    case 10: { WarioArticleState state = {false, false}; return false; }
    case 11: { WarioArticleState state = {false, false}; return false; }
    case 12: { WarioArticleState state = {false, false}; return false; }
    case 13: { WarioArticleState state = {false, false}; return false; }
    case 14: { WarioArticleState state = {false, false}; return false; }
    case 15: { WarioArticleState state = {false, false}; return false; }
    case 16: { WarioArticleState state = {false, false}; return false; }
    default: return false;
    }
}
