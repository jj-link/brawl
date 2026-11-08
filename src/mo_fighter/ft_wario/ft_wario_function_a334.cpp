#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_110_AA38(void*);
void* fn_110_AA48(void*, s32);
void* fn_110_AA60(void*, s32);
}

namespace {
struct WarioArticleState {
    bool first;
    bool second;
};
template <unsigned Kind> struct WarioArticleCounter {
    u32 (*predicate)(void*);
    u32 accepted;
    u32 rejected;
    explicit WarioArticleCounter(u32 (*test)(void*))
        : predicate(test), accepted(0), rejected(0) {}
    inline void operator()(void* article) {
        if (predicate(article) == 1) {
            ++accepted;
        } else {
            ++rejected;
        }
    }
};
template <unsigned Kind> inline WarioArticleCounter<Kind> countArticles(char* object) {
    WarioArticleCounter<Kind> counter(fn_110_AA38);
    for (int i = 0; i < 1; ++i) {
        char* article = Kind == 0 ? static_cast<char*>(fn_110_AA60(object + 0x20B8, i))
                                  : static_cast<char*>(fn_110_AA48(object + 0xC, i));
        counter(article + 0x88);
    }
    return counter;
}
}

extern "C" s32 fn_110_A334(char* object, u32 operation, u32 kind) {
    switch (kind) {
    case 0: { WarioArticleState state = {false, false}; return countArticles<0>(object).accepted; }
    case 1: { WarioArticleState state = {false, false}; return countArticles<1>(object).accepted; }
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
