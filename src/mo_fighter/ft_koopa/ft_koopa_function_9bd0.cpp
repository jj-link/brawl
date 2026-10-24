#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
bool fn_102_A21C(soArticle*);
char* fn_102_A22C(void*, int);
}

namespace {
struct KoopaState {
    bool first;
    bool second;
};
struct KoopaCounter {
    bool (*predicate)(soArticle*);
    unsigned int accepted;
    unsigned int rejected;

    explicit KoopaCounter(bool (*test)(soArticle*))
        : predicate(test), accepted(0), rejected(0) {}
    inline void operator()(soArticle* article) {
        if (predicate(article) == true) {
            ++accepted;
            return;
        }
        ++rejected;
    }
};
inline KoopaCounter countArticles(char* object) {
    KoopaCounter counter(fn_102_A21C);
    for (int i = 0; i < 6; ++i) {
        char* weapon = fn_102_A22C(object + 0xC, i);
        counter(reinterpret_cast<soArticle*>(weapon + 0x88));
    }
    return counter;
}
}

extern "C" unsigned int fn_102_9BD0(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { KoopaState state = {false, false}; return countArticles(object).accepted; }
    case 1: { KoopaState state = {false, false}; return 0; }
    case 2: { KoopaState state = {false, false}; return 0; }
    case 3: { KoopaState state = {false, false}; return 0; }
    case 4: { KoopaState state = {false, false}; return 0; }
    case 5: { KoopaState state = {false, false}; return 0; }
    case 6: { KoopaState state = {false, false}; return 0; }
    case 7: { KoopaState state = {false, false}; return 0; }
    case 8: { KoopaState state = {false, false}; return 0; }
    case 9: { KoopaState state = {false, false}; return 0; }
    case 10: { KoopaState state = {false, false}; return 0; }
    case 11: { KoopaState state = {false, false}; return 0; }
    case 12: { KoopaState state = {false, false}; return 0; }
    case 13: { KoopaState state = {false, false}; return 0; }
    case 14: { KoopaState state = {false, false}; return 0; }
    case 15: { KoopaState state = {false, false}; return 0; }
    case 16: { KoopaState state = {false, false}; return 0; }
    default: return 0;
    }
}
