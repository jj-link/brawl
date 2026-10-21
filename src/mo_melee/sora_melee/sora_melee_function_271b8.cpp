#pragma force_active on

struct Work {
    virtual void unused();
    virtual char* get(int index);
};

struct Object {
    char padding[0x28];
    Work* work;
};

extern "C" unsigned int fn_27_2EFA0(char* obj, float* out);

extern "C" unsigned int fn_27_271B8(Object* __restrict obj, float* out, int index) {
    Work* work = obj->work;
    char* entry = work->get(index);
    return fn_27_2EFA0(entry, out);
}
