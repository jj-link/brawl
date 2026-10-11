#include <so/so_array.h>
#include <so/article/so_article.h>

extern "C" int fn_111_97F8() {
    return 1;
}

extern "C" void fn_111_9800(void* object, u8 value) {
    static_cast<u8*>(object)[0x20BC] = value;
}

extern "C" void* fn_111_9808(void* object) {
    return static_cast<u8*>(object) + 0xA060;
}

extern "C" const u8* fn_111_9814(const void* object, int index) {
    const soArrayFixed<u8>* array = reinterpret_cast<const soArrayFixed<u8>*>(static_cast<const u8*>(object) + 0xA060);
    return &array->at(index);
}

extern "C" void* fn_111_9828(void* object) {
    return static_cast<u8*>(object) + 0xA09C;
}

extern "C" void* fn_111_9834(void* object) {
    return static_cast<u8*>(object) + 0xA554;
}

extern "C" bool fn_111_9840(const soArrayFixed<u8>* array) {
    return array->size() == 0;
}

extern "C" bool fn_111_9874(soArticle* article) {
    return article->isActiveArticle();
}
