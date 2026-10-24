#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
bool fn_93_CC30(soArticle*);
char* fn_93_185D8(void*, int);
}

namespace {
struct LinkArticleCountState {
    bool first;
    bool second;
};
template <unsigned Kind> struct LinkArticleCounter {
    bool (*predicate)(soArticle*);
    unsigned int accepted;
    unsigned int rejected;

    explicit LinkArticleCounter(bool (*test)(soArticle*))
        : predicate(test), accepted(0), rejected(0) {}
    inline void operator()(soArticle* article) {
        if (predicate(article) == true) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};
template <unsigned Kind> inline LinkArticleCounter<Kind> countArticles(char* object) {
    LinkArticleCounter<Kind> counter(fn_93_CC30);
    for (int i = 0; i < 1; ++i) {
        char* weapon = fn_93_185D8(object + 0xC, i);
        counter(reinterpret_cast<soArticle*>(weapon + 0x88));
    }
    return counter;
}
}

extern "C" unsigned int fn_93_17F94(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { LinkArticleCountState state = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { LinkArticleCountState state = {false, false}; return 0; }
    case 2: { LinkArticleCountState state = {false, false}; return 0; }
    case 3: { LinkArticleCountState state = {false, false}; return 0; }
    case 4: { LinkArticleCountState state = {false, false}; return 0; }
    case 5: { LinkArticleCountState state = {false, false}; return 0; }
    case 6: { LinkArticleCountState state = {false, false}; return 0; }
    case 7: { LinkArticleCountState state = {false, false}; return 0; }
    case 8: { LinkArticleCountState state = {false, false}; return 0; }
    case 9: { LinkArticleCountState state = {false, false}; return 0; }
    case 10: { LinkArticleCountState state = {false, false}; return 0; }
    case 11: { LinkArticleCountState state = {false, false}; return 0; }
    case 12: { LinkArticleCountState state = {false, false}; return 0; }
    case 13: { LinkArticleCountState state = {false, false}; return 0; }
    case 14: { LinkArticleCountState state = {false, false}; return 0; }
    case 15: { LinkArticleCountState state = {false, false}; return 0; }
    case 16: { LinkArticleCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
