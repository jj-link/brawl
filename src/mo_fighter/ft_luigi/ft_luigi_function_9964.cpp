// The post-generation dispatch table is four-byte aligned in the REL.
#pragma section data_type ".data$luigi9964" ".bss"

#include <so/article/so_article.h>
#include <so/so_module_accesser.h>
#include <ft/fighter.h>

extern "C" {
extern unsigned char lbl_99_data_5FF4[]; // wnLuigiFireball
extern unsigned char lbl_99_data_5E7C[]; // wnLuigiNegativeZone
extern unsigned char lbl_99_data_1AB0[]; // soArticle
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_99_10648(Fighter*, Vec3f*);
}

namespace {
template <unsigned Kind>
inline bool notifyGenerated(soModuleAccesser* accesser, soArticle* article) {
    // Each kind initializes the two post-generation state bytes, including
    // kinds with no additional action. Keep their per-kind lifetime.
    bool flags[2] = { false, false };
    if (Kind == 0) {
        __dynamic_cast(article, 0, lbl_99_data_5FF4, lbl_99_data_1AB0, 1);
    } else if (Kind == 1) {
        Fighter* weapon = static_cast<Fighter*>(__dynamic_cast(
            article, 0, lbl_99_data_5E7C, lbl_99_data_1AB0, 1));
        Vec3f position = accesser->getPostureModule().getPos();
        fn_99_10648(weapon, &position);
    }
    return true;
}
}

extern "C" bool fn_99_9964(void*, soModuleAccesser* accesser, soArticle* article) {
    switch (article->getArticleId()) {
    case 0: return notifyGenerated<0>(accesser, article);
    case 1: return notifyGenerated<1>(accesser, article);
    case 2: return notifyGenerated<2>(accesser, article);
    case 3: return notifyGenerated<3>(accesser, article);
    case 4: return notifyGenerated<4>(accesser, article);
    case 5: return notifyGenerated<5>(accesser, article);
    case 6: return notifyGenerated<6>(accesser, article);
    case 7: return notifyGenerated<7>(accesser, article);
    case 8: return notifyGenerated<8>(accesser, article);
    case 9: return notifyGenerated<9>(accesser, article);
    case 10: return notifyGenerated<10>(accesser, article);
    case 11: return notifyGenerated<11>(accesser, article);
    case 12: return notifyGenerated<12>(accesser, article);
    case 13: return notifyGenerated<13>(accesser, article);
    case 14: return notifyGenerated<14>(accesser, article);
    case 15: return notifyGenerated<15>(accesser, article);
    case 16: return notifyGenerated<16>(accesser, article);
    default: return false;
    }
}
