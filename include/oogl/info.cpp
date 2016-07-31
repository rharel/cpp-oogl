#include <oogl/info.hpp>

#include <glew/glew.h>


namespace oogl
{
    inline std::string version_string()
    {
        return std::string
        (
            reinterpret_cast<const char*>
            (
                glGetString(GL_VERSION)
            )
        );
    }
}
