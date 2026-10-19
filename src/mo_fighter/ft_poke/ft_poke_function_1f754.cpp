#pragma force_active on
struct Obj {
    virtual void v0(void);  virtual void v1(void);  virtual void v2(void);  virtual void v3(void);
    virtual void v4(void);  virtual void v5(void);  virtual void v6(void);  virtual void v7(void);
    virtual void v8(void);  virtual void v9(void);  virtual void v10(void); virtual void v11(void);
    virtual void v12(void); virtual void v13(void); virtual void v14(void); virtual void v15(void);
    virtual void v16(void); virtual void v17(void); virtual void v18(void); virtual void v19(void);
    virtual void v20(void); virtual void v21(void); virtual void v22(void); virtual void v23(void);
    virtual void v24(void); virtual void v25(void); virtual void v26(void); virtual void v27(void);
    virtual void v28(void); virtual void v29(void); virtual void v30(void); virtual void v31(void);
    virtual void v32(void); virtual void v33(void); virtual void v34(void); virtual void v35(void);
    virtual void v36(void); virtual void v37(void); virtual void v38(void); virtual void v39(void);
    virtual void v40(void); virtual void v41(void); virtual void v42(void); virtual void v43(void);
    virtual void v44(void); virtual void v45(void); virtual void v46(void); virtual void v47(void);
    virtual void v48(void); virtual void v49(void); virtual void v50(void); virtual void v51(void);
    virtual void v52(void); virtual void v53(void); virtual void v54(void);
    virtual void target(void *a, int zero, void *b, int neg1);
};

extern "C" void fn_116_1F754(void *self, void *a, void *b)
{
    Obj *p = *(Obj **)(*(char **)(*(char **)((char *)self + 0x60) + 0xd8) + 0x5c);
    p->target(a, 0, b, -1);
}
