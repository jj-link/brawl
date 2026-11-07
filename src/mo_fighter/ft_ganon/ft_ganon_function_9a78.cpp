#include <so/article/so_article.h>
#pragma force_active on

extern "C" void* fn_109_A3DC(void*, int);
extern "C" void* fn_109_A3C4(void*, int);

namespace {
struct GanonArticleState {
    bool first;
    bool second;
};
template <unsigned Kind>
inline bool allActive(char* object) {
    for (int i = 0; i < 1; ++i) {
        void* w = (Kind == 0) ? fn_109_A3DC(object + 0x16E0, i)
                              : fn_109_A3C4(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(w) + 0x88)->isActiveArticle())
            return false;
    }
    return true;
}
}

extern "C" bool fn_109_9A78(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { GanonArticleState state = {false, false}; return !allActive<0>(object); }
    case 1: { GanonArticleState state = {false, false}; return !allActive<1>(object); }
    case 2: { GanonArticleState state = {false, false}; return false; }
    case 3: { GanonArticleState state = {false, false}; return false; }
    case 4: { GanonArticleState state = {false, false}; return false; }
    case 5: { GanonArticleState state = {false, false}; return false; }
    case 6: { GanonArticleState state = {false, false}; return false; }
    case 7: { GanonArticleState state = {false, false}; return false; }
    case 8: { GanonArticleState state = {false, false}; return false; }
    case 9: { GanonArticleState state = {false, false}; return false; }
    case 10: { GanonArticleState state = {false, false}; return false; }
    case 11: { GanonArticleState state = {false, false}; return false; }
    case 12: { GanonArticleState state = {false, false}; return false; }
    case 13: { GanonArticleState state = {false, false}; return false; }
    case 14: { GanonArticleState state = {false, false}; return false; }
    case 15: { GanonArticleState state = {false, false}; return false; }
    case 16: { GanonArticleState state = {false, false}; return false; }
    default: return false;
    }
}