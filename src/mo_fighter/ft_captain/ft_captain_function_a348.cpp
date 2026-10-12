// Preserve the original REL's four-byte-aligned article-count dispatch table.
#pragma section data_type ".data$captainA348" ".bss"

#include <so/article/so_article.h>

extern "C" {
bool fn_100_AA4C(soArticle*);
char* fn_100_AA5C(void*, int);
char* fn_100_AA74(void*, int);
}

namespace {
struct CaptainArticleCountState {
    bool first;
    bool second;
};
template <unsigned Kind> struct CaptainArticleCounter {
    bool (*predicate)(soArticle*);
    unsigned int accepted;
    unsigned int rejected;

    explicit CaptainArticleCounter(bool (*test)(soArticle*))
        : predicate(test), accepted(0), rejected(0) {}
    inline void operator()(soArticle* article) {
        if (predicate(article) == true) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};
template <unsigned Kind> inline CaptainArticleCounter<Kind> countArticles(char* object) {
    CaptainArticleCounter<Kind> counter(fn_100_AA4C);
    for (int i = 0; i < 1; ++i) {
        char* weapon = Kind == 0 ? fn_100_AA74(object + 0x1F40, i)
                                : fn_100_AA5C(object + 0xC, i);
        counter(reinterpret_cast<soArticle*>(weapon + 0x88));
    }
    return counter;
}
}

// The operation parameter is unused; kind selects a fixed-capacity article pool.
extern "C" unsigned int fn_100_A348(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { CaptainArticleCountState state = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { CaptainArticleCountState state = {false, false}; return countArticles<1>(object).accepted; }
    case 2: { CaptainArticleCountState state = {false, false}; return 0; }
    case 3: { CaptainArticleCountState state = {false, false}; return 0; }
    case 4: { CaptainArticleCountState state = {false, false}; return 0; }
    case 5: { CaptainArticleCountState state = {false, false}; return 0; }
    case 6: { CaptainArticleCountState state = {false, false}; return 0; }
    case 7: { CaptainArticleCountState state = {false, false}; return 0; }
    case 8: { CaptainArticleCountState state = {false, false}; return 0; }
    case 9: { CaptainArticleCountState state = {false, false}; return 0; }
    case 10: { CaptainArticleCountState state = {false, false}; return 0; }
    case 11: { CaptainArticleCountState state = {false, false}; return 0; }
    case 12: { CaptainArticleCountState state = {false, false}; return 0; }
    case 13: { CaptainArticleCountState state = {false, false}; return 0; }
    case 14: { CaptainArticleCountState state = {false, false}; return 0; }
    case 15: { CaptainArticleCountState state = {false, false}; return 0; }
    case 16: { CaptainArticleCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
