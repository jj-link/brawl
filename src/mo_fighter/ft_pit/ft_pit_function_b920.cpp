#pragma force_active on
#pragma section data_type ".data" ".bss"

namespace {
struct PitArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_112_B920(void*, int articleId) {
    switch (articleId) {
    case 0: { PitArticleStatus status = {{false, false}}; return 1; }
    case 1: { PitArticleStatus status = {{false, false}}; return 4; }
    case 2: { PitArticleStatus status = {{false, false}}; return 1; }
    case 3: { PitArticleStatus status = {{false, false}}; return 0; }
    case 4: { PitArticleStatus status = {{false, false}}; return 0; }
    case 5: { PitArticleStatus status = {{false, false}}; return 0; }
    case 6: { PitArticleStatus status = {{false, false}}; return 0; }
    case 7: { PitArticleStatus status = {{false, false}}; return 0; }
    case 8: { PitArticleStatus status = {{false, false}}; return 0; }
    case 9: { PitArticleStatus status = {{false, false}}; return 0; }
    case 10: { PitArticleStatus status = {{false, false}}; return 0; }
    case 11: { PitArticleStatus status = {{false, false}}; return 0; }
    case 12: { PitArticleStatus status = {{false, false}}; return 0; }
    case 13: { PitArticleStatus status = {{false, false}}; return 0; }
    case 14: { PitArticleStatus status = {{false, false}}; return 0; }
    case 15: { PitArticleStatus status = {{false, false}}; return 0; }
    case 16: { PitArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}
