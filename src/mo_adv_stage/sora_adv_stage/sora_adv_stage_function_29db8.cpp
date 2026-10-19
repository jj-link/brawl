#pragma force_active on
struct StageObject;

extern "C" void fn_27_272420(void*, int);
extern "C" void __dt__9grGimmickFv(StageObject*, int);
extern "C" void __dl__FPv(void*);

extern "C" StageObject* fn_40_29DB8(StageObject* p, int flag)
{
    if (p != 0) {
        fn_27_272420(reinterpret_cast<char*>(p) + 0x14C, 0);
        __dt__9grGimmickFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
