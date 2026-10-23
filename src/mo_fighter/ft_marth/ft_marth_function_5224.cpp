#include <types.h>
#pragma force_active on

class soEventUnit;
template <class T> class soInstanceUnit;
template <class T, int N> class soArrayVector;

template <class T, class Storage>
class soInstanceManagerSimpleEntity {
public:
    ~soInstanceManagerSimpleEntity();
};

template <class Observer, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

class soStatusEventObserver;
class soAnimCmdEventObserver;
class soDamageEventObserver;
class soLinkEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
class soArticleEventObserver;
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;
class soTurnEventObserver;
class soCollisionCatchEventObserver;

class soEventManageModuleImpl {
public:
    ~soEventManageModuleImpl();
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_5224(void* self, s16 del) {
    if (self) {
        typedef soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1> CatchUnit;
        typedef soEventUnitWithWorkArea<soTurnEventObserver, 2> TurnUnit;
        typedef soEventUnitWithWorkArea<soMotionEventObserver, 1> MotionUnit;
        typedef soEventUnitWithWorkArea<soItemManageEventObserver, 1> ItemUnit;
        typedef soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> SearchUnit;
        typedef soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> AbsorberUnit;
        typedef soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> ReflectorUnit;
        typedef soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> ShieldUnit;
        typedef soEventUnitWithWorkArea<soCaptureEventObserver, 4> CaptureUnit;
        typedef soEventUnitWithWorkArea<soArticleEventObserver, 5> ArticleUnit;
        typedef soEventUnitWithWorkArea<soModelEventObserver, 4> ModelUnit;
        typedef soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> AttackUnit;
        typedef soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> HitUnit;
        typedef soEventUnitWithWorkArea<soSituationEventObserver, 4> SituationUnit;
        typedef soEventUnitWithWorkArea<soLinkEventObserver, 4> LinkUnit;
        typedef soEventUnitWithWorkArea<soDamageEventObserver, 4> DamageUnit;
        typedef soEventUnitWithWorkArea<soAnimCmdEventObserver, 40> AnimCmdUnit;
        typedef soEventUnitWithWorkArea<soStatusEventObserver, 32> StatusUnit;
        typedef soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > InstanceManager;

        ((CatchUnit*)static_cast<char*>(self) + 0x998)->~CatchUnit();
        ((TurnUnit*)static_cast<char*>(self) + 0x954)->~TurnUnit();
        ((MotionUnit*)static_cast<char*>(self) + 0x918)->~MotionUnit();
        ((ItemUnit*)static_cast<char*>(self) + 0x8E0)->~ItemUnit();
        ((SearchUnit*)static_cast<char*>(self) + 0x884)->~SearchUnit();
        ((AbsorberUnit*)static_cast<char*>(self) + 0x828)->~AbsorberUnit();
        ((ReflectorUnit*)static_cast<char*>(self) + 0x7CC)->~ReflectorUnit();
        ((ShieldUnit*)static_cast<char*>(self) + 0x770)->~ShieldUnit();
        ((CaptureUnit*)static_cast<char*>(self) + 0x714)->~CaptureUnit();
        ((ArticleUnit*)static_cast<char*>(self) + 0x6AC)->~ArticleUnit();
        ((ModelUnit*)static_cast<char*>(self) + 0x650)->~ModelUnit();
        ((AttackUnit*)static_cast<char*>(self) + 0x5F4)->~AttackUnit();
        ((HitUnit*)static_cast<char*>(self) + 0x598)->~HitUnit();
        ((SituationUnit*)static_cast<char*>(self) + 0x53C)->~SituationUnit();
        ((LinkUnit*)static_cast<char*>(self) + 0x4E0)->~LinkUnit();
        ((DamageUnit*)static_cast<char*>(self) + 0x484)->~DamageUnit();
        ((AnimCmdUnit*)static_cast<char*>(self) + 0x278)->~AnimCmdUnit();
        ((StatusUnit*)static_cast<char*>(self) + 0xCC)->~StatusUnit();
        ((soEventManageModuleImpl*)static_cast<char*>(self) + 0xB8)->~soEventManageModuleImpl();
        ((InstanceManager*)self)->~InstanceManager();
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
