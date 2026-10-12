#include <so/so_module_accesser.h>

struct PikachuVerticalRangeStorage {
    char reserved[0x60];
    soModuleAccesser* accesser;
};

extern "C" {
void* fn_98_14878(void*);
void fn_98_9540(void*);
void* fn_98_14750(void*);
bool fn_98_183FC(void*);
void fn_98_18420(void*);
void fn_98_14A18(void*, float);

bool fn_98_145A0(void* storage, const Vec3f* point) {
    soWorkManageModule* work = &static_cast<PikachuVerticalRangeStorage*>(storage)->accesser->getWorkManageModule();
    void* next = fn_98_14878(storage);
    fn_98_9540(next);
    void* entry = fn_98_14750(storage);
    if (!entry) return false;
    if (fn_98_183FC(entry)) return false;
    float first = work->getFloat(0x11000001);
    float second = work->getFloat(0x11000002);
    if ((first <= second && first <= point->m_y && point->m_y <= second) ||
        (first > second && first >= point->m_y && point->m_y >= second)) {
        fn_98_18420(entry);
        fn_98_14A18(storage, point->m_y);
        return true;
    }
    if (next) return fn_98_145A0(next, point);
    return false;
}
}
