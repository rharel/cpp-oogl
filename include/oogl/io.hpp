/**
 * IO methods.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <string>


namespace oogl
{
    namespace io
    {
        bool ReadFile
        (
            const char* path, 
            std::string& contents
        );
    }
}

#include <oogl/io.cpp>
