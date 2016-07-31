/**
 * Texture Object.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <glew/glew.h>

#include <oogl/GLObject.hpp>


namespace oogl
{
    /**
     * This class wraps around OpenGL texture objects.
     * Textures can be used as input to shaders or as render targets.
     *
     * @note Currently only catering to 1D and 2D textures.
     */
    class Texture : public GLObject
    {
        public:
        enum class Binding : GLenum
        {
            Texture1D = GL_TEXTURE_1D,
            Texture2D = GL_TEXTURE_2D,
            Texture3D = GL_TEXTURE_3D,
            Array1D = GL_TEXTURE_1D_ARRAY,
            Array2D = GL_TEXTURE_2D_ARRAY,
            Rectangle = GL_TEXTURE_RECTANGLE,
            CubeMap = GL_TEXTURE_CUBE_MAP,
            CubeMapArray = GL_TEXTURE_CUBE_MAP_ARRAY,
            TextureBuffer = GL_TEXTURE_BUFFER,
            Multisample2D = GL_TEXTURE_2D_MULTISAMPLE,
            MultisampleArray2D = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
        };
        enum class Filter : GLint
        {
            Nearest = GL_NEAREST,
            Linear = GL_LINEAR
        };
        enum class Wrapper : GLint
        {
            ClampToEdge = GL_CLAMP_TO_EDGE,
            ClampToBorder = GL_CLAMP_TO_BORDER,
            Repeat = GL_REPEAT,
            MirroredRepeat = GL_MIRRORED_REPEAT,
            MirrorClampToEdge = GL_MIRROR_CLAMP_TO_EDGE
        };

        /**
         * Gets texture unit by index.
         */
        static GLenum GetUnit(GLint index);

        /**
         * Creates a new 2D, RGB, 1x1 texture.
         */
        Texture();
        /**
         * Creates a new texture with given specifications.
         */
        Texture
        (
            Binding target,
            GLint internal_format,
            GLsizei width, GLsizei height
        );

        /**
         * Deletes texture.
         */
        ~Texture() override;

        /**
         * Binds to context.
         */
        void Bind() override;
        /**
         * Binds texture to given unit.
         */
        void BindToUnit(GLint index);
        /**
         * Binds to the context at given target.
         */
        void BindToTarget(Binding target);

        /**
         * Uploads pixel data to texture.
         */
        void UploadData
        (
            GLint level,
            GLenum format, GLenum type,
            const GLvoid* data
        );
        /**
         * Downloads pixel data from texture.
         */
        void DownloadData
        (
            GLint level,
            GLenum format, GLenum type,
            GLvoid* data
        ) const;
        /**
         * Copies pixel data from another texture.
         */
        void CopyData(const Texture& source);
        /**
         * Clears pixel data.
         */
        void ClearData
        (
            GLint level,
            GLenum format, GLenum type,
            const GLvoid* data
        );

        /**
         * Resizes texture and clears it to black.
         */
        void Resize(GLsizei width, GLsizei height);

        /**
         * Sets binding target.
         */
        void set_binding_target(Binding value);

        /**
         * Sets minifycation filter.
         */
        void set_minification_filter(Filter filter);
        /**
         * Sets magnification filter.
         */
        void set_magnification_filter(Filter filter);
        /**
         * Sets both minification and magnification filters.
         */
        void set_filters(Filter filter);

        /**
         * Sets wrapping policy around s-axis.
         */
        void set_s_wrapper(Wrapper wrapper);
        /**
         * Sets wrapping policy around t-axis.
         */
        void set_t_wrapper(Wrapper wrapper);
        /**
         * Sets global wrapping policy.
         */
        void set_wrappers(Wrapper wrapper);

        /**
         * Gets width in pixels.
         */
        GLint width() const;
        /**
         * Gets height in pixels.
         */
        GLint height() const;
        
        private:
        GLint internal_format_;
        GLsizei width_, height_;
    };
}

#include <oogl/Texture.cpp>
