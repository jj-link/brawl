#pragma force_active on
#pragma section data_type ".data" ".bss"

namespace {
struct ToonLinkArticleStatus {
    bool flags[2];
};
}

extern "C" int fn_121_181F0(void*, unsigned int articleId)
{
    switch (articleId) {
    case 0: { ToonLinkArticleStatus status = {{false, false}}; return 1; }
    case 1: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 2: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 3: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 4: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 5: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 6: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 7: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 8: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 9: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 10: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 11: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 12: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 13: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 14: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 15: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    case 16: { ToonLinkArticleStatus status = {{false, false}}; return 0; }
    default: return 0;
    }
}
