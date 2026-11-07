#include <types.h>
#include "ft/ft_common_data_accesser.h"
#pragma force_active on

extern "C" void fn_27_3611FC(s32, s32, s32);

struct AObjBase {
    char pad[0x3c];
};

class AObj : public AObjBase {
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
    virtual int v40();
};

struct SBase {
    char pad[0x8];
};

class SObj : public SBase {
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
    virtual u32 v55(s32 a, s32 b);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual u32 v62(s32 a, s32 b);
};

struct DObj {
    char pad[0x10];
    SObj* s;
};

struct Self {
    char pad0[0x8];
    AObj* a8;
    char pad1[0xcc];
    DObj* dd8;
};

extern "C" void fn_27_3610E8(Self* self) {
    s32 var_r31 = 0;
    s32 var_r30 = 0;
    s32 var_r29;
    char* d;

    if (self->a8->v40() == 0x19) {
        d = (char*)g_ftCommonDataAccesser.getData((ftKind)0x19);
        var_r31 = *(s32*)(d + 0x7c);
        var_r30 = *(s32*)(d + 0x80);
    } else {
        if (self->a8->v40() == 5) {
            d = (char*)g_ftCommonDataAccesser.getData((ftKind)5);
            var_r31 = *(s32*)(d + 0x174);
            var_r30 = *(s32*)(d + 0x178);
        }
    }
    var_r29 = 0;
    if (self->dd8->s->v55(8, 0) == 1) {
        var_r29 = self->dd8->s->v62(8, 0);
    }
    fn_27_3611FC(var_r29, var_r31, var_r30);
}
