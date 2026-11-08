#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_5F2FC(void*, int, void*, void*, float, float, void*, unsigned);
void fn_27_23313C(unsigned, unsigned, unsigned, unsigned char);
void fn_41_119D4(void*, void*);
void fn_41_11830(void*, void*);
void fn_41_12014(void*);
extern const char __RTTI__5Enemy[];
extern const char __RTTI__11StageObject[];
extern int g_stTriggerMng;
extern const float lbl_41_rodata_BE0;
}

class soNullable {
public:
    virtual void* v0() = 0;
    virtual void* v1() = 0;
    virtual void* v2() = 0;
    virtual void* v3() = 0;
    virtual void* v4() = 0;
    virtual void* v5() = 0;
    virtual void* v6() = 0;
    virtual void* v7() = 0;
    virtual void* v8() = 0;
    virtual void* v9() = 0;
    virtual void* v10() = 0;
    virtual void* v11() = 0;
    virtual void* v12() = 0;
    virtual void* v13() = 0;
    virtual void* v14() = 0;
    virtual void* v15() = 0;
    virtual void* v16() = 0;
    virtual unsigned v17(unsigned) = 0;
};

class Class_6E20 {
public:
    virtual void* v0() = 0;
    virtual void* v1(void*) = 0;
};

extern "C" void fn_41_12BB8(void* arg0, int arg1, void* arg2, void* arg3, float farg0, float farg1, void* arg4, unsigned arg5) {
    if (arg5 != 1u && *(unsigned char*)((char*)arg2 + 0x29) == 1u) {
        fn_27_5F2FC(arg0, arg1, arg2, arg3, farg0, farg1, arg4, arg5);
        return;
    }

    void* cast = __dynamic_cast(*(void**)((char*)arg4 + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
    unsigned field28 = *(unsigned*)((char*)cast + 0x28);

    fn_27_5F2FC(arg0, arg1, arg2, arg3, farg0, farg1, arg4, arg5);

    if (arg5 == 0u && g_stTriggerMng != 0 && *(unsigned*)((char*)arg2 + 0xc) != field28) {
        fn_27_23313C(*(unsigned*)((char*)cast + 0xb0), *(unsigned*)((char*)arg2 + 0xc), field28, *(unsigned char*)((char*)arg2 + 0x22));
    }

    soNullable* obj = *(soNullable**)((char*)arg4 + 0xd8);
    obj = *(soNullable**)((char*)obj + 0x64);
    if (obj->v17(0x12000000u) != 1u) {
        Class_6E20* obj40 = *(Class_6E20**)((char*)arg0 + 0x40);
        void* result = obj40->v1(arg3);
        if (*(float*)((char*)result + 4) <= lbl_41_rodata_BE0 &&
            *(float*)((char*)result + 0xc) <= lbl_41_rodata_BE0) {
            if (*(int*)((char*)arg0 + 0xdc) == 1) {
                *(int*)((char*)arg0 + 0xdc) = -1;
                fn_41_119D4(arg0, arg2);
                fn_41_11830(arg0, result);
                fn_41_12014(arg0);
            } else {
                *(int*)((char*)arg0 + 0xdc) = -1;
            }
        }
    }
}
