#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* getBuffer__14gfFileIOHandleCFv(const void*);
extern "C" void* fn_800C35CC(void*, int, int*, int*, void*, int, int, int, int, int, int);

struct Obj {
    char pad[0x3c];
    virtual void v0(void*);
    virtual void v1(void*);
    virtual void v2(void*);
    virtual void v3(void*);
    virtual void v4(void*);
    virtual void v5(void*);
    virtual void v6(void*);
    virtual void v7(void*);
    virtual void v8(void*);
    virtual void v9(void*);
    virtual void v10(void*);
    virtual void v11(void*);
    virtual void v12(void*);
    virtual void v13(void*);
    virtual void v14(void*);
    virtual void v15(void*);
    virtual void v16(void*);
    virtual void v17(void*);
    virtual void v18(void*);
    virtual void v19(void*);
    virtual void v20(void*);
    virtual void v21(void*);
    virtual void v22(void*);
    virtual void v23(void*);
    virtual void v24(void*);
    virtual void v25(void*);
    virtual void v26(void*);
    virtual void v27(void*);
    virtual void v28(void*);
    virtual void v29(void*);
    virtual void v30(void*);
    virtual void v31(void*);
    virtual void v32(void*);
    virtual void v33(void*);
    virtual void v34(void*);
    virtual void v35(void*);
    virtual void v36(void*);
    virtual void v37(void*);
    virtual void v38(void*);
    virtual void v39(void*);
    virtual void v40(void*);
    virtual void v41(void*);
    virtual void v42(void*);
    virtual void v43(void*);
    virtual void v44(void*);
    virtual void v45(void*);
    virtual void v46(void*);
    virtual void v47(void*);
    virtual void v48(void*);
    virtual void v49(void*);
    virtual void v50(void*);
    virtual void v51(void*);
    virtual void v52(void*);
    virtual void v53(void*);
    virtual void v54(void*);
    virtual int v55(void*);
    virtual void v56(void*);
    virtual void v57(void*);
};

extern "C" void fn_6_2EC0(void* self, int arg1)
{
    int vd0;
    int v9c;
    int r8;
    void* obj = __nw__FUlQ25Heaps8HeapType(0x394, 0x2a);
    if (obj != 0) {
        void* buf = getBuffer__14gfFileIOHandleCFv((char*)*(void**)((char*)self + 0x1ac) + 0x1cc0);
        vd0 = *(int*)((char*)*(void**)((char*)self + 0x1ac) + 0xd0);
        void* p = *(void**)((char*)self + 0x1ac);
        v9c = *(int*)((char*)p + 0x9c);
        r8 = ((Obj*)self)->v55(p);
        obj = fn_800C35CC(obj, arg1, &v9c, &vd0, buf, r8, 0x1a, 0x2a, 0x2b, 0, 0xf0);
    }
    *(void**)((char*)*(void**)((char*)self + 0x1ac) + 0x1ce4) = obj;
}
