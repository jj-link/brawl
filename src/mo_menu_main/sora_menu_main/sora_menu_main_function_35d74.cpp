#include <gf/gf_task.h>
#pragma force_active on

class MenuObject {
    char padding[0x5c];
public:
    virtual ~MenuObject();
};

extern "C" {
extern char lbl_2_data_451C[];
void fn_800B8A0C(void*, int);
void* fn_18_113C(void*, int);
void __dl__FPv(void*);

void* fn_2_35D74(unsigned char* object, int deleting) {
    if (object) {
        *(void**)(object + 0x3c) = lbl_2_data_451C;
        unsigned char* cursor = object;
        for (unsigned int i = 0; i < 3; ++i, cursor += 4) {
            MenuObject* entry = *(MenuObject**)(cursor + 0x64);
            if (entry) {
                delete entry;
                *(void**)(cursor + 0x64) = 0;
            }
        }
        if (*(void**)(object + 0x5c))
            *(void**)(object + 0x5c) = 0;
        fn_800B8A0C(*(void**)(object + 0x48), 1);
        (*(gfTask**)(object + 0x60))->exit();
        *(void**)(object + 0x60) = 0;
        fn_18_113C(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}