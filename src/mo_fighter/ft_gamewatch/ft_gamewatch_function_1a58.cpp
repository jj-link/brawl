#include <new>
#pragma force_active on

extern "C" {
char* fn_107_1AF8(char*, short);
char* fn_107_1ED8(char*, short);
char* fn_107_1F74(char*, short);
char* fn_107_20AC(char*, short);
void fn_27_125E20(char*, short);

char* fn_107_1A58(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_107_1AF8(object + 0x1fd00, memberDeleting);
        fn_107_1ED8(object + 0x1f848, memberDeleting);
        fn_107_1F74(object + 0x1f80c, memberDeleting);
        fn_107_20AC(object + 0x194, memberDeleting);
        fn_27_125E20(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
