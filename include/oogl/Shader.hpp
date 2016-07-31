/**
 * Shader Object.
 *
 * @author Raoul Harel
 * @url github/rharel/cpp-oogl
 */


#pragma once

#include <string>

#include <glew/glew.h>

#include <oogl/GLObject.hpp>


namespace oogl
{
    /**
     * This class is a wrapper around shader objects.
     * Shaders are stages of the programmable rendering pipeline. They are
     * attached to program objects which are then compiled and linked.
     */
    class Shader : public GLObject
    {
        public:
        enum class Type : GLenum
        {
            Vertex = GL_VERTEX_SHADER,
            TessallationControl = GL_TESS_CONTROL_SHADER,
            TessallationEvaluation = GL_TESS_EVALUATION_SHADER,
            Geometry = GL_GEOMETRY_SHADER,
            Fragment = GL_FRAGMENT_SHADER,
            Compute = GL_COMPUTE_SHADER
        };

        /**
         * Creates and compiles shader from string.
         */
        static Shader* BuildFromString(Type type, const char* source);
        /**
         * Creates and compiles shader from path.
         */
        static Shader* BuildFromPath(Type type, const char* path);

        /**
         * Creates a new shader with given type.
         */
        Shader(Type type);
        /**
         * Deletes shader.
         */
        ~Shader() override;

        /**
         * No-op.
         */
        void Bind() override;

        /**
         * Loads given source from string.
         */
        void SourceFromString(const char* source);
        /**
         * Loads given source from path.
         *
         * @returns Value indicating whether operation was succesful.
         */
        bool SourceFromPath(const char* path);

        /**
         * Compiles shader.
         *
         * @returns Value indicating whether operation was succesful.
         */
        bool Compile();

        /**
         * Gets shader type.
         */
        Type type() const;
        /**
         * Gets shader source string.
         */
        const char* source() const;
        /**
         * Checks whether shader is succesfully compiled.
         */
        bool is_compiled() const;
        /**
         * Gets info log.
         */
        const char* info_log() const;

        private:
        Type type_;
        std::string source_ = "";
        bool is_compiled_ = false;
        std::string info_log_ = "";
    };
}

#include <oogl/Shader.cpp>
