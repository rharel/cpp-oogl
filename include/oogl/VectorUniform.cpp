#include <oogl/VectorUniform.hpp>


namespace oogl
{
    template <typename T>
    inline void VectorUniform<T, 1, 1>::set
    (
        const T v0
    )
    {
        VectorUniformBase<T, 1, 1>::set(&v0);
    }
    template <typename T>
    inline void VectorUniform<T, 2, 1>::set
    (
        const T v0,
        const T v1
    )
    {
        const T data[2] {v0, v1};
        VectorUniformBase<T, 2, 1>::set(data);
    }
    template <typename T>
    inline void VectorUniform<T, 3, 1>::set
    (
        const T v0,
        const T v1,
        const T v2
    )
    {
        const T data[3] {v0, v1, v2};
        VectorUniformBase<T, 3, 1>::set(data);
    }
    template <typename T>
    inline void VectorUniform<T, 4, 1>::set
    (
        const T v0,
        const T v1,
        const T v2,
        const T v3
    )
    {
        const T data[4] {v0, v1, v2, v3};
        VectorUniformBase<T, 4, 1>::set(data);
    }
}
