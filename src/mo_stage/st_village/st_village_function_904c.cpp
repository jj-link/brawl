#pragma force_active on
extern "C" {

struct StVillageSomething
{
    int a;
    int b;
    signed c : 2;
};

int fn_70_904C(struct StVillageSomething *p)
{
    return p->c;
}

}
