#pragma force_active on
extern "C" {

class ftYoshi {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

void fn_95_F0BC(ftYoshi *yoshi)
{
    yoshi->v2();
}

}
