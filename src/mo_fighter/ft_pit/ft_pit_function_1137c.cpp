#pragma force_active on
// Null article singleton accessor for the Pit (ft_pit) module.
//
// The module keeps one shared "null" soArticle object in its BSS section; this
// accessor simply hands out a reference to it, so the caller may safely call
// the article's virtual methods without a NULL check.

extern "C" {
extern unsigned char lbl_27_bss_1CC[];
}

struct soLogAttackInfo {
    int _0;
    int _4;
    int _8;
};

enum SituationKind {
    SituationKind_Ground = 0,
    SituationKind_Air,
    SituationKind_Escape,
    SituationKind_ItemHold,
    SituationKind_Entry,
    SituationKind_Dead,
    SituationKind_Number5,
    SituationKind_Number6,
    SituationKind_Number7,
    SituationKind_Number8,
    SituationKind_Number9,
    SituationKind_Number10,
    SituationKind_Number11,
    SituationKind_Number12,
    SituationKind_Number13,
    SituationKind_Number14,
    SituationKind_Number15,
    SituationKind_Number16,
    SituationKind_Number17,
    SituationKind_Number18,
    SituationKind_Number19,
    SituationKind_Number20,
    SituationKind_Number21,
    SituationKind_Number22,
    SituationKind_Number23,
    SituationKind_Number24,
    SituationKind_Number25,
    SituationKind_Number26,
    SituationKind_Number27,
    SituationKind_Number28,
    SituationKind_Number29,
    SituationKind_Number30,
    SituationKind_Number31,
};

class soArticle {
public:
    virtual ~soArticle();
    virtual void remove() = 0;
    virtual int getArticleId() = 0;
    virtual int getArticleEventManageId() = 0;
    virtual int getTaskId() = 0;
    virtual void changeMotion(int motionKind, bool);
    virtual void setFrame(float frame);
    virtual void setRate(float rate);
    virtual void changeStatus(int statusKind);
    virtual void setVisibilityWhole(unsigned char);
    virtual void setVisibility(int, unsigned char);
    virtual void set2nd(unsigned char);
    virtual void action(int);
    virtual void setSituationKind(SituationKind);
    virtual bool isConstraint();
    virtual void deactivateDescendantForce();
    virtual bool isActiveArticle() = 0;
    virtual void deactivateArticle() = 0;
    virtual int getOwnerDeactiveTreatType();
    virtual int getFounderTaskId();
    virtual void have(int, int, int) = 0;
    virtual void linkOwner(int, int) = 0;
    virtual void unlinkOwner(int) = 0;
    virtual bool isSyncOwnerStatus() = 0;
    virtual void setSyncOwnerStatus(bool) = 0;
    virtual void setLogAttackInfo(soLogAttackInfo* logAttackInfo);
    virtual soLogAttackInfo getLogAttackInfo();
    virtual void updateLogAttackInfo();
    virtual void intrudeLogAttackInfo();
    virtual float getActiveGlobalFrame();
    virtual void setAttackPowerMulPattern(float);
};

extern "C" soArticle& fn_112_1137C() {
    return *reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
}
