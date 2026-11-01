#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef float f32;

struct Module38Prefix {
    void* words[2];
};

struct WorkModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void setInt(u32);
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual int getInt(u32);
    virtual void setWork(u32);
};

struct WorkFloatModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void setFloat(f32, u32);
};

struct StatusModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual int getStatus();
};

struct Module38Secondary : Module38Prefix {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void apply(f32, f32, void*, s32, u32, u32);
};

struct Arg1Object {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual int getValue(u32, u32);
};

struct ResultObject {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void setValue(s32);
};

extern "C" void* getInstance__15gfTaskSchedulerFv();
extern "C" void* getTask__15gfTaskSchedulerFUl(void*, u32);
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" void* fn_27_8CE04(void*);
extern "C" s32 getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, u32, u32);
extern "C" void fn_27_135848(void*, void*, f32, void*, s32, f32, f32, s32);
extern "C" char lbl_119_data_1E14[];
extern "C" char lbl_119_data_1F14[];

extern "C" void fn_119_7C64(void* self, void* arg1, f32 farg0, void* arg2,
                             s32 flag, f32 farg1, f32 farg2, s32 arg7) {
    if (((StatusModule*)*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)self +
                                                                  0x60) +
                                                    0xD8) +
                                    0x70))
                ->getStatus() == 0x115 &&
        flag == 1) {
        if (((WorkModule*)*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)self +
                                                                    0x60) +
                                                      0xD8) +
                                      0x64))
                ->getInt(0x22000013) == 0) {
            ((WorkModule*)*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)self +
                                                                    0x60) +
                                                      0xD8) +
                                      0x64))
                ->setWork(0x22000013);

            ((WorkFloatModule*)*(void**)((u8*)*(void**)((u8*)*(void**)(
                (u8*)self + 0x60) + 0xD8) + 0x64))
                ->setFloat(farg0, 0x21000004);

            s32 value = ((Arg1Object*)arg1)->getValue(
                *((u8*)arg2 + 0x24), *((u8*)arg2 + 0x27));

            void* module38 =
                *(void**)((u8*)*(void**)((u8*)*(void**)((u8*)self + 0x60) +
                                         0xD8) +
                          0x38);
            ((Module38Secondary*)module38)
                ->apply(farg1, farg2, arg1, value,
                        *((u8*)arg2 + 0x24), *((u8*)arg2 + 0x27));

            ((WorkModule*)*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)self +
                                                                    0x60) +
                                                      0xD8) +
                                      0x64))
                ->setInt(0x21000005);
        }

        void* task = getTask__15gfTaskSchedulerFUl(
            getInstance__15gfTaskSchedulerFv(),
            *(u32*)((u8*)arg2 + 0x0C));
        void* cast = __dynamic_cast(task, 0x3C, lbl_119_data_1E14,
                                    lbl_119_data_1F14, 1);
        void* result = fn_27_8CE04(cast);
        s32 constant =
            getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                *(void**)((u8*)self + 0x60), 0x5DC7, 0);
        ((ResultObject*)result)->setValue(constant);
    }

    fn_27_135848(self, arg1, farg0, arg2, flag, farg1, farg2, arg7);
}
