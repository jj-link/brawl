#include <so/article/so_article.h>
#pragma force_active on

class Class_8E20 {
public:
    virtual void fn_121_22F8();
    virtual void fn_121_12B5C();
    virtual void fn_121_14840();
    virtual void fn_121_14838();
    virtual void fn_121_14830();
    virtual void fn_121_14828();
    virtual void fn_121_14820();
    virtual void fn_121_14818();
    virtual void fn_121_14810();
    virtual void fn_121_14808();
    virtual void fn_121_14800();
    virtual void fn_121_147F8();
    virtual void fn_121_147F0();
    virtual void fn_121_147E8();
    virtual void fn_121_14798();
    virtual void fn_121_147E0();
    virtual void fn_121_147D0();
    virtual void fn_121_147B0();
    virtual void fn_121_UNK50();
    virtual int fn_121_147A0(int);
};

extern "C" {
void* fn_121_CD44(void*, int);
void* fn_121_CCFC(void*, int);
void* fn_121_CCE4(void*, int);
void* fn_121_CCCC(void*, int);
void* fn_121_CCB4(void*, int);
void* fn_121_CC9C(void*, int);
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
    static void* get(char* pool, int i) { return fn_121_CD44(pool + 0x106FC, i); }
};
template <> struct ArticlePool<1> {
    static int count() { return 4; }
    static void* get(char* pool, int i) { return fn_121_CCFC(pool + 0x8778, i); }
};
template <> struct ArticlePool<2> {
    static int count() { return 1; }
    static void* get(char* pool, int i) { return fn_121_CCE4(pool + 0x6608, i); }
};
template <> struct ArticlePool<3> {
    static int count() { return 1; }
    static void* get(char* pool, int i) { return fn_121_CCCC(pool + 0x4F34, i); }
};
template <> struct ArticlePool<4> {
    static int count() { return 1; }
    static void* get(char* pool, int i) { return fn_121_CCB4(pool + 0x16E0, i); }
};
template <> struct ArticlePool<5> {
    static int count() { return 1; }
    static void* get(char* pool, int i) { return fn_121_CC9C(pool + 0xC, i); }
};
template <unsigned Kind> inline bool allArticlesActive(char* pool, const ArticleSearchStatus& status) {
    for (int i = 0; i < ArticlePool<Kind>::count(); ++i) {
        soArticle& article = *reinterpret_cast<soArticle*>(static_cast<char*>(ArticlePool<Kind>::get(pool, i)) + 0x88);
        if (!status(article)) return false;
    }
    return true;
}
template <unsigned Kind> inline bool articleAvailable(char* pool, const ArticleSearchStatus& status) {
    if (Kind >= 6) return false;
    return !allArticlesActive<Kind>(pool, status);
}
}

struct Inner { char pad[0x84]; Class_8E20* object; };
struct Outer { char pad[0xd8]; Inner* inner; };

extern "C" bool fn_121_BE98(char* pool, Outer* fighter, unsigned kind) {
    switch (kind) {
    case 0: { ArticleSearchStatus status = { false, false }; return articleAvailable<0>(pool, status); }
    case 1: { ArticleSearchStatus status = { false, false }; return articleAvailable<1>(pool, status); }
    case 2: { ArticleSearchStatus status = { false, false }; return articleAvailable<2>(pool, status); }
    case 3: { ArticleSearchStatus status = { false, false }; return articleAvailable<3>(pool, status); }
    case 4: { ArticleSearchStatus status = { false, false }; return articleAvailable<4>(pool, status); }
    case 5: { ArticleSearchStatus status = { false, false }; return articleAvailable<5>(pool, status); }
    case 6: { ArticleSearchStatus status = { false, false }; return fighter->inner->object->fn_121_147A0(6) < 2; }
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
