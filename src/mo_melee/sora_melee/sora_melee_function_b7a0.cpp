// notifyEventAnimCmd__17soModelModuleImplFP9acAnimCmdP16soModuleAccesseri
// Status: 99.8% match, 50 lines differ. 36 of those are the compiler-generated
// int->float magic constant (original: lbl_27_rodata_310; ours: anonymous literal).
// About 14 further differing lines are not located yet.
#include <types.h>
#include <so/so_value_accesser.h>
#include <ac/ac_anim_cmd_impl.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern const f32 lbl_27_rodata_304;
extern const f32 lbl_27_rodata_30C;

struct ArgArray {
    virtual bool isNull();
    virtual const acCmdArgConv& at(s32 index);
    virtual const acCmdArgConv& at(s32 index) const;
    virtual s32 size() const;
    const acCmdArgConv* m_elements;
    s32 m_size;
    s32 m_link;
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

    f32 getFloatData() const {
        if (m_isNull == 1) {
            return lbl_27_rodata_304;
        }
        return m_dataPtr->data / lbl_27_rodata_30C;
    }
};

inline ArgWrap getArg(const ArgArray& list, s32 index) {
    return ArgWrap(&list.at(index));
}

inline s32 getListSize(const ArgArray& list) {
    return list.size();
}

struct SelfBase {
    char data[8];
};

class SelfModule : public SelfBase {
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
    virtual void set(s32 value);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual Vec3f getOtherVector(s32 id);
    virtual void setOtherVector(s32 id, const Vec3f& v);
    virtual Vec3f getVector(s32 id);
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void setVector(s32 id, const Vec3f& v);
    virtual Vec3f getThirdVector(s32 id);
    virtual void setThirdVector(s32 id, const Vec3f& v);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual Vec3f v36(s32 id, bool flag);
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46(s32 value);
    virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56();
    virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61();
    virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66();
    virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
    virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81();
    virtual void v82(); virtual void v83(); virtual void v84(); virtual void v85(); virtual void v86();
    virtual void v87(); virtual void v88(); virtual void v89(); virtual void v90();
    virtual bool valid(s8 group);

    char pad[0xbc];
    soModuleAccesser* m_moduleAccesser;
};

class SelfTail {
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
    virtual void v13(s32 id, f32 value);
};

#define READ_COMPONENT(component, index)                                     \
    if (getArg(list, index).getArgType() == 1)                               \
        component = getArg(list, index).getFloatData();                      \
    else if (getArg(list, index).getArgType() == 5)                          \
        component = soValueAccesser::getValueFloat(                          \
            acc, getArg(list, index).getIntData(), 0);                       \
    else                                                                     \
        return true

extern "C" bool notifyEventAnimCmd__17soModelModuleImplFP9acAnimCmdP16soModuleAccesseri(
    SelfModule* self, AnimCmd* acmd, soModuleAccesser* acc, s32 unk3)
{
    if (!self->valid(acmd->getGroup())) {
        return false;
    }
    if (acmd->getType() <= -1 || acmd->getType() >= 15) {
        return false;
    }

    switch (acmd->getType()) {
    case 0: {
        ArgArray list = acmd->getArgList();
        if (getListSize(list) == 0) {
            self->set(2);
        } else if (getListSize(list) == 1) {
            s32 value;
            if (getArg(list, 0).getArgType() == 0) {
                value = getArg(list, 0).getIntData();
            } else if (getArg(list, 0).getArgType() == 5) {
                value = soValueAccesser::getValueInt(acc, getArg(list, 0).getIntData(), 0);
            } else {
                return true;
            }
            self->set(value);
        } else {
            return true;
        }
        return true;
    }

    case 1:
    case 2:
    case 3:
    case 4: {
        ArgArray list = acmd->getArgList();
        s32 id = getArg(list, 0).getIntData();
        Vec3f vec = self->getVector(id);
        if (acmd->getType() == 1) {
            READ_COMPONENT(vec.m_x, 1);
            READ_COMPONENT(vec.m_y, 2);
            READ_COMPONENT(vec.m_z, 3);
        } else if (acmd->getType() == 2) {
            READ_COMPONENT(vec.m_x, 1);
        } else if (acmd->getType() == 3) {
            READ_COMPONENT(vec.m_y, 1);
        } else {
            READ_COMPONENT(vec.m_z, 1);
        }
        self->setVector(id, vec);
        return true;
    }

    case 11:
    case 12:
    case 13:
    case 14: {
        ArgArray list = acmd->getArgList();
        s32 id = getArg(list, 0).getIntData();
        Vec3f vec = self->getThirdVector(id);
        if (acmd->getType() == 11) {
            READ_COMPONENT(vec.m_x, 1);
            READ_COMPONENT(vec.m_y, 2);
            READ_COMPONENT(vec.m_z, 3);
        } else if (acmd->getType() == 2) {
            READ_COMPONENT(vec.m_x, 1);
        } else if (acmd->getType() == 3) {
            READ_COMPONENT(vec.m_y, 1);
        } else {
            READ_COMPONENT(vec.m_z, 1);
        }
        self->setThirdVector(id, vec);
        return true;
    }

    case 6:
    case 7:
    case 8:
    case 9: {
        ArgArray list = acmd->getArgList();
        s32 id = getArg(list, 0).getIntData();
        Vec3f vec = self->getOtherVector(id);
        if (acmd->getType() == 6) {
            READ_COMPONENT(vec.m_x, 1);
            READ_COMPONENT(vec.m_y, 2);
            READ_COMPONENT(vec.m_z, 3);
        } else if (acmd->getType() == 7) {
            READ_COMPONENT(vec.m_x, 1);
        } else if (acmd->getType() == 8) {
            READ_COMPONENT(vec.m_y, 1);
        } else {
            READ_COMPONENT(vec.m_z, 1);
        }
        self->setOtherVector(id, vec);
        return true;
    }

    case 5: {
        ArgArray list = acmd->getArgList();
        if (getArg(list, 0).getArgType() != 0) {
            return true;
        }
        self->v46(getArg(list, 0).getIntData());
        return true;
    }

    case 10: {
        ArgArray list = acmd->getArgList();
        u32 id = getArg(list, 0).getIntData();
        if (id == -1) {
            return true;
        }
        u32 a1 = getArg(list, 1).getIntData();
        u32 a2 = getArg(list, 2).getIntData();
        u32 a3 = getArg(list, 3).getIntData();
        Vec3f vec = self->v36(id, false);
        char* enumStart = *reinterpret_cast<char**>(reinterpret_cast<char*>(self->m_moduleAccesser) + 0xd8);
        SelfTail* o = *reinterpret_cast<SelfTail**>(enumStart + 0x64);
        o->v13(a1, vec.m_x);
        o->v13(a2, vec.m_y);
        o->v13(a3, vec.m_z);
        return true;
    }
    }

    return false;
}
