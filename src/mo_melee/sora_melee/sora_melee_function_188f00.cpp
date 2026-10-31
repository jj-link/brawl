#include <types.h>
#pragma force_active on

#define VIRTUALS_2 \
    virtual void v0(); virtual void v1();
#define VIRTUALS_4 \
    VIRTUALS_2 virtual void v2(); virtual void v3();
#define VIRTUALS_8 \
    VIRTUALS_4 virtual void v4(); virtual void v5(); \
    virtual void v6(); virtual void v7();
#define VIRTUALS_16 \
    VIRTUALS_8 virtual void v8(); virtual void v9(); \
    virtual void v10(); virtual void v11(); \
    virtual void v12(); virtual void v13(); \
    virtual void v14(); virtual void v15();
#define VIRTUALS_32 \
    VIRTUALS_16 virtual void v16(); virtual void v17(); \
    virtual void v18(); virtual void v19(); \
    virtual void v20(); virtual void v21(); \
    virtual void v22(); virtual void v23(); \
    virtual void v24(); virtual void v25(); \
    virtual void v26(); virtual void v27(); \
    virtual void v28(); virtual void v29(); \
    virtual void v30(); virtual void v31();
#define VIRTUALS_64 \
    VIRTUALS_32 virtual void v32(); virtual void v33(); \
    virtual void v34(); virtual void v35(); \
    virtual void v36(); virtual void v37(); \
    virtual void v38(); virtual void v39(); \
    virtual void v40(); virtual void v41(); \
    virtual void v42(); virtual void v43(); \
    virtual void v44(); virtual void v45(); \
    virtual void v46(); virtual void v47(); \
    virtual void v48(); virtual void v49(); \
    virtual void v50(); virtual void v51(); \
    virtual void v52(); virtual void v53(); \
    virtual void v54(); virtual void v55(); \
    virtual void v56(); virtual void v57(); \
    virtual void v58(); virtual void v59(); \
    virtual void v60(); virtual void v61(); \
    virtual void v62(); virtual void v63();
#define VIRTUALS_100 \
    VIRTUALS_64 virtual void v64(); virtual void v65(); \
    virtual void v66(); virtual void v67(); \
    virtual void v68(); virtual void v69(); \
    virtual void v70(); virtual void v71(); \
    virtual void v72(); virtual void v73(); \
    virtual void v74(); virtual void v75(); \
    virtual void v76(); virtual void v77(); \
    virtual void v78(); virtual void v79(); \
    virtual void v80(); virtual void v81(); \
    virtual void v82(); virtual void v83(); \
    virtual void v84(); virtual void v85(); \
    virtual void v86(); virtual void v87(); \
    virtual void v88(); virtual void v89(); \
    virtual void v90(); virtual void v91(); \
    virtual void v92(); virtual void v93(); \
    virtual void v94(); virtual void v95(); \
    virtual void v96(); virtual void v97(); \
    virtual void v98(); virtual void v99();

struct Query54 {
    VIRTUALS_8
    virtual void v8();
    virtual int query(int);
};

struct Clear54 {
    VIRTUALS_64
    virtual void v64(); virtual void v65(); \
    virtual void v66(); virtual void v67(); \
    virtual void v68(); virtual void v69(); \
    virtual void v70(); virtual void v71(); \
    virtual void v72(); virtual void v73(); \
    virtual void v74(); virtual void v75(); \
    virtual void v76(); virtual void v77(); \
    virtual void v78(); virtual void v79(); \
    virtual void v80(); virtual void v81(); \
    virtual void v82(); virtual void v83(); \
    virtual void v84(); virtual void v85(); \
    virtual void v86(); virtual void v87(); \
    virtual void v88(); virtual void v89(); \
    virtual void v90(); virtual void v91(); \
    virtual void v92(); virtual void v93(); \
    virtual void v94(); virtual void v95(); \
    virtual void v96(); virtual void v97(); \
    virtual void v98();
    virtual void clear(int, int, int);
};

struct Result24 {
    u32 words[6];
};

struct MotionObject {
    u32 pad[2];
    VIRTUALS_32
    virtual void v32();
    virtual int getValue(int);
    virtual void v34();
    virtual void v35();
    virtual Result24 setValue(int, int);
};

struct LocalObject {
    VIRTUALS_4
    virtual void v4();
    virtual void consume(const void*);
};

struct OwnerObject {
    u32 pad[15];
    VIRTUALS_32
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
    virtual void invoke();
};

struct Module14 {
    VIRTUALS_2
    virtual void v2();
    virtual int check();
    virtual void v4();
    virtual void v5();
    virtual void setup(int, int);
};

struct Module10 {
    u32 pad[2];
    VIRTUALS_16
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void update(int, int);
};

struct Module7C {
    VIRTUALS_8
    virtual void v8();
    virtual void query();
    virtual void v10();
    virtual void v11();
    virtual void update();
};

struct FlagModule {
    VIRTUALS_16
    virtual void v16();
    virtual int has(int, void*);
};

struct FinalModule {
    VIRTUALS_2
    virtual void v2();
    virtual void apply(int, void*);
};

extern "C" int fn_27_189200(void*);

extern "C" void fn_27_188F00(void* unused, char* self) {
    char* modules = *(char**)(self + 0xD8);

    if ((*(Query54**)(modules + 0x54))->query(0) != 0) {
        ((Clear54*)(*(Query54**)(*(char**)(self + 0xD8) + 0x54)))
            ->clear(0, 0, 0);
    }

    modules = *(char**)(self + 0xD8);
    MotionObject* motion = *(MotionObject**)(modules + 4);
    LocalObject* localObject = *(LocalObject**)(modules + 0xC);
    int value = motion->getValue(0);
    const Result24& local = motion->setValue(value, 0);
    localObject->consume(&local);

    OwnerObject* owner = *(OwnerObject**)(self + 8);
    owner->invoke();

    Module14* module14 = *(Module14**)(*(char**)(self + 0xD8) + 0x14);
    module14->setup(2, 1);

    Module10* module10 = *(Module10**)(*(char**)(self + 0xD8) + 0x10);
    module10->update(0, 0);

    Module7C* module7C = *(Module7C**)(*(char**)(self + 0xD8) + 0x7C);
    module7C->query();
    module7C->update();

    char* moduleBase = *(char**)(self + 0xD8);
    FlagModule* flag = *(FlagModule**)(moduleBase + 0x64);
    if (flag->has(0x22000012, moduleBase) == 0 &&
        fn_27_189200(self) != 0) {
        return;
    }

    int result =
        (*(Module14**)(*(char**)(self + 0xD8) + 0x14))->check();
    int mode = 0xE;
    if (result == 0) {
        mode = 0x17;
    }
    FinalModule* finalModule =
        *(FinalModule**)(*(char**)(self + 0xD8) + 0x70);
    finalModule->apply(mode, self);
}

#undef VIRTUALS_2
#undef VIRTUALS_4
#undef VIRTUALS_8
#undef VIRTUALS_16
#undef VIRTUALS_32
#undef VIRTUALS_64
#undef VIRTUALS_100
