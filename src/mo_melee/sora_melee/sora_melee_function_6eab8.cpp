#pragma force_active on
struct ArgData { int type; int value; };
struct ArgResult { ArgData* data; unsigned char flag; };
struct PairArg { int value; signed char flag; PairArg(int v):value(v),flag(0) {} };
class Self { public:
virtual void v0(); virtual signed char category(); virtual signed char type(); virtual int count(); virtual void v4(); virtual void v5(); virtual bool getArg(ArgResult*, int) const;
};
class Cmd { public:
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void call8(int);
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void call15(int, const PairArg&);
virtual void call16(int, const PairArg&, int);
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
virtual void call75(int,int,int,unsigned short,bool);
virtual void v76();
virtual void v77();
virtual void v78();
virtual void v79();
virtual void v80();
virtual void v81();
virtual void call82(int);
virtual void call83(int);
virtual void v84();
virtual void call85(float*,float*);
virtual void v86();
virtual void call87(int);
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
virtual void call99(int,int,int);
virtual void v100();
virtual void v101();
virtual void v102();
virtual void v103();
virtual void v104();
virtual void v105();
virtual void v106();
virtual void v107();
virtual void v108();
virtual void v109();
virtual void v110();
virtual void v111();
virtual void v112();
virtual void v113();
virtual void v114();
virtual void v115();
virtual void v116();
virtual void v117();
virtual bool accept(signed char);
};
struct GroundBase { char pad[0x3c]; };
class Ground : public GroundBase { public:
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
virtual int getMdlIndex();
};
struct Access { void* pad; void* pad2; Ground* ground; };
extern const float lbl_27_rodata_950;
extern "C" int fn_27_6EAB8(Cmd* cmd, Self* self, Access* acc) {
 if (cmd->accept(self->category()) == 0) return 0;
 if (self->type() <= -1 || self->type() >= 0xA) return 0;
 int shared;
 switch (self->type()) {
 case 0: {
 ArgResult local0; local0.data=0; local0.flag=0;
 if (self->getArg(&local0,0)==0) return 1;
 int val0; if(local0.flag==1) val0=0; else val0=local0.data->value;
 ArgResult local1; local1.data=0; local1.flag=0;
 if (self->getArg(&local1,1)==0) return 1;
 if(local1.flag==1) shared=0; else shared=local1.data->value;
 ArgResult local2; local2.data=0; local2.flag=0;
 if (self->getArg(&local2,2)==0) return 1;
 int val2; if(local2.flag==1) val2=0; else val2=local2.data->value;
 ArgResult local3; local3.data=0; local3.flag=0; int val3=3;
 if ((unsigned int)self->getArg(&local3,3)==1U) {
 int t; if(local3.flag==1) t=-1; else t=local3.data->type;
 if(t==0) { int v; if(local3.flag==1) v=0; else v=local3.data->value; val3=v & 0xFFFF; }
 }
 cmd->call75(val0,shared,val2,val3,1); return 1;
 }
 case 1: {
 if(self->count()<=0) cmd->call87(1);
 else { ArgResult local; local.data=0; local.flag=0; if(self->getArg(&local,0)==0) return 1; int val; if(local.flag==1) val=0; else val=local.data->value!=0; cmd->call87(val); }
 return 1;
 }
 case 2: {
 float arr0[3]; float arr1[3];
 arr0[0]=lbl_27_rodata_950; arr0[1]=lbl_27_rodata_950; arr0[2]=lbl_27_rodata_950;
 arr1[0]=lbl_27_rodata_950; arr1[1]=lbl_27_rodata_950; arr1[2]=lbl_27_rodata_950;
 cmd->call85(arr0,arr1); acc->ground->getMdlIndex(); return 1;
 }
 case 3: {
 ArgResult local0; local0.data=0; local0.flag=0; if(self->getArg(&local0,0)==0) return 1;
 if(local0.flag==1) shared=0; else shared=local0.data->value;
 ArgResult local1; local1.data=0; local1.flag=0; if(self->getArg(&local1,1)==0) return 1;
 int val1; if(local1.flag==1) val1=0; else val1=local1.data->value;
 cmd->call15(shared,PairArg(val1)); return 1;
 }
 case 4: {
 ArgResult local0; local0.data=0; local0.flag=0;
 if(self->getArg(&local0,0)==0) goto fail0;
 { int t; if(local0.flag==1) t=-1; else t=local0.data->type;
 if(t==0) goto next; }
 fail0: return 1;
 next:
 ArgResult local1; local1.data=0; local1.flag=0;
 if(self->getArg(&local1,1)==0) goto fail1;
 { int t1; if(local1.flag==1) t1=-1; else t1=local1.data->type;
 if(t1==0) goto call; }
 fail1: return 1;
 call:
 int val0; if(local0.flag==1) val0=0; else val0=local0.data->value;
 int val1; if(local1.flag==1) val1=0; else val1=local1.data->value;
 cmd->call16(val0,PairArg(val1),0); return 1;
 }
 case 5: case 6: {
 int extra;
 ArgResult local0; local0.data=0; local0.flag=0; if(self->getArg(&local0,0)==0) return 1;
 int val0; if(local0.flag==1) val0=0; else val0=local0.data->value;
 ArgResult local1; local1.data=0; local1.flag=0; if(self->getArg(&local1,1)==0) return 1;
 int val1; if(local1.flag==1) val1=0; else val1=local1.data->value;
 extra=1; if(self->type()==6) extra=0; cmd->call99(val0,val1,extra); return 1;
 }
 case 7: {
 ArgResult local; local.data=0; local.flag=0; if(self->getArg(&local,0)==0) return 1;
 int val; if(local.flag==1) val=0; else val=local.data->value; cmd->call8(val); return 1;
 }
 case 8: {
 ArgResult local; local.data=0; local.flag=0; if(self->getArg(&local,0)==0) return 1;
 int val; if(local.flag==1) val=0; else val=local.data->value; cmd->call82(val); return 1;
 }
 case 9: {
 ArgResult local; local.data=0; local.flag=0; if(self->getArg(&local,0)==0) return 1;
 int val; if(local.flag==1) val=0; else val=local.data->value; cmd->call83(val); return 1;
 }
 default: return 0;
 }
}