#pragma force_active on
class gfApplication {
public:
    void restart();
};

extern "C" {
void fn_801E9A30(int);
void fn_801E98B0(void);
void fn_801FF1AC(void);
void VIWaitForRetrace(void);
void fn_801DF434(int);
}

void gfApplication::restart()
{
    fn_801E9A30(1);
    fn_801E98B0();
    fn_801FF1AC();
    VIWaitForRetrace();
    VIWaitForRetrace();
    fn_801DF434(2);
}
