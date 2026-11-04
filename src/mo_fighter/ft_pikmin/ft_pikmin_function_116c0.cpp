#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#include <math.h>
#pragma force_active on

struct TargetBase { char pad[0x3c]; };
class Target : public TargetBase {
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
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void changeStatus(int);
};
struct Owner { void* unused; void* manager; };
extern "C" {
int fn_113_243CC(void*);
Target* fn_113_244FC(void*);
void fn_113_24654(void*);
void fn_113_24D34(void*, Target*, float);
void fn_113_24D3C(void*, Target*, Vec2f*);
unsigned int fn_113_24D74(void*, Target*, int);
void fn_113_24D80(void*, Target*);
void fn_113_25108(void*, Target*, unsigned int);
void fn_113_25114(void*, Target*, unsigned int, float);
void fn_113_25330(void*, Target*);
void fn_113_B7F0(Vec2f*, const Vec3f*);
void fn_8003DC64(Vec2f*, float, Vec2f*);
extern const float lbl_113_rodata_30;
}

static inline void addPosition(Vec2f& result, const Vec2f& base, const Vec2f& offset) {
    Vec2f sum;
    sum.m_x = base.m_x + offset.m_x;
    sum.m_y = base.m_y + offset.m_y;
    Vec2f::copy(result, sum);
}

static inline void setPosition(Owner* self, const Vec2f& base, const Vec2f& offset) {
    Vec2f sum;
    sum.m_x = base.m_x + offset.m_x;
    sum.m_y = base.m_y + offset.m_y;
    Vec2f result;
    Vec2f::copy(result, sum);
    void* manager = self->manager;
    fn_113_24D3C(manager, fn_113_244FC(manager), &result);
}

extern "C" void fn_113_116C0(Owner* self, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000010) == 1U) {
        accesser->getWorkManageModule().offFlag(0x22000010);
        if (fn_113_243CC(self->manager) > 0) {
            if (accesser->getWorkManageModule().isFlag(0x22000011) == 1U) {
                void* manager = self->manager;
                fn_113_25108(manager, fn_113_244FC(manager), 0x22000000);
            }
            void* manager = self->manager;
            if (fn_113_24D74(manager, fn_113_244FC(manager), -1) == 1U) {
                void* manager = self->manager;
                fn_113_24D80(manager, fn_113_244FC(manager));
            }
            manager = self->manager;
            float lr = accesser->getPostureModule().getLr();
            fn_113_24D34(manager, fn_113_244FC(manager), lr);
            float angle = lbl_113_rodata_30;
            if (accesser->getSituationModule().getKind() == 0 &&
                accesser->getGroundModule().isTouch(static_cast<grCollStatus::TouchMask>(8), 0) == 1U) {
                Vec2f normal;
                Vec2f::copy(normal, accesser->getGroundModule().getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0));
                float y = normal.m_y;
                float x = normal.m_x;
                angle = (float)atan2(x, y);
                if (lbl_113_rodata_30 != angle) {
                    void* manager = self->manager;
                    fn_113_25114(manager, fn_113_244FC(manager), 0x21000000, angle);
                }
            }
            Vec3f pos = accesser->getModelModule().getNodeGlobalPosition(0, false);
            Vec2f base;
            fn_113_B7F0(&base, &pos);
            Vec2f offset(soValueAccesser::getConstantFloat(accesser, 0xfa2, 0),
                         soValueAccesser::getConstantFloat(accesser, 0xfa3, 0));
            if (accesser->getPostureModule().getLr() < lbl_113_rodata_30)
                offset.m_x = -offset.m_x;
            if (lbl_113_rodata_30 != angle)
                fn_8003DC64(&offset, -angle, &offset);
            float scale = accesser->getPostureModule().getScale();
            offset.m_x *= scale;
            offset.m_y *= scale;
            setPosition(self, base, offset);
            fn_113_244FC(self->manager)->changeStatus(0x15);
            manager = self->manager;
            fn_113_25330(manager, fn_113_244FC(manager));
            fn_113_24654(self->manager);
        }
    }
}
