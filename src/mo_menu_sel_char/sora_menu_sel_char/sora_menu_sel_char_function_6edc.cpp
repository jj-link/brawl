#include <types.h>
#pragma force_active on

extern "C" int fn_10_61D8(void*);
extern "C" int fn_10_7618(void*);
extern "C" int fn_10_12E58(void*);
extern "C" void fn_10_138F0(void*);
extern "C" void fn_10_13464(void*, int);

extern "C" void fn_10_6EDC(void* self) {
    char* cursor;
    int result;
    int i;
    int selected = -1;
    int fallback = 0;

    if (fn_10_61D8(self) != 0) {
        result = fn_10_7618(self);
        if (result >= 0) {
            cursor = (char*)self;
            i = 0;

            while (i < *(int*)((char*)self + 0x648)) {
                void* item = *(void**)(cursor + 0x44);
                if (*(int*)item == 1 && fn_10_12E58(item) == 0) {
                    selected = i;
                    break;
                }
                cursor += 4;
                i++;
            }

            if (selected < 0) {
                void* item;
                char* fallbackCursor = (char*)self;
                int fallbackIndex = 0;
                int count = *(int*)((char*)self + 0x648);
                for (; fallbackIndex < count; fallbackIndex++) {
                    item = *(void**)(fallbackCursor + 0x44);
                    if (*(int*)item == 0 &&
                        *(int*)((char*)item + 0x1B4) == 2) {
                        selected = fallbackIndex;
                        fallback = 1;
                        break;
                    }
                    fallbackCursor += 4;
                }
            }

            if (selected >= 0) {
                cursor = (char*)*(void**)((char*)self + selected * 4 + 0x44);
                if (fallback != 0) {
                    fn_10_138F0(cursor);
                }
                fn_10_13464(cursor, result);
            }
        }
    }
}
