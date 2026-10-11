#include <so/so_array.h>
#include <so/article/so_article.h>
#include <types.h>

// Expose the otherwise private soArticle slot without changing its ABI.
class LucasArticleView : public soArticle {
public:
    virtual bool isActiveArticle();
};

extern "C" int fn_114_E6E8(void*) {
    return 5;
}

extern "C" void fn_114_E6F0(void* object, u8 value) {
    *(static_cast<u8*>(object) + 0x40758) = value;
}

extern "C" void* fn_114_E6FC(void* object) {
    return static_cast<char*>(object) + 0x48714;
}

extern "C" const u32& fn_114_E708(void* object, s32 index) {
    const soArrayFixed<u32>* member = reinterpret_cast<const soArrayFixed<u32>*>(static_cast<char*>(object) + 0x48714);
    return member->at(index);
}

extern "C" void* fn_114_E71C(void* object) {
    return static_cast<char*>(object) + 0x48750;
}

extern "C" void* fn_114_E728(void* object) {
    return static_cast<char*>(object) + 0x48c08;
}

extern "C" bool fn_114_E734(const soArrayFixed<u32>* object) {
    return object->size() == 0;
}

extern "C" bool fn_114_E768(LucasArticleView* object) {
    return object->isActiveArticle();
}
