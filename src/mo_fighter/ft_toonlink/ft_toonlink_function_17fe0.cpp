#pragma force_active on
extern "C" {
unsigned int fn_121_CC2C(void*);
char* fn_121_18624(void*, int);
}

namespace {
struct ArticleCountState {
    bool first;
    bool second;
};
template <unsigned Kind> struct ArticleCounter {
    unsigned int (*predicate)(void*);
    unsigned int accepted;
    unsigned int rejected;
    explicit ArticleCounter(unsigned int (*test)(void*))
        : predicate(test), accepted(0), rejected(0) {}
    inline void operator()(void* article) {
        if (predicate(article) == 1) {
            ++accepted;
        } else {
            ++rejected;
        }
    }
};
template <unsigned Kind> inline ArticleCounter<Kind> countArticles(char* object) {
    ArticleCounter<Kind> counter(fn_121_CC2C);
    for (int i = 0; i < 1; ++i) {
        counter(fn_121_18624(object + 0xC, i) + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_121_17FE0(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { ArticleCountState state = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { ArticleCountState state = {false, false}; return 0; }
    case 2: { ArticleCountState state = {false, false}; return 0; }
    case 3: { ArticleCountState state = {false, false}; return 0; }
    case 4: { ArticleCountState state = {false, false}; return 0; }
    case 5: { ArticleCountState state = {false, false}; return 0; }
    case 6: { ArticleCountState state = {false, false}; return 0; }
    case 7: { ArticleCountState state = {false, false}; return 0; }
    case 8: { ArticleCountState state = {false, false}; return 0; }
    case 9: { ArticleCountState state = {false, false}; return 0; }
    case 10: { ArticleCountState state = {false, false}; return 0; }
    case 11: { ArticleCountState state = {false, false}; return 0; }
    case 12: { ArticleCountState state = {false, false}; return 0; }
    case 13: { ArticleCountState state = {false, false}; return 0; }
    case 14: { ArticleCountState state = {false, false}; return 0; }
    case 15: { ArticleCountState state = {false, false}; return 0; }
    case 16: { ArticleCountState state = {false, false}; return 0; }
    default: return 0;
    }
}
