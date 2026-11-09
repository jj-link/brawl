#include <types.h>
#pragma force_active on

struct Class_1768_base {
    unsigned char pad[0xc];
};

class Class_1768 : public Class_1768_base {
public:
    virtual void fn_27_1DCD4();
    virtual int fn_27_1D618();
};

struct Class_90D8_base {
    unsigned char pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C(void*, float);
};

struct D {
    unsigned char pad[0x38];
    Class_90D8* m_38;
};

struct B {
    unsigned char pad[0xd8];
    D* m_d8;
};

struct Self_base {
    unsigned char pad[0x3c];
};

#define V10(a, b, c, d, e, f, g, h, i, j) \
    virtual void a();                       \
    virtual void b();                       \
    virtual void c();                       \
    virtual void d();                       \
    virtual void e();                       \
    virtual void f();                       \
    virtual void g();                       \
    virtual void h();                       \
    virtual void i();                       \
    virtual void j()

class Self_0 : public Self_base {
public:
    V10(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9);
};
class Self_1 : public Self_0 {
public:
    V10(v10, v11, v12, v13, v14, v15, v16, v17, v18, v19);
};
class Self_2 : public Self_1 {
public:
    V10(v20, v21, v22, v23, v24, v25, v26, v27, v28, v29);
};
class Self_3 : public Self_2 {
public:
    V10(v30, v31, v32, v33, v34, v35, v36, v37, v38, v39);
};
class Self_4 : public Self_3 {
public:
    V10(v40, v41, v42, v43, v44, v45, v46, v47, v48, v49);
};
class Self_5 : public Self_4 {
public:
    V10(v50, v51, v52, v53, v54, v55, v56, v57, v58, v59);
};
class Self_6 : public Self_5 {
public:
    V10(v60, v61, v62, v63, v64, v65, v66, v67, v68, v69);
};
class Self_7 : public Self_6 {
public:
    V10(v70, v71, v72, v73, v74, v75, v76, v77, v78, v79);
};
class Self_8 : public Self_7 {
public:
    V10(v80, v81, v82, v83, v84, v85, v86, v87, v88, v89);
};
class Self_9 : public Self_8 {
public:
    V10(v90, v91, v92, v93, v94, v95, v96, v97, v98, v99);
};
class Self_10 : public Self_9 {
public:
    V10(v100, v101, v102, v103, v104, v105, v106, v107, v108, v109);
};
class Self_11 : public Self_10 {
public:
    V10(v110, v111, v112, v113, v114, v115, v116, v117, v118, v119);
};
class Self_12 : public Self_11 {
public:
    V10(v120, v121, v122, v123, v124, v125, v126, v127, v128, v129);
};
class Self_13 : public Self_12 {
public:
    V10(v130, v131, v132, v133, v134, v135, v136, v137, v138, v139);
};
class Self_14 : public Self_13 {
public:
    V10(v140, v141, v142, v143, v144, v145, v146, v147, v148, v149);
};
class Self_15 : public Self_14 {
public:
    V10(v150, v151, v152, v153, v154, v155, v156, v157, v158, v159);
};
class Self_16 : public Self_15 {
public:
    V10(v160, v161, v162, v163, v164, v165, v166, v167, v168, v169);
};
class Self_17 : public Self_16 {
public:
    V10(v170, v171, v172, v173, v174, v175, v176, v177, v178, v179);
};

class Self : public Self_17 {
public:
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual Class_1768* cb(float);

    unsigned char pad[0x20];
    B* m_60;
};

#undef V10

extern "C" void fn_27_1571DC(void*, int, int, float);
extern const float lbl_27_rodata_1048;

extern "C" void fn_27_13C724(Self* self, float f) {
    Class_1768* result = self->cb(f);
    B* b = self->m_60;
    b->m_d8->m_38->fn_27_7B22C(b, f);
    if (result->fn_27_1D618() == 0) {
        fn_27_1571DC((char*)self + 0x13c, 0, 0, lbl_27_rodata_1048);
    }
}
