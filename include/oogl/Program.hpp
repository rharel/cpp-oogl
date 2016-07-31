/**
 * Program Object.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <string>

#include <glew/glew.h>

#include <oogl/GLObject.hpp>
#include <oogl/Shader.hpp>
#include <oogl/VectorUniform.hpp>


namespace oogl
{
    /**
     * This class wraps around OpenGL program objects.
     * Programs are a pipeline of shaders that renders an image.
     */
    class Program : public GLObject
    {
        public:
        /**
         * Creates, compiles, and links a program from shader list.
         */
        static Program* Build
        (
            std::initializer_list<const Shader*> shaders
        );

        /**
         * Creates a new program.
         */
        Program();
        /**
         * Deletes program.
         */
        ~Program() override;

        /**
         * Alias for Use().
         */
        void Bind() override;

        /**
         * Attaches shader.
         */
        void AttachShader(const Shader& shader);
        /**
         * Detaches shader.
         */
        void DetachShader(const Shader& shader);

        /**
         * Links programs.
         *
         * @returns Value indicating whether operation was succesful.
         */
        bool Link();
        /**
         * Binds to context.
         */
        void Use();
        
        /**
         * Gets uniform location by name.
         */
        GLint GetUniformLocation(const char* name) const;
        /**
         * Gets uniform.
         */
        template <typename T, unsigned int D, GLsizei N = 1>
        VectorUniform<T, D, N> GetVectorUniform(const char* name) const;

        /**
         * Checks whether program is linked succesfully.
         */
        bool is_linked() const;
        /**
         * Gets info log.
         */
        const char* info_log() const;

        private:
        bool is_linked_ = false;
        std::string info_log_ = "";
    };
}

#include <oogl/Program.cpp>
