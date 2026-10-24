#include <so/article/so_article.h>
#pragma force_active on

extern "C" void* fn_116_1964C(void* object, int index);

namespace {
struct ArticleSearchStatus {
    bool first;
    bool second;
};
template <unsigned Kind> inline bool allActive(void* object, const ArticleSearchStatus&) {
    if (Kind != 0) return true;
    for (int i = 0; i < 10; ++i) {
        void* member = fn_116_1964C(static_cast<unsigned char*>(object) + 0xc, i);
        soArticle* article = reinterpret_cast<soArticle*>(static_cast<unsigned char*>(member) + 0x88);
        if (!article->isActiveArticle()) return false;
    }
    return true;
}
template <unsigned Kind> inline int available(void* object) {
    ArticleSearchStatus status = { false, false };
    return !allActive<Kind>(object, status);
}
}

extern "C" int fn_116_18E44(void* object, unsigned, unsigned kind) {
    switch (kind) {
    case 0: return available<0>(object);
    case 1: return available<1>(object);
    case 2: return available<2>(object);
    case 3: return available<3>(object);
    case 4: return available<4>(object);
    case 5: return available<5>(object);
    case 6: return available<6>(object);
    case 7: return available<7>(object);
    case 8: return available<8>(object);
    case 9: return available<9>(object);
    case 10: return available<10>(object);
    case 11: return available<11>(object);
    case 12: return available<12>(object);
    case 13: return available<13>(object);
    case 14: return available<14>(object);
    case 15: return available<15>(object);
    case 16: return available<16>(object);
    default: return 0;
    }
}
