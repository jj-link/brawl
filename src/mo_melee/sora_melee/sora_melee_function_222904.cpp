#include <types.h>
#pragma force_active on

namespace nw4r { namespace g3d { class ResFileData; } }

extern "C" int fn_8018E588(void*);
extern "C" void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
extern "C" void fn_801971D0(void*, void*);
extern "C" void fn_8000D2E0(void*, void*, int);
extern void* g_gfSceneRoot;

class Stage {
public:
    bool registScnAnim(nw4r::g3d::ResFileData* resFileData, u32 idx);
};

bool Stage::registScnAnim(nw4r::g3d::ResFileData* resFileData, u32 idx) {
    bool result = false;
    void* file = resFileData;
    if (file != nullptr) {
        if (fn_8018E588(&file) != 0) {
            void* anm = GetResAnmScn__Q34nw4r3g3d7ResFileFi(&file, idx);
            void* tmp = anm;
            fn_801971D0(&anm, &tmp);
            fn_8000D2E0(g_gfSceneRoot, &anm, 0xf);
            result = true;
        }
    }
    return result;
}
