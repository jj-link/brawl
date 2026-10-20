#include <stddef.h>
#pragma force_active on

struct CallbackData {
    unsigned int unk0;
    unsigned int flags;
};

struct Callback {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void setup(int, int);

    CallbackData* data;
    unsigned int count;
    unsigned char pad[0x8C - 12];

    void init(int n, int heap) {
        if (this == NULL) return;
        count = n;
        setup(0, heap);
        data->flags |= 1;
    }
};

struct Base {
    unsigned char pad0[0x3C];
};

struct ObjectInterface : Base {
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
    virtual void setA(int);
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void setB(const char*);

    unsigned char pad1[0xD0 - 0x40];
    Callback callback;
    unsigned int field15C;
    unsigned int field160;
    unsigned char field164;
    unsigned char field165;
    unsigned char pad2[2];
    void* field168;
};

extern "C" {
    void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
    void fn_78_1768(ObjectInterface*, const char*);
    extern char lbl_78_data_1390[];
}

namespace Heaps {
    enum HeapType {
        StageInstance = 15
    };
}

inline void* operator new(unsigned long size, Heaps::HeapType heap) {
    return __nw__FUlQ25Heaps8HeapType(size, heap);
}

struct Object {
    unsigned char storage[0x16C];

    Object(const char* name) {
        ObjectInterface* obj = (ObjectInterface*)this;
        fn_78_1768(obj, name);
        *(void**)((char*)obj + 0x3C) = lbl_78_data_1390;
        obj->field15C = 0;
        obj->field160 = 0;
        obj->field164 = 0;
        obj->field165 = 0;
        obj->field168 = 0;

        Callback* cb = (Callback*)((unsigned long)this + 0xD0);
        if (cb == NULL) return;
        cb->count = 1;
        cb->setup(0, 15);
        cb->data->flags |= 1;
    }
};

extern "C" Object* fn_78_37EC(int arg0, const char* arg1, const char* arg2) {
    Object* obj = new (Heaps::StageInstance) Object(arg2);
    if (obj != NULL) {
        ((ObjectInterface*)obj)->setA(arg0);
        ((ObjectInterface*)obj)->setB(arg1);
    }
    return obj;
}
