#include <oogl/io.hpp>

#include <fstream>
#include <sstream>


namespace oogl
{
    namespace io
    {
        inline bool oogl::io::ReadFile
        (
            const char* path, 
            std::string& contents
        )
        {
            std::ifstream file_stream(path);
            if (!file_stream.is_open()) { return false; }

            std::stringstream string_stream;
            string_stream << file_stream.rdbuf();

            contents = string_stream.str();

            return true;
        }
    }
}
