#pragma force_active on
extern "C" {
unsigned int fn_109_A3B4(void*);
void* fn_109_A3DC(void*, int);
void* fn_109_A3C4(void*, int);
}

namespace {
struct GanonArticleState {
    bool first;
    bool second;
};
template <unsigned Kind> struct GanonArticleCounter {
    unsigned int (*predicate)(void*);
    int matched;
    int rejected;
    explicit GanonArticleCounter(unsigned int (*test)(void*))
        : predicate(test), matched(0), rejected(0) {}
    inline void operator()(void* article) {
        if (predicate(article) == 1) {
            ++matched;
        } else {
            ++rejected;
        }
    }
};
template <unsigned Kind> inline GanonArticleCounter<Kind> countGanonArticles(char* object) {
    GanonArticleCounter<Kind> counter(fn_109_A3B4);
    for (int i = 0; i < 1; ++i) {
        void* item = Kind == 0 ? fn_109_A3DC(object + 0x16E0, i)
                              : fn_109_A3C4(object + 0xC, i);
        counter(static_cast<char*>(item) + 0x88);
    }
    return counter;
}
}

extern "C" unsigned int fn_109_9CB0(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { GanonArticleState state = {false, false}; return countGanonArticles<0>(object).matched; }
    case 1: { GanonArticleState state = {false, false}; return countGanonArticles<1>(object).matched; }
    case 2: { GanonArticleState state = {false, false}; return 0; }
    case 3: { GanonArticleState state = {false, false}; return 0; }
    case 4: { GanonArticleState state = {false, false}; return 0; }
    case 5: { GanonArticleState state = {false, false}; return 0; }
    case 6: { GanonArticleState state = {false, false}; return 0; }
    case 7: { GanonArticleState state = {false, false}; return 0; }
    case 8: { GanonArticleState state = {false, false}; return 0; }
    case 9: { GanonArticleState state = {false, false}; return 0; }
    case 10: { GanonArticleState state = {false, false}; return 0; }
    case 11: { GanonArticleState state = {false, false}; return 0; }
    case 12: { GanonArticleState state = {false, false}; return 0; }
    case 13: { GanonArticleState state = {false, false}; return 0; }
    case 14: { GanonArticleState state = {false, false}; return 0; }
    case 15: { GanonArticleState state = {false, false}; return 0; }
    case 16: { GanonArticleState state = {false, false}; return 0; }
    default: return 0;
    }
}
