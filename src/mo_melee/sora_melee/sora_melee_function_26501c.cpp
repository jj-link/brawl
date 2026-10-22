#pragma force_active on

class Ground {
public:
    void setValidAttachedEffect(unsigned long arg);
    char pad[0x3C];
};

class grYakumono : public Ground {
public:
    void setValidAttachedEffect(unsigned long arg0);
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9();
    virtual void v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(), v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29();
    virtual void v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49();
    virtual void v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59();
    virtual void v60(), v61(), v62(), v63(), v64(), v65(), v66(), v67(), v68(), v69();
    virtual void v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(), v79();
    virtual void v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89();
    virtual void v90(), v91(), v92(), v93(), v94(), v95();
    virtual void s98(unsigned long a, unsigned long b);
    virtual void s99(unsigned long a, unsigned long b);
    virtual void s100(unsigned long a);
    virtual void s101();
    virtual void s102();
};

void grYakumono::setValidAttachedEffect(unsigned long arg0) {
    Ground::setValidAttachedEffect(arg0);
    if (arg0 == 1) {
        this->s98(0, 0);
        this->s101();
    }
    if ((int)arg0 == 0) {
        this->s99(0, 0);
        this->s100(0);
        this->s102();
    }
}
