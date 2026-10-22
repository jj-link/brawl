#pragma force_active on

extern "C" {
    void fn_82_3374(void*);
    void fn_82_35C0(void*, float);
    void fn_82_2F9C(void*, float);
    void fn_82_11DC(void*, float);
    void fn_82_1A00(void*, float);
    void fn_82_2284(void*);
    void fn_82_26E0(void*, int, float);
    void setPos__9grGimmickFP5Vec3f(void*, void*);
    extern const float lbl_82_rodata_10;
    extern const float lbl_82_rodata_28;
}

struct Vec3 {
    float x, y, z;
};

extern "C" void fn_82_1090(char* self, float f) {
    Vec3 v;

    fn_82_3374(self);
    fn_82_35C0(self, f);
    fn_82_2F9C(self, f);
    v.x = lbl_82_rodata_10;
    v.y = lbl_82_rodata_28;
    v.z = lbl_82_rodata_10;
    v.y = v.y - *(float*)(self + 0xfbc);
    v.y = v.y - *(float*)(self + 0xfd8);
    v.x = lbl_82_rodata_10 - *(float*)(self + 0xfd4);
    setPos__9grGimmickFP5Vec3f(*(void**)(self + 0x1dc), &v);

    if ((unsigned int)*(int*)(self + 0x103c) > 0xa) {
        fn_82_11DC(self, f);
        fn_82_1A00(self, f);
        {
            int i;
            char* p;
            p = self + 0x200;
            for (i = 0; i < *(int*)(self + 0x880); i++) {
                fn_82_26E0(p, *(int*)(self + 0xf20), f);
                p += 0x34;
            }
        }
        {
            char* p;
            int i;
            p = self + 0x88c;
            for (i = 0; i < *(int*)(self + 0xf0c); i++) {
                fn_82_26E0(p, *(int*)(self + 0x1e0), f);
                p += 0x34;
            }
        }
        fn_82_2284(self);
    } else {
        *(int*)(self + 0x103c) = *(int*)(self + 0x103c) + 1;
    }
}
