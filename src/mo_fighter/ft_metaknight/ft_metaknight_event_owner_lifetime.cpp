#include <types.h>

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void* fn_111_18AC(void* object, int deleting);
void operator delete(void* object);

extern "C" bool fn_111_83B8(void*, int event) {
    s8 type = static_cast<s8>(event);
    int observed = 12;
    return static_cast<s8>(observed) == type;
}

extern "C" void* fn_111_83D4(void* object, int deleting) {
    if (object) {
        // Nested deleting modes use signed low halfwords in the word-sized caller ABI.
        fn_27_C74E8(static_cast<u8*>(object) + 0xA5FC, -1);
        void* baseObject = object;
        int baseDeleting = 0;
        int baseFlag = static_cast<s16>(baseDeleting);
        fn_111_18AC(baseObject, baseFlag);
        if (static_cast<s16>(deleting) > 0) {
            operator delete(object);
        }
    }
    return object;
}
