#pragma force_active on
extern "C" void fn_8003820C(void*, int);

class gfApplication {
public:
    ~gfApplication();
};

gfApplication::~gfApplication() {
    fn_8003820C(this, -1);
}
