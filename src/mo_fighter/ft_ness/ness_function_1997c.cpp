#include <so/article/so_article.h>

extern "C" {
bool fn_101_EEF0(soArticle*);
char* fn_101_19FC4(void*, int);
}

namespace {
// The two state flags are initialized for every kind, but not read here.
struct NessArticleCountState {
    bool first;
    bool second;
};
struct NessArticleCounter {
    bool (*predicate)(soArticle*);
    unsigned int accepted;
    unsigned int rejected;

    explicit NessArticleCounter(bool (*test)(soArticle*))
        : predicate(test), accepted(0), rejected(0) {}
    void operator()(soArticle* article) {
        if (predicate(article) == true) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};
inline NessArticleCounter countArticles(char* object, bool (*predicate)(soArticle*)) {
    NessArticleCounter counter(predicate);
    for (int i = 0; i < 6; ++i) {
        counter(reinterpret_cast<soArticle*>(fn_101_19FC4(object + 0xC, i) + 0x88));
    }
    return counter;
}
}

extern "C" unsigned int fn_101_1997C(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: {
        NessArticleCountState state = {false, false};
        return countArticles(object, fn_101_EEF0).accepted;
    }
    case 1: { NessArticleCountState state = {false, false}; return 0; }
    case 2: { NessArticleCountState state = {false, false}; return 0; }
    case 3: { NessArticleCountState state = {false, false}; return 0; }
    case 4: { NessArticleCountState state = {false, false}; return 0; }
    case 5: { NessArticleCountState state = {false, false}; return 0; }
    case 6: { NessArticleCountState state = {false, false}; return 0; }
    case 7: { NessArticleCountState state = {false, false}; return 0; }
    case 8: { NessArticleCountState state = {false, false}; return 0; }
    case 9: { NessArticleCountState state = {false, false}; return 0; }
    case 10: { NessArticleCountState state = {false, false}; return 0; }
    case 11: { NessArticleCountState state = {false, false}; return 0; }
    case 12: { NessArticleCountState state = {false, false}; return 0; }
    case 13: { NessArticleCountState state = {false, false}; return 0; }
    case 14: { NessArticleCountState state = {false, false}; return 0; }
    case 15: { NessArticleCountState state = {false, false}; return 0; }
    case 16: { NessArticleCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
