#pragma force_active on

class VObj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8(float f) = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11(void* a, int b) = 0;
};

extern "C" {
void setFrameMatCol__8MuObjectFf(void* obj, float frame);
void* getInstance__14gfSceneManagerFv();
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_13_data_188[];
extern char lbl_13_data_1B8[];
extern const float lbl_13_rodata_48;
}

extern "C" void fn_13_1520(char* arg0, int arg1) {
    char* p9c;
    int a10;
    char* obj;
    int a10b;
    obj = *(char**)(arg0 + 0x64);
    setFrameMatCol__8MuObjectFf(obj, (float)arg1);
    a10 = *(int*)(obj + 0x10);

    void* mgr = getInstance__14gfSceneManagerFv();
    void* dc = __dynamic_cast(*(void**)((char*)mgr + 4), 4, lbl_13_data_188, lbl_13_data_1B8, 0);
    char* p = *(char**)((char*)dc + 0x398);
    char* q = *(char**)p;
    VObj* o = *(VObj**)(q + 0x48);
    o->v11(*(void**)((char*)o + 0xE4), a10);

    int aA8 = *(int*)(arg0 + 0xA8);
    mgr = getInstance__14gfSceneManagerFv();
    dc = __dynamic_cast(*(void**)((char*)mgr + 4), 4, lbl_13_data_188, lbl_13_data_1B8, 0);
    p = *(char**)((char*)dc + 0x398);
    q = *(char**)p;
    o = *(VObj**)(q + 0x48);
    o->v11(*(void**)((char*)o + 0xE4), aA8);

    char* o68 = *(char**)(arg0 + 0x68);
    (*(VObj**)(*(char**)(o68 + 0x14) + 0xC))->v8(lbl_13_rodata_48);
    (*(VObj**)(*(char**)(o68 + 0x14) + 0x18))->v8(lbl_13_rodata_48);

    int b0 = *(int*)(arg0 + 0xB0);
    int n;
    if (b0 >= 2) {
        n = -1;
    } else {
        n = *(int*)(arg0 + 0xD0);
    }
    if (n > 0) {
        p9c = *(char**)(arg0 + 0x9C);
        a10b = *(int*)(p9c + 0x10);
        mgr = getInstance__14gfSceneManagerFv();
        dc = __dynamic_cast(*(void**)((char*)mgr + 4), 4, lbl_13_data_188, lbl_13_data_1B8, 0);
        p = *(char**)((char*)dc + 0x398);
        q = *(char**)p;
        o = *(VObj**)(q + 0x48);
        o->v11(*(void**)((char*)o + 0xE4), a10b);
        (*(VObj**)(*(char**)(p9c + 0x14) + 0xC))->v8(lbl_13_rodata_48);
    }

    char* o6c = *(char**)(arg0 + 0x6C);
    (*(VObj**)(*(char**)(o6c + 0x14) + 0xC))->v8(lbl_13_rodata_48);
    (*(VObj**)(*(char**)(o6c + 0x14) + 0x18))->v8(lbl_13_rodata_48);
    int a10c = *(int*)(o6c + 0x10);
    mgr = getInstance__14gfSceneManagerFv();
    dc = __dynamic_cast(*(void**)((char*)mgr + 4), 4, lbl_13_data_188, lbl_13_data_1B8, 0);
    p = *(char**)((char*)dc + 0x398);
    q = *(char**)p;
    o = *(VObj**)(q + 0x48);
    o->v11(*(void**)((char*)o + 0xE4), a10c);
}
