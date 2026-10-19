#pragma force_active on
extern "C" int fn_800B61C0(void*);
extern "C" int fn_800B5854(void*, int, int, int, int);

class FriendVObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(int);
};

extern "C" int fn_14_9BFC(void* self) {
    char* p = (char*)self;
    if (fn_800B61C0(*(void**)(p + 0xc8))) {
        FriendVObj* obj = *(FriendVObj**)(p + 0x204);
        obj->v13(*(int*)(p + 0x1ec));
        fn_800B5854(*(void**)(p + 0xc0), 8, 0x10, 1, 0);
        return 0x19;
    }
    return *(int*)(p + 0x24c4);
}
