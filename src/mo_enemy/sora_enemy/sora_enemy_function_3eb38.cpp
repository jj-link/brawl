#include <so/article/so_article.h>
#pragma force_active on

extern "C" void* fn_41_3F304(void*, int);

namespace {
struct ArticleState {
    bool first;
    bool second;
};
}

extern "C" bool fn_41_3EB38(char* object, unsigned int unused, unsigned int kind) {
    switch (kind) {
    case 0: {
        ArticleState state = {false, false};
        int result;
        int i;
        for (i = 0; i < 2; ++i) {
            char* article = static_cast<char*>(fn_41_3F304(object + 0xC, i));
            if (!reinterpret_cast<soArticle*>(article + 0x94)->isActiveArticle()) {
                result = 0;
                goto done;
            }
        }
        result = 1;
    done:
        return result == 0;
    }
    case 1: { ArticleState state = {false, false}; return false; }
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
    default:
        return false;
    }
}
