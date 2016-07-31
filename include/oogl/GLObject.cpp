#include <oogl/GLObject.hpp>


namespace oogl
{
    inline GLObject::GLObject() {};
    inline GLObject::~GLObject() {}

    inline void GLObject::Initialize(const GLuint handle)
    {
        if (is_valid()) { return; }
        handle_ = handle;
    }

    inline void GLObject::BindToTarget(const GLenum target)
    {
        set_binding_target(target);
        Bind();
    }
    
    inline bool GLObject::is_valid() const
    { 
        return handle_ != 0; 
    }
    inline GLuint GLObject::handle() const 
    { 
        return handle_; 
    }

    inline GLenum GLObject::binding_target() const
    {
        return binding_target_;
    }
    inline void GLObject::set_binding_target(const GLenum target)
    {
        binding_target_ = target;
    }
}
