#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ac/ac_anim_cmd_impl.h>
#include <so/ground/so_ground_module_impl.h>
#pragma force_active on

extern f32 lbl_27_rodata_92C;
extern f32 lbl_27_rodata_928;

struct ArgArray {
    virtual bool isNull() const;
    virtual const acCmdArgConv& at(s32 index);
    virtual const acCmdArgConv& at(s32 index) const;
    const acCmdArgConv* m_elements;
    s32 m_size;
};

struct AnimCmd {
    virtual bool isNull() const;
    virtual s8 getGroup() const;
    virtual s8 getType() const;
    virtual s32 getArgNum() const;
    virtual u8 getOption() const;
    virtual ArgArray getArgList();
};

struct ArgWrap {
    const acCmdArgConv* m_dataPtr;
    u8 m_isNull;

    ArgWrap(const acCmdArgConv* p) : m_dataPtr(p), m_isNull(false) {}

    s32 getArgType() const {
        if (m_isNull == 1) {
            return -1;
        }
        return m_dataPtr->argType;
    }

    s32 getIntData() const {
        if (m_isNull == 1) {
            return 0;
        }
        return m_dataPtr->data;
    }
};

struct NotifySelf {
    virtual void slot0();
    virtual void slot1();
    virtual void notify(s32, s32, s32, Vec2f*);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual bool valid(s8);
    soModuleAccesser* m_acc;
};

struct GroundBase {
    char padding[8];
};

struct Ground : GroundBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual bool isTouch(s32, u32);
    virtual void slot56();
    virtual Vec2f getTouchNormal(s32, u32);
};

inline ArgWrap getArg(const ArgArray& list, s32 index) {
    return ArgWrap(&list.at(index));
}

extern "C" bool fn_27_68F4C(
    NotifySelf* self, AnimCmd* cmd, soModuleAccesser* acc, s32 unk3
) {
    if (!self->valid(cmd->getGroup())) {
        return false;
    }
    if (cmd->getType() <= -1 || cmd->getType() >= 1) {
        return false;
    }
    switch (cmd->getType()) {
    case 0: {
        const ArgArray args = cmd->getArgList();
        s32 v28;
        s32 v31;
        if (getArg(args, 0).getArgType() == 0) {
            v31 = getArg(args, 0).getIntData();
        } else if (getArg(args, 0).getArgType() == 5) {
            v31 = soValueAccesser::getValueInt(
                acc, getArg(args, 0).getIntData(), 0
            );
        } else {
            return true;
        }

        if (getArg(args, 1).getArgType() == 0) {
            v28 = getArg(args, 1).getIntData();
        } else if (getArg(args, 1).getArgType() == 5) {
            v28 = soValueAccesser::getValueInt(
                acc, getArg(args, 1).getIntData(), 0
            );
        } else {
            return true;
        }

        acc = reinterpret_cast<soModuleAccesser*>(
            self->m_acc->m_enumerationStart->m_groundModule
        );
        void* mask = reinterpret_cast<void*>(getArg(args, 2).getIntData());

        Vec2f vec;
        vec.m_x = lbl_27_rodata_92C;
        vec.m_y = lbl_27_rodata_928;

        bool hit = reinterpret_cast<Ground*>(acc)->isTouch(
            reinterpret_cast<s32>(mask), 0
        );
        if (hit == 1) {
            vec = reinterpret_cast<Ground*>(acc)->getTouchNormal(
                reinterpret_cast<s32>(mask), 0
            );
        }
        self->notify(v31, v28, hit, &vec);
        return true;
    }
    }
    return false;
}
