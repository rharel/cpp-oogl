#include <oogl/UniformBase.hpp>


namespace oogl
{
    template <typename T, GLsizei N>
    inline UniformBase<T, N>::UniformBase()
        : program_(nullptr), 
          name_("") {}
    template <typename T, GLsizei N>
    inline UniformBase<T, N>::UniformBase
    (
        const Program& program,
        const GLint location,
        const char* name
    )
        : program_(&program),
          location_(location),
          name_(name) {}

    template <typename T, GLsizei N>
    inline bool UniformBase<T, N>::is_valid() const
    {
        return location_ != -1;
    }

    template <typename T, GLsizei N>
    inline const Program& UniformBase<T, N>::program() const
    {
        return *program_;
    }
    template <typename T, GLsizei N>
    inline GLint UniformBase<T, N>::location() const
    {
        return location_;
    }
    template <typename T, GLsizei N>
    inline const char* UniformBase<T, N>::name() const
    {
        return name_.c_str();
    }
}
