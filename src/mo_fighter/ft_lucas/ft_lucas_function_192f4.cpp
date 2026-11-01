#include <so/article/so_article.h>
#include <types.h>
#pragma force_active on

extern "C" void* fn_114_19B2C(void*, int);

namespace {
struct LucasArticleAvailabilityState {
    bool first;
    bool second;
};
inline bool allArticlesActive(char* object) {
    for (int i = 0; i < 6; ++i) {
        void* w = fn_114_19B2C(object + 0xC, i);
        if (!reinterpret_cast<soArticle*>(static_cast<char*>(w) + 0x88)->isActiveArticle())
            return false;
    }
    return true;
}
}

extern "C" bool fn_114_192F4(char* object, unsigned int operation, unsigned int kind) {
    switch (kind) {
    case 0: { LucasArticleAvailabilityState state = {false, false}; return !allArticlesActive(object); }
    case 1: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 2: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 3: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 4: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 5: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 6: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 7: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 8: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 9: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 10: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 11: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 12: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 13: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 14: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 15: { LucasArticleAvailabilityState state = {false, false}; return false; }
    case 16: { LucasArticleAvailabilityState state = {false, false}; return false; }
    default: return false;
    }
}
