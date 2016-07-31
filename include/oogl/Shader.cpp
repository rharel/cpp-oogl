#include <oogl/Shader.hpp>

#include <oogl/io.hpp>


namespace oogl
{
    inline Shader* Shader::BuildFromString
    (
        const Type type, 
        const char* source
    )
    {
        auto shader = new Shader(type);
        
        shader->SourceFromString(source);
        if (!shader->Compile())
        {
            shader->info_log_ = 
                "Compilation failure:\n" + shader->info_log_;
            return shader;
        }
        
        return shader;
    }
    inline Shader* Shader::BuildFromPath
    (
        const Type type,
        const char* path
    )
    {
        Shader* shader;

        std::string source;
        if (!io::ReadFile(path, source))
        {
            shader = BuildFromString(type, "");
            shader->info_log_ = "Could not read source file";
        }
        else 
        { 
            shader = BuildFromString(type, source.c_str()); 
        }

        return shader;
    }

    inline Shader::Shader(const Type type)
        : type_(type)
    {
        Initialize(glCreateShader(static_cast<GLenum>(type_)));
    }

    inline Shader::~Shader()
    {
        glDeleteShader(handle());
    }
    
    inline void Shader::Bind() {};

    inline void Shader::SourceFromString(const char* source)
    {
        source_ = source;
        
        const GLchar* files[1] { source_.c_str() };
        const GLint lengths[1] { static_cast<GLint>(source_.size()) };
        glShaderSource(handle(), 1, files, lengths);
    }
    inline bool Shader::SourceFromPath(const char* path)
    {
        std::string source;
        if (!io::ReadFile(path, source))
        {
            return false;
        }

        SourceFromString(source.c_str());
        return true;
    }

    inline bool Shader::Compile()
    {
        glCompileShader(handle());
        
        GLint status;
        glGetShaderiv(handle(), GL_COMPILE_STATUS, &status);
        is_compiled_ = status == GL_TRUE;

        GLint info_log_length;
        glGetShaderiv(handle(), GL_INFO_LOG_LENGTH, &info_log_length);

        GLsizei max_log_length = info_log_length;
        GLsizei actual_log_length;
        GLchar* info_log = new GLchar[info_log_length];
        glGetShaderInfoLog
        (
            handle(), 
            max_log_length, &actual_log_length, 
            info_log
        );
        info_log_ = std::string(info_log);
        delete[] info_log;

        return is_compiled_;
    }

    inline Shader::Type Shader::type() const
    {
        return type_; 
    }
    inline bool Shader::is_compiled() const
    { 
        return is_compiled_; 
    }
    inline const char* Shader::source() const
    { 
        return source_.c_str();
    }
    inline const char* Shader::info_log() const 
    { 
        return info_log_.c_str();
    }
}
