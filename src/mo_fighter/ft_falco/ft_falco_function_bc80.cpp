#include <so/article/so_article.h>
#pragma force_active on

extern "C" {
void* fn_108_C7F0(void*, int);
void* fn_108_C808(void*, int);
void* fn_108_C830(void*, int);
void* fn_108_C88C(void*, int);
}

namespace {
struct ArticleSearchStatus {
    bool first;
    bool second;
    bool operator()(soArticle& article) const { return article.isActiveArticle(); }
};
template <unsigned Kind> struct ArticlePool {
    static int count() { return 0; }
    static void* get(char*, int) { return 0; }
};
template <> struct ArticlePool<0> {
    static int count() { return 1; }
    static void* get(char* pool, int i) { return fn_108_C88C(pool + 0x131F0, i); }
};
template <> struct ArticlePool<1> {
    static int count() { return 5; }
    static void* get(char* pool, int i) { return fn_108_C830(pool + 0x8A80, i); }
};
template <> struct ArticlePool<2> {
    static int count() { return 2; }
    static void* get(char* pool, int i) { return fn_108_C808(pool + 0x4B2C, i); }
};
template <> struct ArticlePool<3> {
    static int count() { return 1; }
    static void* get(char* pool, int i) { return fn_108_C7F0(pool + 0xC, i); }
};
template <unsigned Kind> inline bool allArticlesActive(char* pool, const ArticleSearchStatus& status) {
    for (int i = 0; i < ArticlePool<Kind>::count(); ++i) {
        soArticle& article = *reinterpret_cast<soArticle*>(static_cast<char*>(ArticlePool<Kind>::get(pool, i)) + 0x88);
        if (!status(article)) return false;
    }
    return true;
}
template <unsigned Kind> inline bool articleAvailable(char* pool, const ArticleSearchStatus& status) {
    if (Kind >= 4) return false;
    return !allArticlesActive<Kind>(pool, status);
}
}

extern "C" bool fn_108_BC80(char* pool, void*, unsigned kind) {
    switch (kind) {
    case 0: { ArticleSearchStatus status = { false, false }; return articleAvailable<0>(pool, status); }
    case 1: { ArticleSearchStatus status = { false, false }; return articleAvailable<1>(pool, status); }
    case 2: { ArticleSearchStatus status = { false, false }; return articleAvailable<2>(pool, status); }
    case 3: { ArticleSearchStatus status = { false, false }; return articleAvailable<3>(pool, status); }
    case 4: { ArticleSearchStatus status = { false, false }; return articleAvailable<4>(pool, status); }
    case 5: { ArticleSearchStatus status = { false, false }; return articleAvailable<5>(pool, status); }
    case 6: { ArticleSearchStatus status = { false, false }; return articleAvailable<6>(pool, status); }
    case 7: { ArticleSearchStatus status = { false, false }; return articleAvailable<7>(pool, status); }
    case 8: { ArticleSearchStatus status = { false, false }; return articleAvailable<8>(pool, status); }
    case 9: { ArticleSearchStatus status = { false, false }; return articleAvailable<9>(pool, status); }
    case 10: { ArticleSearchStatus status = { false, false }; return articleAvailable<10>(pool, status); }
    case 11: { ArticleSearchStatus status = { false, false }; return articleAvailable<11>(pool, status); }
    case 12: { ArticleSearchStatus status = { false, false }; return articleAvailable<12>(pool, status); }
    case 13: { ArticleSearchStatus status = { false, false }; return articleAvailable<13>(pool, status); }
    case 14: { ArticleSearchStatus status = { false, false }; return articleAvailable<14>(pool, status); }
    case 15: { ArticleSearchStatus status = { false, false }; return articleAvailable<15>(pool, status); }
    case 16: { ArticleSearchStatus status = { false, false }; return articleAvailable<16>(pool, status); }
    default: return false;
    }
}
