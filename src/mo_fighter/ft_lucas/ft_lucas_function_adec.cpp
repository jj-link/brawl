#pragma force_active on
class ftObjA {
public:
    virtual int v2();
    virtual int* v3(int);
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual int v15();
};

struct ftEntryA {
    int key;
    int value;
};

extern "C" ftObjA* fn_114_ADB0(void*);

extern "C" void fn_114_ADEC(void* a, int b, ftEntryA* arr) {
    ftObjA* obj = fn_114_ADB0(a);
    if ((unsigned int)obj->v2() == 1) return;
    if (arr == 0) return;

    int i = 0;
    while (true) {
        if (i >= obj->v15()) break;
        ftEntryA* e = &arr[i];
        int key = arr[i].key;
        if (key < 0) break;
        int val = e->value;
        int* dst = obj->v3(key);
        *dst = val;
        i++;
    }
}
