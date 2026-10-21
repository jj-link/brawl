#pragma force_active on
extern "C" int fn_8013581C(void*);

struct ObjV {
    virtual void* pad();
    virtual void* call(void*);
};

extern "C" int fn_27_27724(void* self, void* arg) {
    int result = 0;
    void* ret = (*(ObjV**)((char*)self + 0x28))->call(arg);

    if ((*(int*)((char*)*(void**)((char*)ret + 4) + 8) >> 24) == 3) {
        void* ret2 = (*(ObjV**)((char*)self + 0x28))->call(arg);
        if (fn_8013581C(*(void**)((char*)ret2 + 4)) == 0)
            result = 1;
    }
    return result;
}
