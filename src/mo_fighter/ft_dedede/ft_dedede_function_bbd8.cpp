// The article dispatch table begins at four-byte alignment.
#pragma section data_type ".data$dededeBBD8" ".bss"

namespace {
struct DededeArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_117_BBD8(void*, int articleId) {
    switch (articleId) {
    case 0: { DededeArticleStatus status = {{false, false}}; return 2; }
    case 1: { DededeArticleStatus status = {{false, false}}; return 1; }
    case 2: { DededeArticleStatus status = {{false, false}}; return 1; }
    case 3: { DededeArticleStatus status = {{false, false}}; return 4; }
    case 4: { DededeArticleStatus status = {{false, false}}; return 19; }
    case 5: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 6: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 7: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 8: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 9: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 10: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 11: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 12: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 13: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 14: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 15: { DededeArticleStatus status = {{false, false}}; return 0; }
    case 16: { DededeArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}
