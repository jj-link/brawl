// Preserve the original REL's four-byte-aligned article-availability dispatch table.
#pragma section data_type ".data$captainA110" ".bss"

#include <so/article/so_article.h>

extern "C" {
char* fn_100_AA5C(void*, int);
char* fn_100_AA74(void*, int);
}

namespace {
struct CaptainArticleAvailabilityState {
    bool first;
    bool second;
};
template <unsigned Kind> inline bool allArticlesActive(char* object) {
    for (int i = 0; i < 1; ++i) {
        char* weapon = Kind == 0 ? fn_100_AA74(object + 0x1F40, i)
                                : fn_100_AA5C(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(weapon + 0x88)->isActiveArticle()) {
            return false;
        }
    }
    return true;
}
}

// The operation parameter is unused; kind selects a fixed-capacity article pool.
extern "C" bool fn_100_A110(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { CaptainArticleAvailabilityState state = {false, false}; return !allArticlesActive<0>(object); }
    case 1: { CaptainArticleAvailabilityState state = {false, false}; return !allArticlesActive<1>(object); }
    case 2: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 3: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 4: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 5: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 6: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 7: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 8: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 9: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 10: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 11: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 12: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 13: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 14: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 15: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    case 16: { CaptainArticleAvailabilityState state = {false, false}; return false; }
    default: return false;
    }
}
