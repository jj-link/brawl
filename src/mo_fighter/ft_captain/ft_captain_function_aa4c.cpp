#include <so/article/so_article.h>
#pragma force_active on

// Thunk used as the article predicate in the count-table dispatch: it
// tail-calls the article's "isActiveArticle" virtual (vtable slot 0x58)
// and passes the result straight through as the predicate value.
extern "C" bool fn_100_AA4C(soArticle* article) {
    return article->isActiveArticle();
}
