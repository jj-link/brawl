#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void __dt__9grGimmickFv(void* self, int flag);

class grGimmick {
public:
    virtual ~grGimmick();
};

extern "C" grGimmick* fn_40_2DEB8(grGimmick* self, int flag) {
    if (self) {
        __dt__9grGimmickFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
