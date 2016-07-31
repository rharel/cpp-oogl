#include <oogl/Program.hpp>


namespace oogl
{
    inline Program* Program::Build
    (
        std::initializer_list<const Shader*> shaders
    )
    {
        Program* program = new Program();

        for (const Shader* shader : shaders)
        {
            program->AttachShader(*shader);
        }
        if (!program->Link())
        {
            program->info_log_ = 
                "Linking failure:\n" + program->info_log_;
            return program;
        }
        for (const Shader* shader : shaders)
        {
            program->DetachShader(*shader);
        }

        return program;
    }

    inline Program::Program()
    {
        Initialize(glCreateProgram());
    }

    inline Program::~Program()
    {
        glDeleteProgram(handle());
    }
    inline void Program::Bind()
    {
        Use();
    }

    inline void Program::AttachShader(const Shader& shader)
    {
        glAttachShader(handle(), shader.handle());
    }
    inline void Program::DetachShader(const Shader& shader)
    {
        glDetachShader(handle(), shader.handle());
    }

    inline bool Program::Link()
    {
        glLinkProgram(handle());

        GLint link_status;
        glGetProgramiv(handle(), GL_LINK_STATUS, &link_status);
        is_linked_ = link_status == GL_TRUE;

        GLint info_log_length;
        glGetProgramiv(handle(), GL_INFO_LOG_LENGTH, &info_log_length);

        GLsizei max_log_length = info_log_length;
        GLsizei actual_log_length;
        GLchar* info_log = new GLchar[info_log_length];
        glGetProgramInfoLog
        (
            handle(), 
            max_log_length, &actual_log_length,
            info_log
        );
        info_log_ = std::string(info_log);
        delete[] info_log;

        return is_linked_;
    }

    inline void Program::Use()
    {
        glUseProgram(handle());
    }

    inline GLint Program::GetUniformLocation(const char* name) const
    {
        return glGetUniformLocation(handle(), name);
    }
    template <typename T, unsigned int D, GLsizei N>
    inline VectorUniform<T, D, N> 
           Program::GetVectorUniform(const char* name) const
    {
        return VectorUniform<T, D, N>
        (
            *this,
            GetUniformLocation(name),
            name
        );
    }

    inline bool Program::is_linked() const
    { 
        return is_linked_; 
    }
    inline const char* Program::info_log() const
    { 
        return info_log_.c_str(); 
    }
}
