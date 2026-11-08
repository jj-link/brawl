#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_461C;
}

struct Lbl71C8Base { char pad[4]; };
class Lbl71C8Obj : public Lbl71C8Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(void*, unsigned int, unsigned int);
};

extern Lbl71C8Obj lbl_27_bss_71C8;

class Class1A4 {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual int v16();
};

class Class27A8 {
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
    virtual int v9(int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
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
    virtual float v32();
};

class ClassDB4 {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual float v25();
};

class ClassDB4b {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26(float);
};

struct SelfBase { char pad[0x3C]; };
class SelfObj : public SelfBase {
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
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
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
};

extern "C" void fn_27_28F9BC(char* arg0, char* arg1) {
    if (((Lbl71C8Obj*)&lbl_27_bss_71C8)->v6(arg0 + 0xCC, 0x5B6D, 0) == 1) {
        if (((Lbl71C8Obj*)&lbl_27_bss_71C8)->v6(arg1 + 0xCC, 0x5B6D, 0) == 1) {
            float f;
            if (((Lbl71C8Obj*)&lbl_27_bss_71C8)->v6(arg1 + 0xCC, 0x5B6D, 0) == 1) {
                Class1A4* obj = *(Class1A4**)(*(char**)(arg1 + 0x1A4) + 0x70);
                int val;
                if (obj->v16() == 2) {
                    val = 1;
                } else {
                    Class27A8* c27 = (Class27A8*)(arg1 + 0x27A8);
                    val = c27->v9(3);
                }
                if (val != 0) {
                    Class27A8* c27 = (Class27A8*)(arg1 + 0x27A8);
                    f = c27->v32();
                } else {
                    ClassDB4* cdb4 = (ClassDB4*)(arg1 + 0xDB4);
                    f = cdb4->v25();
                }
            } else {
                f = lbl_27_rodata_461C;
            }
            ClassDB4b* cdb4b = (ClassDB4b*)(arg0 + 0xDB4);
            cdb4b->v26(f);
            SelfObj* selfObj = (SelfObj*)arg0;
            selfObj->v43();
        }
    }
}
