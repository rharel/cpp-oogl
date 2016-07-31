/**
 * Program uniform base class.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <string>
#include <type_traits>

#include <glew/glew.h>


namespace oogl
{
    class Program;

    /**
     * Abstract base class for program object uniforms.
     *
     * @param T Data type.
     * @param D Data dimension.
     * @param N Array size.
     */
    template <typename T, GLsizei N>
    class UniformBase
    {
        static_assert(std::is_arithmetic<T>::value, "is arithmetic");
        
        public:
        UniformBase();
        UniformBase
        (
            const Program& program,
            GLint location,
            const char* name
        );

        virtual void set(const T* value) = 0;
        
        bool is_valid() const;

        const Program& program() const;
        GLint location() const;
        const char* name() const;

        private:
        const Program* program_;
        std::string name_;
        GLint location_;
    };
}

#include <oogl/UniformBase.cpp>
