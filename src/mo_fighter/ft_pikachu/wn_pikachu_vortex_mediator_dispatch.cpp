// The same generator/operator interface layout is used by the reconstructed
// Vortex article callback; callback follows the two interface tables at0x20.
class VortexOwnerArticleGenerator {
public:
    virtual ~VortexOwnerArticleGenerator();
    virtual void* getArticleObject();
};
class VortexOwnerArticleOperator {
public:
    virtual ~VortexOwnerArticleOperator();
    virtual void* getArticleObject();
};
class VortexOwnerArticleMediator : public VortexOwnerArticleGenerator, public VortexOwnerArticleOperator {
public:
    virtual ~VortexOwnerArticleMediator();
    virtual void* getArticleObject();
    virtual void callback();
};

extern "C" void fn_98_19078(char* owner) {
    reinterpret_cast<VortexOwnerArticleMediator*>(owner + 0x1750)->callback();
}
