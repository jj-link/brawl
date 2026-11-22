#include <types.h>
#include <so/model/so_model_module_impl.h>
#pragma force_active on

class NodeArray {
public:
    virtual void slot0();
    virtual soModelVirtualNode* at(int);
    virtual void slot2();
    virtual int size() const;
};

extern "C" void fn_27_973C(soModelModuleImpl*);
extern "C" void fn_80047A50(char*, s8*, unsigned long);
extern "C" void fn_800471A4(void*, int, int, void*, void*, int, int, int);

inline bool isVirtualNode(soModelModuleImpl* self, u32 node) {
    if (node >= self->soModelModuleSimple::getNodeNum() && node < 300)
        return true;
    return false;
}

extern "C" void setUpMtx__17soModelModuleImplFUl(soModelModuleImpl* obj, u32 node) {
    u8* self = (u8*)obj;
    u32 real;
    long model;
    long model2;
    s32 i;

    if (isVirtualNode(obj, node) == true) {
        u32 parent;
        for (i = 0; i < (*(NodeArray**)(self + 0x90))->size(); ++i) {
            if ((*(NodeArray**)(self + 0x90))->at(i)->getNodeParent(node, parent) == true)
                break;
        }

        real = obj->getRealNodeId(parent);
        if (!((self[0xc5] >> 6) & 1) && (int)self[0xc2] != 2) {
            fn_27_973C(obj);
            if ((*(s8**)(self + 0xa8))[real] != 1) {
                model = *(long*)(self + 0xc);
                *(int*)(self + 0x48) = 0;
                fn_80047A50((char*)model, *(s8**)(self + 0xa8), real);
                fn_800471A4((void*)model, 0, 0, *(void**)(self + 0xa8),
                            *(void**)(self + 0xac), 0, 0, 0);
                self[0xc2] = 1;
            }
        }

        Vec3f scale = obj->getNodeScale(node);
        (*(NodeArray**)(self + 0x90))->at(i)->updateMatrix(*obj, node, scale);
        return;
    }
    if (!((self[0xc5] >> 6) & 1) && (int)self[0xc2] != 2) {
        fn_27_973C(obj);
        if ((*(s8**)(self + 0xa8))[node] != 1) {
            model2 = *(long*)(self + 0xc);
            *(int*)(self + 0x48) = 0;
            fn_80047A50((char*)model2, *(s8**)(self + 0xa8), node);
            fn_800471A4((void*)model2, 0, 0, *(void**)(self + 0xa8),
                        *(void**)(self + 0xac), 0, 0, 0);
            self[0xc2] = 1;
        }
    }
}
