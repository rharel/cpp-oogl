#include <oogl/Texture.hpp>


namespace oogl
{
    inline GLenum Texture::GetUnit(const GLint index)
    {
        return GL_TEXTURE0 + index;
    }

    inline Texture::Texture()
        : Texture(Binding::Texture2D, GL_RGB, 1, 1) {}
    inline Texture::Texture
    (
        const Binding target,
        const GLint internal_format,
        const GLsizei width,
        const GLsizei height
    )
        : internal_format_(internal_format),
          width_(width), 
          height_(height)
    {
        GLuint handle;
        glGenTextures(1, &handle);
        Initialize(handle);
        set_binding_target(target);
    }

    inline Texture::~Texture()
    {
        const GLuint object = handle();
        glDeleteTextures(1, &object);
    }
    inline void Texture::Bind()
    {
        glBindTexture(binding_target(), handle());
    }
    inline void Texture::BindToUnit(const GLint index)
    {
        glActiveTexture(Texture::GetUnit(index));
        Bind();
    }
    inline void Texture::BindToTarget(const Binding target)
    {
        set_binding_target(target);
        Bind();
    }

    inline void Texture::UploadData
    (
        const GLint level,
        const GLenum format, 
        const GLenum type,
        const GLvoid* data
    )
    {
        if (binding_target() == 
            static_cast<GLenum>(Binding::Texture1D))
        {
            glTexImage1D
            (
                binding_target(),
                level,
                internal_format_,
                width_, 0,
                format, type,
                data
            );
        }
        else if (binding_target() == 
                 static_cast<GLenum>(Binding::Texture2D))
        {
            glTexImage2D
            (
                binding_target(),
                level,
                internal_format_,
                width_, height_, 0,
                format, type,
                data
            );
        }
    }
    inline void Texture::DownloadData
    (
        const GLint level,
        const GLenum format,
        const GLenum type,
        GLvoid* data
    ) const
    {
        glGetTexImage
        ( 	
            binding_target(),
  	        level,
  	        format,type,
  	        data
        );
    }
    inline void Texture::CopyData(const Texture& source)
    {
        Resize(source.width_, source.height_);
        glCopyImageSubData
        (
            source.handle(), 
            source.binding_target(),
            0,
            0, 0, 0,
            this->handle(),
            this->binding_target(),
            0,
            0, 0, 0,
            source.width_, source.height_, 1
        );
    }
    inline void Texture::ClearData
    (
        const GLint level,
        const GLenum format,
        const GLenum type,
        const GLvoid* data
    )
    {
        glClearTexImage(handle(), level, format, type, data);
    }

    inline void Texture::Resize
    (
        const GLsizei width,
        const GLsizei height
    )
    {
        width_ = width;
        height_ = height;
        
        Bind();
        UploadData(0, GL_RED, GL_FLOAT, nullptr);
    }

    inline void Texture::set_binding_target(const Binding value)
    {
        GLObject::set_binding_target(static_cast<GLenum>(value));
    }

    inline void Texture::set_minification_filter(const Filter filter)
    {
        glTexParameteri
        (
            binding_target(),
            GL_TEXTURE_MIN_FILTER,
            static_cast<GLint>(filter)
        );
    }
    inline void Texture::set_magnification_filter(const Filter filter)
    {
        glTexParameteri
        (
            binding_target(),
            GL_TEXTURE_MAG_FILTER,
            static_cast<GLint>(filter)
        );
    }
    inline void Texture::set_filters(const Filter filter)
    {
        set_minification_filter(filter);
        set_magnification_filter(filter);
    }

    inline void Texture::set_s_wrapper(const Wrapper wrapper)
    {
        glTexParameteri
        (
            binding_target(),
            GL_TEXTURE_WRAP_S,
            static_cast<GLint>(wrapper)
        );
    }
    inline void Texture::set_t_wrapper(const Wrapper wrapper)
    {
        glTexParameteri
        (
            binding_target(),
            GL_TEXTURE_WRAP_T,
            static_cast<GLint>(wrapper)
        );
    }
    inline void Texture::set_wrappers(const Wrapper wrapper)
    {
        set_s_wrapper(wrapper);
        set_t_wrapper(wrapper);
    }

    inline GLint Texture::width() const
    {
        return width_;
    }
    inline GLint Texture::height() const
    {
        return height_;
    }
}
