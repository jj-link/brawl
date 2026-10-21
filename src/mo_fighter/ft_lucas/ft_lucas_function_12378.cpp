#pragma force_active on

extern "C" {
extern char lbl_114_data_8460[];
extern char lbl_114_data_84E4[];
extern const float lbl_114_rodata_98;
extern const float lbl_114_rodata_9C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Work {
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
    virtual float getFloat(unsigned long);
};

struct Status {
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
    virtual int getKind();
};

struct Pad8 {
    int a, b;
};

struct Target : Pad8 {
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
    virtual void setValue(int, float);
};

struct Pad60 {
    char pad[0x3c];
};

struct Final : Pad60 {
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
    virtual void finish();
};

extern "C" void fn_114_12378(void*, char* self) {
    char* modules = *(char**)(self + 0xd8);
    Work* work = *(Work**)(modules + 0x64);
    Target* target = static_cast<Target*>(__dynamic_cast(
        *(void**)(modules + 4), 8,
        lbl_114_data_8460, lbl_114_data_84E4, 1));

    float value = work->getFloat(0x21000004);
    Status* status = *(Status**)(*(char**)(self + 0xd8) + 0x70);
    if (status->getKind() == 0x11e) {
        value *= lbl_114_rodata_98;
    }

    target->setValue(3, lbl_114_rodata_9C * value);
    Final* object = *(Final**)(self + 8);
    object->finish();
}
