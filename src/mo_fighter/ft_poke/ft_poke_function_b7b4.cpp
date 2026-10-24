#pragma force_active on
namespace {
struct PokeArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_116_B7B4(void*, int articleId) {
    switch (articleId) {
    case 0: { PokeArticleStatus status = {{false, false}}; return 5; }
    case 1: { PokeArticleStatus status = {{false, false}}; return 2; }
    case 2: { PokeArticleStatus status = {{false, false}}; return 4; }
    case 3: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 4: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 5: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 6: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 7: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 8: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 9: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 10: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 11: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 12: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 13: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 14: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 15: { PokeArticleStatus status = {{false, false}}; return 0; }
    case 16: { PokeArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}
