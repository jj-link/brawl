#include <types.h>
#pragma force_active on

class Ground;
class stCollisionWork;
class stMelee;
class grCollision;

class Stage {
public:
    void setCollision(grCollision* coll);
};

class grCollision {
public:
    static grCollision* create(Stage* stage, void* mem, Ground* ground, int flag);
};

class stMelee {
public:
    grCollision* createCollisionSelf(stCollisionWork* work, Ground* ground, const char* a, const char* b, unsigned short c);
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_27_238F90(stMelee* self, Stage* stage, stCollisionWork* work, const char* a, const char* b, unsigned short c);

grCollision* stMelee::createCollisionSelf(stCollisionWork* arg0, Ground* arg1, const char* arg2, const char* arg3, unsigned short arg4) {
    grCollision* result;
    if (arg0 == nullptr) {
        return nullptr;
    }
    Stage* stage = (Stage*)__nw__FUlQ25Heaps8HeapType(0x28, 0x11);
    if (stage == nullptr) {
        return nullptr;
    }
    fn_27_238F90(this, stage, arg0, arg2, arg3, arg4);
    result = grCollision::create((Stage*)this, (void*)stage, arg1, 1);
    ((Stage*)this)->setCollision(result);
    __dl__FPv(stage);
    return result;
}
