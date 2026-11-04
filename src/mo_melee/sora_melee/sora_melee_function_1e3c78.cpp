#include <mt/mt_vector.h>
#include <memory.h>
#pragma force_active on
struct Flags {
    unsigned char first:1, second:1, third:1, fourth:1, fifth:1, sixth:1, seventh:1, eighth:1;
    unsigned char ninth:1, tenth:1, reserved:6;
};
struct Initialize {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};
struct Values { unsigned int a,b,c,d,e,f,g,h; };
struct Energy {
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3();
    virtual void e4(); virtual void e5(); virtual void* get(int);
};
struct Posture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void set(float);
};
struct Motion {
    char pad[8];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void set(int,int);
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86(); virtual void v87();
    virtual void v88(); virtual void v89(); virtual void v90(); virtual void v91();
    virtual void v92(); virtual void v93(); virtual void v94(); virtual void v95();
    virtual void v96(); virtual void v97(); virtual void v98(); virtual void v99();
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106(); virtual void v107();
    virtual void v108(); virtual void v109(); virtual void v110(); virtual void v111();
    virtual int check(int);
};
struct Ground {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void set(int,int);
};
struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void on(int);
};
struct Effect {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual int create(int, const Vec3f*, const Vec3f*, int, int, float);
};
struct Other {
    char pad[8];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void extra(); virtual void set1(int,int);
    virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void set2(int,int);
};
struct Modules {
    char pad[0xc]; Posture* posture; Motion* motion; Ground* ground;
    char pad2[0x4c]; Work* work;
    char pad3[0x14]; Energy* energy;
    char pad4[8]; Effect* effect;
    char pad5[0x2c]; Other* other;
};
struct Owner { char pad[0xd8]; Modules* modules; };
struct Object { char pad[0x60]; Owner* owner; char pad2[0x944]; Values first, second; int effect; };
struct Result { char pad[8]; float x,y,a,b,c,d,e,f,g,h; };
extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_2B70, lbl_27_rodata_2B78;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_1D8370(void*, const Initialize*);
void fn_27_1E3C78(Object* self, const Vec3f* pos, const float* speed, const Values* first, const Values* second, int effect, int a, int b, float lr, float facing) {
    Initialize init;
    init.resource=-1;
    init.team=0xffff; init.teamOwner=0xffff; init.teamAnother=0xffff;
    init.index=-1; init.owner=-1;
    init.reserved0=0; init.reserved1=0;
    __memcpy(&init.position,pos,sizeof(Vec3f));
    init.facing=facing;
    init.parameter=-1; init.variant=0; init.situation=2; init.status=0x80;
    init.reserved2=0; init.motion=0x35f; init.reserved3=0;
    init.flags.first=1; init.flags.second=0; init.flags.third=0; init.flags.fourth=0;
    init.flags.fifth=1; init.flags.sixth=0; init.flags.seventh=0; init.flags.eighth=0;
    init.flags.ninth=0; init.flags.tenth=0;
    fn_27_1D8370(self,&init);
    self->owner->modules->posture->set(lr);
    self->owner->modules->other->set1(a,0);
    self->owner->modules->other->set2(b,0);
    self->first=*first;
    self->second=*second;
    Result* result=(Result*)__dynamic_cast(self->owner->modules->energy->get(0),0,lbl_27_data_457C0,lbl_27_data_CDF8,1);
    result->x=speed[0]; result->y=speed[1];
    if(self->owner->modules->motion->check(0)) {
        self->owner->modules->motion->set(1,0);
        self->owner->modules->ground->set(0,0);
        float* v=(float*)&self->first;
        result->a=v[0]; result->b=v[1]; result->e=v[2]; result->f=v[3];
        result->c=v[4]; result->d=v[5]; result->g=v[6]; result->h=v[7];
    } else {
        self->owner->modules->motion->set(5,0);
        self->owner->modules->ground->set(2,0);
        float* v=(float*)&self->second;
        result->a=v[0]; result->b=v[1]; result->e=v[2]; result->f=v[3];
        result->c=v[4]; result->d=v[5]; result->g=v[6]; result->h=v[7];
    }
    if(effect) {
        Vec3f zero(lbl_27_rodata_2B78,lbl_27_rodata_2B78,lbl_27_rodata_2B78);
        self->effect=self->owner->modules->effect->create(effect,pos,&zero,0x20,-1,lbl_27_rodata_2B70);
    }
    self->owner->modules->work->on(0x12000000);
}
}