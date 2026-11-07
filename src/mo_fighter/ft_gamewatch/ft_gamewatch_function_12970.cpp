#pragma force_active on
extern const float lbl_107_rodata_58[];

struct ftGameWatchModule {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual float* v17(int flag);
    virtual void v18();
    virtual void v19(float* values, int flag);
    virtual void v20(float* values, int flag);
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38(float value, int flag);
};

extern "C" void fn_107_12970(void*, char* self, int id) {
    const float* rodata = lbl_107_rodata_58;
    if (id >= 0x11d && id <= 0x138) {
        float* p = (*(ftGameWatchModule**)(*(char**)(self + 0xd8) + 0x60))->v17(0);
        float box[4];
        float a[3];
        float t0;
        float t1;
        float t2;
        float t3;
        float t5;
        t3 = rodata[1] - p[4];
        t2 = rodata[2] - p[3];
        t1 = rodata[3] - p[1];
        t0 = rodata[4] - p[2];
        box[0] = t0;
        box[1] = t1;
        box[2] = t2;
        box[3] = t3;
        (*(ftGameWatchModule**)(*(char**)(self + 0xd8) + 0x60))->v20(box, 0);
        t5 = rodata[5] - p[0];
        a[0] = rodata[6];
        a[1] = t5;
        a[2] = rodata[6];
        (*(ftGameWatchModule**)(*(char**)(self + 0xd8) + 0x60))->v19(a, 0);
        (*(ftGameWatchModule**)(*(char**)(self + 0xd8) + 0x60))->v38(rodata[7], 0);
    }
}
